/* ================================================================== */
/*  FujiFlim OIS firmware */
/* ================================================================== */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/leds.h>
#include <linux/errno.h>
#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/hrtimer.h>
#include <linux/types.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <linux/file.h>
#include <soc/qcom/camera2.h>
#include <linux/poll.h>
#include "msm_sd.h"
#include "msm_ois.h"
#include "msm_ois_i2c.h"

#define LAST_UPDATE "14-12-26, 16M LGIT OIS bu24333GWL"

#define FIRMWARE_VER_BIN_1 "bu24233_dl_program_LGIT_IDG2021_LGITAct_rev16B_S_data1.bin"
#define FIRMWARE_VER_BIN_2 "bu24233_dl_program_LGIT_IDG2021_LGITAct_rev16B_S_data2.bin"
#define FIRMWARE_VER_CHECKSUM 0x0002CB58

#define E2P_FIRST_ADDR			(0x0900)
#define E2P_SECOND_ADDR			(0x091C)
#define E2P_DATA_BYTE_FIRST		(26)
#define E2P_DATA_BYTE_SECOND	(22)

#define CTL_END_ADDR_FOR_FIRST_E2P_DL	(0x1DC0)
#define CTL_END_ADDR_FOR_SECOND_E2P_DL	(0x1DDA)

#define OIS_START_DL_ADDR		(0xF010)
#define OIS_COMPLETE_DL_ADDR	(0xF006)
#define OIS_READ_STATUS_ADDR	(0x6024)
#define OIS_CHECK_SUM_ADDR		(0xF008)

#define LIMIT_STATUS_POLLING	(10)
#define LIMIT_OIS_ON_RETRY		(5)

#define GYRO_SCALE_FACTOR 262
#define HALL_SCALE_FACTOR 187
#define NUM_GYRO_SAMLPING (10)

static int16_t g_gyro_offset_value_x, g_gyro_offset_value_y;

static struct ois_i2c_bin_list LGIT_VER16_REL_BIN_DATA = {
	.files = 2,
	.entries = {
		{
			.filename = FIRMWARE_VER_BIN_1,
			.filesize = 0x08BC,
			.blocks = 1,
			.addrs = {
				{0x0000, 0x08BB, 0x0000},
			}
		},
		{
			.filename = FIRMWARE_VER_BIN_2,
			.filesize = 0x01C0,
			.blocks = 1,
			.addrs = {
				{0x0000, 0x01BF, 0x1C00},
			}
		},
	},
	.checksum = FIRMWARE_VER_CHECKSUM
};

static int lgit_imx234_rohm_ois_poll_ready(int limit)
{
	uint8_t ois_status;
	int read_byte = 0;

	RegReadA(OIS_READ_STATUS_ADDR, &ois_status); /* polling status ready */
	read_byte++;

	while ((ois_status != 0x01) && (read_byte < limit)) {
		RegReadA(OIS_READ_STATUS_ADDR, &ois_status); /* polling status ready */
		usleep(1000); /* wait 1ms */
		read_byte++;
	}

	return ois_status;
}

int lgit_imx234_rohm_ois_bin_download(struct ois_i2c_bin_list bin_list)
{
	int rc = 0;
	int cnt = 0;
	int32_t read_value_32t;

	CDBG("%s\n", __func__);

	/* check OIS ic is alive */
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING)) {
		printk("%s: no reply 1\n", __func__);
		rc = OIS_INIT_I2C_ERROR;
		goto END;
	}

	/* Send command ois start dl */
	rc = RegWriteA(OIS_START_DL_ADDR, 0x00);

	while (rc < 0 && cnt < LIMIT_STATUS_POLLING) {
		usleep(2000);
		rc = RegWriteA(OIS_START_DL_ADDR, 0x00);
		cnt++;
	}

	if (rc < 0) {
		printk("%s: no reply\n", __func__);
		rc = OIS_INIT_I2C_ERROR;
		goto END;
	}

	/* OIS program downloading */
	rc = ois_i2c_load_and_write_bin_list(bin_list);
	if (rc < 0)
		goto END;

	/* Check sum value!*/
	RamRead32A(OIS_CHECK_SUM_ADDR, &read_value_32t);
	if (read_value_32t != bin_list.checksum) {
		printk("%s: sum = 0x%x\n", __func__, read_value_32t);
		rc = OIS_INIT_CHECKSUM_ERROR;
		goto END;
	}

	rc = ois_i2c_load_and_write_e2prom_data(E2P_FIRST_ADDR, E2P_DATA_BYTE_FIRST, CTL_END_ADDR_FOR_FIRST_E2P_DL);
	if (rc < 0)
		goto END;

	rc = ois_i2c_load_and_write_e2prom_data(E2P_SECOND_ADDR, E2P_DATA_BYTE_SECOND, CTL_END_ADDR_FOR_SECOND_E2P_DL);
	if (rc < 0)
		goto END;

	/* Send command ois complete dl */
	RegWriteA(OIS_COMPLETE_DL_ADDR, 0x00);

	/* Read ois status */
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING)) {
		printk("%s: no reply 3\n", __func__);
		rc = OIS_INIT_TIMEOUT;
		goto END;
	}

	printk("%s, complete dl FINISHED!\n", __func__);

