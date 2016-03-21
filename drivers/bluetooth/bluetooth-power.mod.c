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
	{ 0xfdb121b7, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x58d5c57, __VMLINUX_SYMBOL_STR(platform_driver_register) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0x4cabed9, __VMLINUX_SYMBOL_STR(rfkill_register) },
	{ 0xaad6d92f, __VMLINUX_SYMBOL_STR(rfkill_init_sw_state) },
	{ 0x8329cb05, __VMLINUX_SYMBOL_STR(device_create_file) },
	{ 0x1e50276, __VMLINUX_SYMBOL_STR(rfkill_alloc) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x3757c9b, __VMLINUX_SYMBOL_STR(of_get_named_gpio_flags) },
	{ 0xe1227f80, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5d6c0c8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x89a3bdb0, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0x260cf8f8, __VMLINUX_SYMBOL_STR(of_get_property) },
	{ 0x3e3835fd, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xcab61768, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0xbec25473, __VMLINUX_SYMBOL_STR(of_parse_phandle) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xfe990052, __VMLINUX_SYMBOL_STR(gpio_free) },
	{ 0x1258d9d9, __VMLINUX_SYMBOL_STR(regulator_disable) },
	{ 0x432fd7f6, __VMLINUX_SYMBOL_STR(__gpio_set_value) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xa8f59416, __VMLINUX_SYMBOL_STR(gpio_direction_output) },
	{ 0x47229b5c, __VMLINUX_SYMBOL_STR(gpio_request) },
	{ 0xca16dbe7, __VMLINUX_SYMBOL_STR(regulator_enable) },
	{ 0x98cc564a, __VMLINUX_SYMBOL_STR(regulator_set_voltage) },
	{ 0x5a48534a, __VMLINUX_SYMBOL_STR(regulator_count_voltages) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x6e2cf2a, __VMLINUX_SYMBOL_STR(regulator_get) },
	{ 0xf087137d, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xd85ac634, __VMLINUX_SYMBOL_STR(regulator_put) },
	{ 0x535fffb7, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xdb68bbad, __VMLINUX_SYMBOL_STR(rfkill_destroy) },
	{ 0x83eb21c, __VMLINUX_SYMBOL_STR(rfkill_unregister) },
	{ 0xa46c8051, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0x2e350c9e, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D1C112783B7545591A4C645");
