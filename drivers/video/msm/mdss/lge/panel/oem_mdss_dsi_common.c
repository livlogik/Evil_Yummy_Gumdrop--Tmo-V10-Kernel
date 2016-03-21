/* Copyright (c) 2012-2015, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/spinlock.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <linux/err.h>
#include <linux/regulator/consumer.h>
#include <linux/clk.h>

#define INIT_FUNC(x, y) ((x->y) = y)
#include "mdss_debug.h"
#include "oem_mdss_dsi_common.h"
#include "oem_mdss_dsi.h"
#include <linux/input/lge_touch_notify.h>
#include <linux/mfd/p1_dsv.h>

static struct panel_list supp_panels[] = {
	{"LGD INCELL 1440p Dual 0 cmd mode dsi panel", LGD_R69007_QHD_DUALDSI_CMD_PANEL},
	{"LGD INCELL 1440p Dual 1 cmd mode dsi panel", LGD_R69007_QHD_DUALDSI_CMD_PANEL},
	{"JDI INCELL 1440p Dual 0 cmd mode dsi panel", JDI_NT36850_QHD_DUALDSI_CMD_PANEL},
	{"JDI INCELL 1440p Dual 1 cmd mode dsi panel", JDI_NT36850_QHD_DUALDSI_CMD_PANEL},
	{"LGD SIC INCELL 1440p Dual 0 cmd mode dsi panel", LGD_LG4943_QHD_DUALDSI_CMD_PANEL},
	{"LGD SIC INCELL 1440p Dual 1 cmd mode dsi panel", LGD_LG4943_QHD_DUALDSI_CMD_PANEL},
	{"LGD SIC LG4945 INCELL 1440p Dual 0 cmd mode dsi panel", LGD_LG4945_QHD_DUALDSI_CMD_PANEL},
	{"LGD SIC LG4945 INCELL 1440p Dual 1 cmd mode dsi panel", LGD_LG4945_QHD_DUALDSI_CMD_PANEL},
};

static int panel_id;

struct lge_mdss_dsi_interface panel_init_fnc = {
	pre_msm_dss_enable_vreg,
	post_msm_dss_enable_vreg,
	pre_mdss_dsi_panel_reset,
	post_mdss_dsi_panel_reset,
	pre_mdss_dsi_panel_power_ctrl,
	post_mdss_dsi_panel_power_ctrl,
	post_mdss_dsi_blank,
	post_mdss_dsi_panel_on,
	post_mdss_dsi_panel_off,
	lge_mdss_dsi_event_handler,
	lge_msm_dss_enable_vreg,
	lge_mdss_dsi_request_gpios,
	lge_mdss_dsi_panel_reset,
	lge_mdss_dsi_lane_config,
	lge_mdss_dsi_ctrl_probe,
	lge_dsi_panel_device_register,
	lge_mdss_panel_parse_dt,
	lge_panel_device_create,
	lge_mdss_dsi_cmdlist_commit,
	lge_mdss_dsi_panel_init,
	lge_dump_mdss_reg,
	lge_mdss_xlog_tout_handler_default,
	lge_mdss_create_xlog_debug,
	lge_mdss_dsi_panel_bl_ctrl
};

int panel_name_to_id(struct panel_list supp_panels[],
			  uint32_t supp_panels_size,
			  const char *panel_name)
{
	int i;
	int panel_id = UNKNOWN_PANEL;

	if (!panel_name) {
		pr_err("Invalid panel name\n");
		return panel_id;
	}

	/* Remove any leading whitespaces */
	panel_name += strspn(panel_name, " ");
	for (i = 0; i < supp_panels_size; i++) {
		if (!strncmp(panel_name, supp_panels[i].name,
			MAX_PANEL_ID_LEN)) {
			panel_id = supp_panels[i].id;
			break;
		}
	}

	return panel_id;
}

int pre_msm_dss_enable_vreg(struct mdss_panel_data *pdata, int enable)
{
	return 0;
}

int post_msm_dss_enable_vreg(struct mdss_panel_data *pdata, int enable)
{
	return 0;
}

int pre_mdss_dsi_panel_reset(struct mdss_panel_data *pdata, int enable)
{
	return 0;
}