END:
	return rc;
}

int lgit_imx234_rohm_ois_init_cmd(int limit)
{
	int trial = 0;

	do {
		RegWriteA(0x6020, 0x01);
		trial++;
	} while (trial < limit && !lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING));

	if (trial == limit)
		return OIS_INIT_TIMEOUT;

	RegWriteA(0x6023, 0x02);
	RegWriteA(0x602C, 0x1B);
	RegWriteA(0x602D, 0x10);
	RegWriteA(0x6023, 0x00);	/* gyro on */

	RegWriteB(0x60EE, 0x200); /* AF init */
#if 1
	RegWriteA(0x60D6, 0x00); /* AF servo on */
#else
	RegWriteA(0x60D6, 0x01); /* AF servo on */
#endif

	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING))
		return OIS_INIT_TIMEOUT;

	return OIS_SUCCESS;
}

static struct msm_ois_func_tbl lgit2_ois_func_tbl;

int32_t lgit_imx234_rohm_ois_mode(struct msm_ois_ctrl_t *o_ctrl,
					   struct msm_ois_set_info_t *set_info)
{
	int cur_mode = lgit2_ois_func_tbl.ois_cur_mode;
	uint8_t mode = *(uint8_t *)set_info->setting;

	CDBG("%s Enter\n", __func__);

	if (cur_mode == mode)
		return OIS_SUCCESS;

	if (cur_mode != OIS_MODE_CENTERING_ONLY) {
		RegWriteA(0x6020, 0x01);
		if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING))
			return OIS_INIT_TIMEOUT;
	}

	switch (mode) {
	case OIS_MODE_PREVIEW_CAPTURE:
	case OIS_MODE_CAPTURE:
		CDBG("%s:%d, %d preview capture\n", __func__, mode, cur_mode);
		RegWriteA(0x6021, 0x03); /*  zero shutter mode 2 */
		RegWriteA(0x6020, 0x02);
		break;
	case OIS_MODE_VIDEO:
		CDBG("%s:%d, %d video\n", __func__, mode, cur_mode);
		RegWriteA(0x6021, 0x61);
		RegWriteA(0x6020, 0x02);
		break;
	case OIS_MODE_CENTERING_ONLY:
		CDBG("%s:%d, %d centering_only\n", __func__, mode, cur_mode);
		break;
	case OIS_MODE_CENTERING_OFF:
		CDBG("%s:%d, %d centering_off\n", __func__, mode, cur_mode);
		RegWriteA(0x6020, 0x00); /* lens centering off */
		if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING))
			return OIS_INIT_TIMEOUT;
		break;
	}

	lgit2_ois_func_tbl.ois_cur_mode = mode;
	CDBG("%s End\n", __func__);

	return OIS_SUCCESS;
}

