/* include/linux/touch_sic_abt.h
 *
 * Copyright (C) 2014 LGE.
 *
 * Author: esook.kang@lge.com
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef TOUCH_SIC_ABT_H
#define TOUCH_SIC_ABT_H

#if USE_ABT_MONITOR_APP

#include <linux/socket.h>
#include <linux/in.h>
/* for abt monitor app. header */
#define CMD_ABT_LOC_X_START			(tc_device_ctl_base + 0x674)
#define CMD_ABT_LOC_X_END			(tc_device_ctl_base + 0x675)
#define CMD_ABT_LOC_Y_START			(tc_device_ctl_base + 0x676)
#define CMD_ABT_LOC_Y_END			(tc_device_ctl_base + 0x677)
/* debug data report mode setting */
#define CMD_RAW_DATA_REPORT_MODE	(tc_device_ctl_base + 0x626)
#define CMD_RAW_DATA_COMPRESS		(tc_device_ctl_base + 0x627)

#define REPORT_RNORG				1
#define REPORT_RAW					2
#define REPORT_BASELINE				3
#define REPORT_SEG1					4
#define REPORT_SEG2					5
#define REPORT_GLASS				6
#define REPORT_DEBUG_ONLY			7
#define REPORT_OFF					20

#define ACTIVE_SCREEN_CNT_X		18
#define ACTIVE_SCREEN_CNT_Y		32

#define HEAD_LOAD			10

#define DEF_RNDCPY_EVERY_Nth_FRAME	(4)

#define DEFAULT_PORT 8095
#define SEND_PORT 8090
#define OMK_BUF 1000

#define MODULE_NAME "ABT_SOCKET"
/* must 4 multiple */
#define I2C_PACKET_SIZE 128

enum E_DATA_TYPE {
	DATA_TYPE_RAW = 0,
	DATA_TYPE_BASELINE,
	DATA_TYPE_RN_ORG = 10,
	DATA_TYPE_SEG1 = 20,
	DATA_TYPE_SEG2,
	DATA_TYPE_MAX
};

enum DEBUG_TYPE {
	DEBUG_DATA = 0,
	DEBUG_MODE = 1,
	DEBUG_DATA_RW_MODE = 2,
	DEBUG_DATA_CAPTURE_MODE = 3,
	DEBUG_DATA_CMD_MODE = 4
};

enum RW_TYPE {
	READ_TYPE = 55,
	WRITE_TYPE = 66
};

enum DEBUG_REPORT_CMD {
	DEBUG_REPORT_POINT = 0x100,
	DEBUG_REPORT_OCD,
};

enum ABT_CONNECT_TOOL {
	NOTHING = 0,
	ABT_STUDIO = 1,
	ABT_PCTOOL = 2
};

/* UDP */
#pragma pack(push, 1)
struct send_data_t {
	u8 type;
	u8 mode;
	u8 flag;
	u8 touchCnt;
	u32 timestamp;
	u32 frame_num;
	u8 data[3000];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct debug_report_header {
	u8 key_frame;
	u8 type;
	u16 data_size;
};
#pragma pack(pop)

/* TCP */
struct s_comm_packet {
	u8 cmd;
	u8 report_type;

	union {
		u8 rw;
		u8 data_type;
	} flag;

	u8 status;


	u16 addr;
	u16 data_size;

	u32 frame_num;

	u8  data[4];

	u32 crc;
};

struct sock_comm_t {
	struct i2c_client *client;

	struct task_struct *thread;
	struct socket *sock;
	struct sockaddr_in addr;

	/*TCP*/
	struct sockaddr_in client_addr;
	struct socket *client_sock;
	/*TCP*/


	uint32_t (*sock_listener)(uint8_t *buf, uint32_t len);
	struct socket *sock_send;
	struct sockaddr_in addr_send;
	struct send_data_t data_send;

	struct s_comm_packet *recv_packet;
	struct s_comm_packet send_packet;
	int send_connected;
	char send_ip[20];

	u8 running;
};

struct T_ABTLog_FileHead {
/* 4 byte => 4B */
	/* 2B : x축 해상도 */
	unsigned short	resolution_x;
	/* 2B : y축 해상도 */
	unsigned short	resolution_y;
/* 4 byte => 8B */
	/* 1B : real node 개수 (x축) */
	unsigned char	node_cnt_x;
	/* 1B : real node 개수 (y축) */
	unsigned char	node_cnt_y;
	/* 1B : additional node 개수 (touch button 등등으로 인해..) */
	unsigned char	additional_node_cnt;
	unsigned char	dummy1;
/* 4 byte => 12B */
	/* 2B : RN MIN value */
	unsigned short	rn_min;
	/* 2B : RN MAX value */
	unsigned short	rn_max;
/* 4 byte => 16B */
	/* 1B : RAW Size (1B or 2B) */
	unsigned char	raw_data_size;
	/* 1B : RN Size (1B or 2B) */
	unsigned char	rn_data_size;
	/* 1B : frame buf 에 쌓인 data 의 type -> E_DATA_TYPE number */
	unsigned char	frame_data_type;
	/* 1B : frame buf 에 쌓인 data 의 unit size (1B or 2B) */
	unsigned char	frame_data_size;
/* 4 byte => 20B */
	/* 4B : x_node start/end 의 location(screen resolution) */
	unsigned short	loc_x[2];
/* 4 byte => 24B */
	/* 4B : y_node start/end 의 location(screen resolution) */
	unsigned short	loc_y[2];
/* 104 byte => 128B */
	/* total 128B 중 나머지.. */
	unsigned char	dummy[104];
} __packed;

extern struct sock_comm_t abt_comm;
extern struct mutex abt_socket_lock;
extern struct mutex abt_i2c_comm_lock;
extern int abt_socket_mutex_flag;

extern u8 abt_report_point;
extern u8 abt_report_ocd;
extern u32 CMD_GET_ABT_DEBUG_REPORT;
extern u16 abt_ocd[2][ACTIVE_SCREEN_CNT_X*ACTIVE_SCREEN_CNT_Y];
extern u8 abt_ocd_read;
extern u8 abt_reportP[256];
extern char abt_head[128];
extern u32 abt_compress_flag;

extern int abt_show_mode;
extern int abt_ocd_on;
extern int abt_report_mode;

extern int32_t abt_ksocket_raw_data_send(uint8_t *buf, uint32_t len);
extern ssize_t show_abtApp(struct i2c_client *client, char *buf);
extern ssize_t store_abtApp(struct i2c_client *client,
					const char *buf, size_t count);
extern ssize_t show_abtTool(struct i2c_client *client, char *buf);
extern ssize_t store_abtTool(struct i2c_client *client,
					const char *buf, size_t count);
extern int abt_force_set_report_mode(struct i2c_client *client, u32 mode);

#endif

#endif