int post_mdss_dsi_panel_reset(struct mdss_panel_data *pdata, int enable)
{
	return 0;
}

int pre_mdss_dsi_panel_power_ctrl(struct mdss_panel_data *pdata, int enable)
{
	int rc = 0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_pre_mdss_dsi_panel_power_ctrl(pdata, enable);
		break;
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	     rc = jdi_qhd_command_pre_mdss_dsi_panel_power_ctrl(pdata, enable);
		break;
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_sic_qhd_command_pre_mdss_dsi_panel_power_ctrl(pdata, enable);
		break;
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_lg4945_qhd_command_pre_mdss_dsi_panel_power_ctrl(pdata, enable);
		break;
	}
	return 0;
}

int post_mdss_dsi_panel_power_ctrl(struct mdss_panel_data *pdata, int enable)
{
	int rc = 0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_post_mdss_dsi_panel_power_ctrl(pdata,enable);
		break;
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		break;
	}
	return 0;
}

int post_mdss_dsi_blank(struct mdss_panel_data *pdata, int power_state)
{
	int rc = 0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_post_mdss_dsi_blank(pdata,power_state);
		break;
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		break;
	}

	return 0;
}

int post_mdss_dsi_panel_on(struct mdss_panel_data *pdata)
{
	int rc = 0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_post_mdss_dsi_panel_on(pdata);
		break;
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		break;
	}

	return 0;
}

int post_mdss_dsi_panel_off(struct mdss_panel_data *pdata)
{
	int rc = 0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
		break;
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_post_mdss_dsi_panel_off(pdata);
		break;
	}

	return 0;
}

#if IS_ENABLED(CONFIG_LGE_DISPLAY_SUPPORT_MFTS)
bool lge_mdss_dsi_always_on_power_ctrl_check(struct mdss_dsi_ctrl_pdata *ctrl_pdata)
{
	if (ctrl_pdata == NULL) {
		pr_err("%s: Invalid input ctrl_pdata\n", __func__);
			return false;
	}

	if(ctrl_pdata->lge_pan_data->mfts_mode) {
		if(ctrl_pdata->lge_pan_data->auto_touh_test_mode) {
			return false;
		}
		return true;
	}

	return false;
}

int msm_dss_enable_vreg_sic(struct dss_vreg *in_vreg, int num_vreg, int enable, char *ldo_name)
{
	int i = 0, rc = 0;
	if (enable) {
		for (i = 0; i < num_vreg; i++) {
			if(!strcmp(in_vreg[i].vreg_name, ldo_name))
				pr_err("lge_log %s: now %s off\n", __func__, ldo_name);
			else
				continue;

			rc = PTR_RET(in_vreg[i].vreg);
			if (rc) {
				DEV_ERR("%pS->%s: %s regulator error. rc=%d\n",
					__builtin_return_address(0), __func__,
					in_vreg[i].vreg_name, rc);
				goto vreg_set_opt_mode_fail;
			}
			if (in_vreg[i].pre_on_sleep)
				msleep(in_vreg[i].pre_on_sleep);
			rc = regulator_set_optimum_mode(in_vreg[i].vreg,
				in_vreg[i].enable_load);
			if (rc < 0) {
				DEV_ERR("%pS->%s: %s set opt m fail\n",
					__builtin_return_address(0), __func__,
					in_vreg[i].vreg_name);
				goto vreg_set_opt_mode_fail;
			}
			rc = regulator_enable(in_vreg[i].vreg);
			if (in_vreg[i].post_on_sleep)
				msleep(in_vreg[i].post_on_sleep);
			if (rc < 0) {
				DEV_ERR("%pS->%s: %s enable failed\n",
					__builtin_return_address(0), __func__,
					in_vreg[i].vreg_name);
				goto disable_vreg;
			}
		}
	} else {
		for (i = num_vreg-1; i >= 0; i--) {
		pr_err("lge_log %s: now %s enter\n", __func__, ldo_name);
				if(!strcmp(in_vreg[i].vreg_name, ldo_name))
					pr_err("lge_log %s: now %s off\n", __func__, ldo_name);
				else
				 continue;

				if (regulator_is_enabled(in_vreg[i].vreg)) {
					if (in_vreg[i].pre_off_sleep)
						msleep(in_vreg[i].pre_off_sleep);
					regulator_set_optimum_mode(in_vreg[i].vreg,
						in_vreg[i].disable_load);
					regulator_disable(in_vreg[i].vreg);
					if (in_vreg[i].post_off_sleep)
						msleep(in_vreg[i].post_off_sleep);
				}
			}
	}
	return rc;

disable_vreg:
	regulator_set_optimum_mode(in_vreg[i].vreg, in_vreg[i].disable_load);

vreg_set_opt_mode_fail:
	for (i--; i >= 0; i--) {
		if (in_vreg[i].pre_off_sleep)
			msleep(in_vreg[i].pre_off_sleep);
		regulator_set_optimum_mode(in_vreg[i].vreg,
			in_vreg[i].disable_load);
		regulator_disable(in_vreg[i].vreg);
		if (in_vreg[i].post_off_sleep)
			msleep(in_vreg[i].post_off_sleep);
	}

	return rc;
} /* msm_dss_enable_vreg */