int lgit_imx234_rohm_ois_calibration(int ver)
{
	int16_t gyro_offset_value_x, gyro_offset_value_y = 0;

	CDBG("%s: lgit_ois_calibration start\n", __func__);
	/* Gyro Zero Calibration Starts. */
	RegWriteA(0x6020, 0x01);/* update mode & servo on & ois off mode */
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING)) {
		CDBG("%s 0x6024 result fail 1 @01\n", __func__);
		return OIS_INIT_TIMEOUT;
	}
	/* Gyro On */
	RegWriteA(0x6023, 0x00);
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING)) {
		CDBG("%s 0x6024 result fail 3 @02\n", __func__);
		return OIS_INIT_TIMEOUT;
	}
	/* X */
	RegWriteA(0x6088, 0);
	/* usleep(50000); */
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING + 30)) {
		CDBG("%s 0x6024 result fail 3 @03\n", __func__);
		return OIS_INIT_TIMEOUT;
	}
	RegReadB(0x608A, &gyro_offset_value_x);
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING)) {
		CDBG("%s 0x6024 result fail 3 @04\n", __func__);
		return OIS_INIT_TIMEOUT;
	}
	/* Y */
	RegWriteA(0x6088, 1);
	/* usleep(50000); */
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING + 30)) {
		CDBG("%s 0x6024 result fail 3 @05\n", __func__);
		return OIS_INIT_TIMEOUT;
	}
	RegReadB(0x608A, &gyro_offset_value_y);
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING)) {
		CDBG("%s 0x6024 result fail 3 @06A\n", __func__);
		return OIS_INIT_TIMEOUT;
	}

	/* Cal. Dato to eeprom */
	ois_i2c_e2p_write(0x0908, (uint16_t)(0xFFFF & gyro_offset_value_x), 2);
	ois_i2c_e2p_write(0x090A, (uint16_t)(0xFFFF & gyro_offset_value_y), 2); /* gyro_offset_value_x -> gyro_offset_value_y�� ������.(������) */

	/* Cal. Data to OIS Driver */
	RegWriteA(0x609C, 0x00);
	RamWriteA(0x609D, gyro_offset_value_x); /* 16 */
	RegWriteA(0x609C, 0x01);
	RamWriteA(0x609D, gyro_offset_value_y); /* 16 */

	/* Gyro Zero Calibration Ends. */
	CDBG("%s gyro_offset_value_x %d gyro_offset_value_y %d\n", __func__, gyro_offset_value_x, gyro_offset_value_y);
	g_gyro_offset_value_x = gyro_offset_value_x;
	g_gyro_offset_value_y = gyro_offset_value_y;

	CDBG("%s: lgit_ois_calibration end\n", __func__);
	return OIS_SUCCESS;
}

int32_t lgit_imx234_init_set_rohm_ois(struct msm_ois_ctrl_t *o_ctrl,
						   struct msm_ois_set_info_t *set_info)
{
	int32_t rc = OIS_SUCCESS;
	uint16_t cal_ver = 0;
	uint16_t ver;

	CDBG("%s Enter\n", __func__);
	printk("%s, %s\n", __func__, LAST_UPDATE);

	if (copy_from_user(&ver, (void *)set_info->setting, sizeof(uint16_t))) {
		pr_err("%s:%d failed\n", __func__, __LINE__);
		rc = -EFAULT;
		return rc;
	}

	ois_i2c_e2p_read(E2P_FIRST_ADDR + 0x1C, &cal_ver, 2);
	printk("%s ver %x, init ver %d\n", __func__, cal_ver, ver);

	switch (cal_ver) {
	case 0xE:
	default:
		rc = lgit_imx234_rohm_ois_bin_download(LGIT_VER16_REL_BIN_DATA);
		break;
#if 0
	default:
		rc = OIS_INIT_NOT_SUPPORTED;
		break;
#endif
	}

	if (rc < 0)	{
		CDBG("%s: init fail\n", __func__);
		return rc;
	}

	switch (ver) {
	case OIS_VER_RELEASE:
		CDBG("%s OIS_VER_RELEASE\n", __func__);
		lgit_imx234_rohm_ois_init_cmd(LIMIT_OIS_ON_RETRY);
#if 0
		/* OIS ON */
		RegWriteA(0x6021, 0x12);/* view finder mode */
		RegWriteA(0x6020, 0x02);/* OIS ON */
		if (!lgit_imx234_rohm_ois_poll_ready(5))
			return OIS_INIT_TIMEOUT;
#endif

		break;
	case OIS_VER_CALIBRATION:
	case OIS_VER_DEBUG:
		CDBG("%s OIS_VER_DEBUG\n", __func__);
		lgit_imx234_rohm_ois_calibration(ver);

		/* OIS ON */
		RegWriteA(0x6021, 0x79);/* LGIT STILL & PAN ON MODE */
		RegWriteA(0x6020, 0x02);/* OIS ON */

		if (!lgit_imx234_rohm_ois_poll_ready(5))
			return OIS_INIT_TIMEOUT;
		break;
	}

