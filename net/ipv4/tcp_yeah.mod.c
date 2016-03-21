#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xa58455e2, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xcc9a353, __VMLINUX_SYMBOL_STR(tcp_vegas_get_info) },
	{ 0xcd8d7cf1, __VMLINUX_SYMBOL_STR(tcp_vegas_cwnd_event) },
	{ 0x12527940, __VMLINUX_SYMBOL_STR(tcp_vegas_state) },
	{ 0xd9a07453, __VMLINUX_SYMBOL_STR(tcp_reno_min_cwnd) },
	{ 0x459f8477, __VMLINUX_SYMBOL_STR(tcp_unregister_congestion_control) },
	{ 0xc5d67ef, __VMLINUX_SYMBOL_STR(tcp_register_congestion_control) },
	{ 0x741f42d4, __VMLINUX_SYMBOL_STR(tcp_cong_avoid_ai) },
	{ 0xfb200eda, __VMLINUX_SYMBOL_STR(tcp_slow_start) },
	{ 0xb3694c96, __VMLINUX_SYMBOL_STR(tcp_is_cwnd_limited) },
	{ 0x4a9a20b0, __VMLINUX_SYMBOL_STR(tcp_vegas_init) },
	{ 0xdf45b5b6, __VMLINUX_SYMBOL_STR(tcp_vegas_pkts_acked) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