int lge_mdss_dsi_blank_pre(struct mdss_panel_data *pdata)
{
	int ret = 0;
	struct mdss_dsi_ctrl_pdata *ctrl_pdata = NULL;

	if (pdata == NULL) {
		pr_err("%s: Invalid input data\n", __func__);
		return -EINVAL;
	}

	ctrl_pdata = container_of(pdata, struct mdss_dsi_ctrl_pdata,
				panel_data);
	if (ctrl_pdata->ndx) {
		if (ctrl_pdata->panel_data.panel_info.lge_pan_info.panel_type
			== LGD_LG4945_INCELL_CMD_PANEL && ctrl_pdata->lge_pan_data->touch_driver_registered) {
			touch_notifier_call_chain(LCD_EVENT_TOUCH_PWR_OFF,
						NULL);
		}

		pr_info("%s : LCD_EVENT_TOUCH_PWR_OFF sent \n", __func__);
	}
	return ret;
}

#define DW_SET_ENM_R 0
#define DW_HIZ_KNOCK_ON 1
#define DW_HIZ_KNOCK_ON_ENM_R 2
int lge_mdss_dsi_panel_power_ctrl_pre(struct mdss_panel_data *pdata, int enable)
{
	int ret = 0;
	struct mdss_dsi_ctrl_pdata *ctrl_pdata = NULL;

	if (pdata == NULL) {
		pr_err("%s: Invalid input data\n", __func__);
		return -EINVAL;
	}

	ctrl_pdata = container_of(pdata, struct mdss_dsi_ctrl_pdata,
				panel_data);

	if(enable) {
		if (ctrl_pdata->panel_data.panel_info.lge_pan_info.panel_type
			== LGD_LG4945_INCELL_CMD_PANEL) {
			pr_err("lge_log %s: called\n", __func__);
			mdss_dsi_ena_ctrl(pdata, enable);
			mdelay(5);
			dsv_i2c_configure(DW_HIZ_KNOCK_ON);
			mdelay(5);
			mdss_dsi_vddio_ctrl(pdata, enable);
			mdelay(5);
			ret = msm_dss_enable_vreg_sic(
					ctrl_pdata->power_data[DSI_PANEL_PM].vreg_config,
					ctrl_pdata->power_data[DSI_PANEL_PM].num_vreg, 1, "vpnl_touch");
			return ret;
		}
	} else {
		if (ctrl_pdata->panel_data.panel_info.lge_pan_info.panel_type
			== LGD_LG4945_INCELL_CMD_PANEL) {
			mdelay(5);
			ret = msm_dss_enable_vreg_sic(
			ctrl_pdata->power_data[DSI_PANEL_PM].vreg_config,
			ctrl_pdata->power_data[DSI_PANEL_PM].num_vreg, 0, "vpnl_touch");
		}
	}

	return ret;
}