	lgit2_ois_func_tbl.ois_cur_mode = OIS_MODE_CENTERING_ONLY;
	CDBG("%s End\n", __func__);
	return rc;

}
int32_t	lgit_imx234_rohm_ois_on(struct msm_ois_ctrl_t *o_ctrl,
					 struct msm_ois_set_info_t *set_info)
{
	int32_t rc = OIS_SUCCESS;
	CDBG("%s Enter\n", __func__);

	/* OIS ON */
	RegWriteA(0x6021, 0x03);/* LGIT STILL & PAN ON MODE */
	RegWriteA(0x6020, 0x02);/* OIS ON */

	if (!lgit_imx234_rohm_ois_poll_ready(5))
		return OIS_INIT_TIMEOUT;
	CDBG("%s End\n", __func__);
	return rc;
}

void lgit_imx234_rohm_write_vcm(int16_t nDAC)
{
	if (nDAC > 1024) nDAC = 1023;
	if (nDAC < 0) nDAC = 0;
	//W 0x60DA //0~1024//usint
	//      uint16_t data[2];
	//       data[1] = nDAC & 0xff;
	//       data[0] = nDAC >> 8;
	RegWriteB(0x60DA, nDAC);
}

EXPORT_SYMBOL(lgit_imx234_rohm_write_vcm);

int32_t	lgit_imx234_rohm_ois_off(struct msm_ois_ctrl_t *o_ctrl,
					  struct msm_ois_set_info_t *set_info)
{

	CDBG("%s Enter\n", __func__);

	RegWriteA(0x6020, 0x01);
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING))  {
		CDBG("%s poll time out\n", __func__);
		return OIS_INIT_TIMEOUT;
	}

	CDBG("%s End\n", __func__);
	return OIS_SUCCESS;
}

int32_t lgit_imx234_rohm_ois_stat(struct msm_ois_ctrl_t *o_ctrl,
					   struct msm_ois_set_info_t *set_info)
{
	struct msm_ois_info_t ois_stat;

	int16_t val_hall_x;
	int16_t val_hall_y;

	/* float gyro_scale_factor_idg2020 = (1.0)/(262.0); */
	int16_t val_gyro_x;
	int16_t val_gyro_y;
	/* Hall Fail Spec. */
	int16_t spec_hall_x_lower = 1467;/* +-0.65degȮ���ϱ� ���Ͽ� 45.0um �ʿ���.(���� Spec.�� +-0.5deg�̹Ƿ� ����� ���� ���Ե�) */
	int16_t spec_hall_x_upper = 2629;
	int16_t spec_hall_y_lower = 1467;
	int16_t spec_hall_y_upper = 2629;
	uint8_t *ptr_dest = NULL;

	memset(&ois_stat, 0, sizeof(ois_stat));
	snprintf(ois_stat.ois_provider, ARRAY_SIZE(ois_stat.ois_provider), "LGIT_ROHM");

	/* Gyro Read by reg */
	RegWriteA(0x609C, 0x02);
	RamReadA(0x609D, &val_gyro_x);
	RegWriteA(0x609C, 0x03);
	RamReadA(0x609D, &val_gyro_y);

	//set_info->ois_info.gyro[0] = (int16_t)val_gyro_x;
	//set_info->ois_info.gyro[1] = (int16_t)val_gyro_y;

	/* Hall Fail */
	/* Read Hall X */
	RegWriteA(0x6060, 0x00);
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING + 30)) {
		CDBG("%s 0x6024 result fail 3 @09\n", __func__);
		return OIS_INIT_TIMEOUT;
	}
	RegReadB(0x6062, &val_hall_x);

	/* Read Hall Y */
	RegWriteA(0x6060, 0x01);
	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING + 30)) {
		CDBG("%s 0x6024 result fail 3 @10\n", __func__);
		return OIS_INIT_TIMEOUT;
	}

	RegReadB(0x6062, &val_hall_y);

	ois_stat.gyro[0] = (int16_t)val_gyro_x;
	ois_stat.gyro[1] = (int16_t)val_gyro_y;
	ois_stat.hall[0] = (int16_t)val_hall_x;
	ois_stat.hall[1] = (int16_t)val_hall_y;
	ois_stat.is_stable = 1;

	ptr_dest = (uint8_t *)set_info->ois_info;
	if (copy_to_user(ptr_dest, &ois_stat, sizeof(ois_stat))) {
		CDBG("%s: failed copy_to_user result\n", __func__);
	}