int lge_mdss_dsi_panel_power_ctrl_post(struct mdss_panel_data *pdata, int enable)
{
	int ret = 0;
	struct mdss_dsi_ctrl_pdata *ctrl_pdata = NULL;

	if (pdata == NULL) {
		pr_err("%s: Invalid input data\n", __func__);
		return -EINVAL;
	}

	ctrl_pdata = container_of(pdata, struct mdss_dsi_ctrl_pdata,
				panel_data);

	if(enable) {
		if (ctrl_pdata->panel_data.panel_info.lge_pan_info.panel_type
			== LGD_LG4945_INCELL_CMD_PANEL) {
			dsv_i2c_configure(DW_HIZ_KNOCK_ON_ENM_R);
			mdss_dsi_lcd_reset(pdata, enable);
		}
	} else {
		if (ctrl_pdata->panel_data.panel_info.lge_pan_info.panel_type
			== LGD_LG4945_INCELL_CMD_PANEL) {

			pr_err("lge_log %s: called\n", __func__);

			mdelay(5);
			dw8768_mode_change(0);
			mdelay(5);
			mdss_dsi_lcd_reset(pdata, enable);
			mdelay(5);
			mdss_dsi_ena_ctrl(pdata, enable);
			mdelay(5);
			mdss_dsi_vddio_ctrl(pdata, enable);
		}
	}

	return ret;
}
#endif

int lge_mdss_dsi_event_handler(struct mdss_panel_data *pdata, int event, void *arg)
{
	int rc = 0;

	struct mdss_dsi_ctrl_pdata *ctrl_pdata = NULL;
	ctrl_pdata = container_of(pdata, struct mdss_dsi_ctrl_pdata, panel_data);
#if IS_ENABLED(CONFIG_LGE_DISPLAY_SUPPORT_MFTS)
	if(event == MDSS_EVENT_BLANK) {
		ctrl_pdata->lge_pan_data->always_on_power_ctrl = lge_mdss_dsi_always_on_power_ctrl_check(ctrl_pdata);
		pr_info("%s : Always-on-power ctrl [%d]\n", __func__, ctrl_pdata->lge_pan_data->always_on_power_ctrl);

		if(ctrl_pdata->lge_pan_data->always_on_power_ctrl)
			lge_mdss_dsi_blank_pre(pdata);
	}
#endif

	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_mdss_dsi_event_handler(pdata,event,arg);
		break;
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
		rc = jdi_qhd_command_mdss_dsi_event_handler(pdata,event,arg);
		break;
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_sic_qhd_command_mdss_dsi_event_handler(pdata,event,arg);
		break;
	}
	return 0;
}


int lge_msm_dss_enable_vreg(struct mdss_dsi_ctrl_pdata *ctrl_pdata, int enable)
{
	int rc = 0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_msm_dss_enable_vreg(ctrl_pdata, enable);
		break;
	}

	return 0;
}

int lge_mdss_dsi_request_gpios(struct mdss_dsi_ctrl_pdata *ctrl_pdata)
{
	int rc = 0;

	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_mdss_dsi_request_gpios(ctrl_pdata);
		break;

	default:
		break;
	}

	return rc;
}

int lge_mdss_dsi_panel_reset(struct mdss_panel_data *pdata, int enable)
{
	int rc = 0;
#if IS_ENABLED(CONFIG_LGE_DISPLAY_EXTENDED_PANEL)
	struct mdss_panel_info *pinfo;
#endif

	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_mdss_dsi_panel_reset(pdata, enable);
		break;
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
		rc = jdi_qhd_command_mdss_dsi_panel_reset(pdata, enable);
		break;
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
#if IS_ENABLED(CONFIG_LGE_DISPLAY_EXTENDED_PANEL)
		pinfo = &pdata->panel_info;
		if ((pinfo->lge_pan_info.lge_panel_send_off_cmd==false) || (pinfo->lge_pan_info.lge_panel_send_on_cmd==false))
			break;
#endif
		rc = lgd_sic_qhd_command_mdss_dsi_panel_reset(pdata, enable);
		break;
	default:
		break;
	}

	return rc;
}

int lge_mdss_dsi_lane_config(struct mdss_panel_data *pdata, int enable)
{
	return 0;
}

int lge_mdss_dsi_ctrl_probe(struct platform_device *pdev)
{
	int rc = 0;

	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_mdss_dsi_ctrl_probe(pdev);
		break;
	}

	return rc;
}

int lge_dsi_panel_device_register(struct device_node *pan_node, struct mdss_dsi_ctrl_pdata *ctrl_pdata)
{
	int rc = 0;

	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_dsi_panel_device_register(pan_node, ctrl_pdata);
		break;

	default:
		break;
	}

	return rc;

}