#if 0
	CDBG("%s val_hall_x(%d) -> 0x%x g_gyro_offset_value_x (%d)\n", __func__,
		 val_hall_x, ois_stat->gyro[0], g_gyro_offset_value_x);
	CDBG("%s val_hall_y(%d) -> 0x%x g_gyro_offset_value_y (%d)\n", __func__,
		 val_hall_y, ois_stat->gyro[1], g_gyro_offset_value_y);
#endif

	if (abs(val_gyro_x) > (25 * 262) ||
		abs(val_gyro_y) > (25 * 262)) {
		CDBG("Gyro Offset X is FAIL!!! (%d)\n", val_gyro_x);
		CDBG("Gyro Offset Y is FAIL!!! (%d)\n", val_gyro_y);
		ois_stat.is_stable = 0;
	}

	/* Hall Spec. Out? */
	if (val_hall_x > spec_hall_x_upper || val_hall_x < spec_hall_x_lower) {
		CDBG("val_hall_x is FAIL!!! (%d) 0x%x\n", val_hall_x,
			 val_hall_x);
		ois_stat.is_stable = 0;
	}

	if (val_hall_y > spec_hall_y_upper || val_hall_y < spec_hall_y_lower) {
		CDBG("val_hall_y is FAIL!!! (%d) 0x%x\n", val_hall_y,
			 val_hall_y);
		ois_stat.is_stable = 0;
	}

	return 0;
}

int32_t lgit_imx234_rohm_ois_move_lens(struct msm_ois_ctrl_t *o_ctrl,
							struct msm_ois_set_info_t *set_info)
{

	int8_t hallx = 0;/* target_x / HALL_SCALE_FACTOR; */
	int8_t hally = 0;/* target_y / HALL_SCALE_FACTOR; */
	uint8_t result = 0;

	int32_t rc = OIS_SUCCESS;
	int16_t offset[2];
	if (copy_from_user(&offset[0], (void *)set_info->setting, sizeof(int16_t) * 2)) {
		pr_err("%s:%d failed\n", __func__, __LINE__);
		rc = -EFAULT;
		return rc;
	}
	hallx =  offset[0] / HALL_SCALE_FACTOR;
	hally =  offset[1] / HALL_SCALE_FACTOR;

	/* check ois mode & change to suitable mode */
	RegReadA(0x6020, &result);
	if (result != 0x01) {
		RegWriteA(0x6020, 0x01);
		if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING))
			return OIS_INIT_TIMEOUT;
	}

	printk("%s target : %d(0x%x), %d(0x%x)\n", __func__,
		   hallx, hallx, hally, hally);

	/* hallx range -> D2 to 2E (-46, 46) */
	RegWriteA(0x6099, 0xFF & hallx); /* target x position input */
	RegWriteA(0x609A, 0xFF & hally); /* target y position input */
	/* wait 100ms */
	usleep(100000);
	RegWriteA(0x6098, 0x01); /* order to move. */

	if (!lgit_imx234_rohm_ois_poll_ready(LIMIT_STATUS_POLLING * 12))
		return OIS_INIT_TIMEOUT;

	RegReadA(0x609B, &result);

	RegWriteA(0x6023, 0x00);/* Gyro On */
	RegWriteA(0x6021, 0x12);/* LGIT STILL & PAN ON MODE */
	RegWriteA(0x6020, 0x02);/* OIS ON */

	if (result == 0x03)
		return  OIS_SUCCESS;

	printk("%s move fail : 0x%x\n", __func__, result);
	return OIS_FAIL;
}

void lgit_imx234_rohm_ois_init(struct msm_ois_ctrl_t *msm_ois_t)
{
	lgit2_ois_func_tbl.ini_set_ois = lgit_imx234_init_set_rohm_ois;
	lgit2_ois_func_tbl.enable_ois = lgit_imx234_rohm_ois_on;
	lgit2_ois_func_tbl.disable_ois = lgit_imx234_rohm_ois_off;
	lgit2_ois_func_tbl.ois_mode = lgit_imx234_rohm_ois_mode;
	lgit2_ois_func_tbl.ois_stat = lgit_imx234_rohm_ois_stat;
	lgit2_ois_func_tbl.ois_move_lens = lgit_imx234_rohm_ois_move_lens;
	lgit2_ois_func_tbl.ois_cur_mode = OIS_MODE_CENTERING_ONLY;

	msm_ois_t->sid_ois = 0x7C >> 1;
	msm_ois_t->func_tbl = &lgit2_ois_func_tbl;
}