int lge_mdss_panel_parse_dt(struct device_node *pan_node, struct mdss_dsi_ctrl_pdata *ctrl_pdata)
{
	int rc = 0;

	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_mdss_panel_parse_dt(pan_node, ctrl_pdata);
		break;

	}
	return rc;
}

int lge_panel_device_create(struct device_node *pan_node, struct mdss_dsi_ctrl_pdata *ctrl_pdata)
{
	return 0;
}

int lge_mdss_dsi_cmdlist_commit(struct mdss_dsi_ctrl_pdata *ctrl, int from_mdp)
{
	int rc = 0;

	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
			rc = lgd_qhd_command_mdss_dsi_cmdlist_commit(ctrl, from_mdp);
			break;
	}
	return rc;
}

int lge_mdss_dsi_panel_init(struct device_node *node, struct mdss_dsi_ctrl_pdata *ctrl_pdata, bool cmd_cfg_cont_splash)
{
	int rc =0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
			rc = lgd_qhd_command_mdss_dsi_panel_init(node,ctrl_pdata,cmd_cfg_cont_splash);
			break;
	}


	return rc;
}
int lge_dump_mdss_reg(void)
{
	int rc =0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
			rc = lgd_qhd_command_dump_mdss_reg();
			break;
	}
	return rc;
}

int lge_mdss_xlog_tout_handler_default(void)
{
	int rc =0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
			rc = lgd_qhd_command_mdss_xlog_tout_handler_default();
			break;
	}
	return rc;
}

int lge_mdss_create_xlog_debug(struct mdss_debug_data *mdd)
{
	int rc =0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
			rc = lgd_qhd_command_mdss_create_xlog_debug(mdd);
			break;
	}
	return rc;
}

int lge_mdss_dsi_panel_bl_ctrl(struct mdss_panel_data *pdata, u32 bl_level)
{
	int rc =0;
	switch (panel_id) {
	case LGD_R69007_QHD_DUALDSI_CMD_PANEL:
	case JDI_NT36850_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4943_QHD_DUALDSI_CMD_PANEL:
	case LGD_LG4945_QHD_DUALDSI_CMD_PANEL:
		rc = lgd_qhd_command_mdss_dsi_panel_bl_ctrl(pdata, bl_level);
		break;
	}
	return rc;
}


int get_lge_panel_id(void)
{
	return panel_id;
}
void lge_mdss_dsi_seperate_panel_api_init(struct lge_mdss_dsi_interface *pdata, struct device_node *dsi_pan_node)
{
	static const char *panel_name;
	u32 *panel_power_sequence;
	int rc, i, num, fnum;
	struct property *data;

	panel_name = of_get_property(dsi_pan_node, "qcom,mdss-dsi-panel-name", NULL);

	panel_id = panel_name_to_id(supp_panels,
			ARRAY_SIZE(supp_panels), panel_name);

	data = of_find_property(dsi_pan_node, "lge,panel_power_sequence", &num);

	if (!data || !num) {
		pr_err("%s:%d, error reading lge,panel_power_sequence, length found = %d\n",
			__func__, __LINE__, num);
	} else {
		num /= sizeof(u32);
		fnum = sizeof(struct lge_mdss_dsi_interface)/sizeof(int *);
		if (num > fnum) {
			pr_err("%s: dtsi#:%d, header#:%d\n", __func__, num, fnum);
			num = fnum;
		}

		panel_power_sequence = kzalloc(sizeof(u32) * num, GFP_KERNEL);
		if (!panel_power_sequence) {
			pr_err("%s: Not enough memory\n", __func__);
			return;
		}

		rc = of_property_read_u32_array(dsi_pan_node, "lge,panel_power_sequence", panel_power_sequence, num);

		if (rc) {
			pr_err("%s: unable to read panel_power_sequence\n", __func__);
			kfree(panel_power_sequence);
			return;
		}

		for (i = 0; i < num; i++) {
			if (panel_power_sequence[i])
				memcpy(&pdata->pre_msm_dss_enable_vreg+i, &panel_init_fnc.pre_msm_dss_enable_vreg+i,
								sizeof(int *));
		}
		kfree(panel_power_sequence);

	}
}
