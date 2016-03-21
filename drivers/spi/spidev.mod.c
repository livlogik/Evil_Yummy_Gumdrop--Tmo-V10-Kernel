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
	{ 0x6d044c26, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x15692c87, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x10776789, __VMLINUX_SYMBOL_STR(no_llseek) },
	{ 0x7231afe4, __VMLINUX_SYMBOL_STR(device_unregister) },
	{ 0x6bc3fbc0, __VMLINUX_SYMBOL_STR(__unregister_chrdev) },
	{ 0xa73ae09d, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xe2d80bfa, __VMLINUX_SYMBOL_STR(driver_unregister) },
	{ 0x61e2ec82, __VMLINUX_SYMBOL_STR(spi_new_device) },
	{ 0x91c6fe7b, __VMLINUX_SYMBOL_STR(spi_busnum_to_master) },
	{ 0x830fb747, __VMLINUX_SYMBOL_STR(spi_register_driver) },
	{ 0x816e341d, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x54210876, __VMLINUX_SYMBOL_STR(__register_chrdev) },
	{ 0x34c44606, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0xf10bbb4c, __VMLINUX_SYMBOL_STR(spi_setup) },
	{ 0xafd32368, __VMLINUX_SYMBOL_STR(get_device) },
	{ 0xbdbc13a1, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x67c2fa54, __VMLINUX_SYMBOL_STR(__copy_to_user) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xfbc74f64, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0xf9dde891, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x5abc34a4, __VMLINUX_SYMBOL_STR(spi_async) },
	{ 0xf087137d, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0x500a0257, __VMLINUX_SYMBOL_STR(nonseekable_open) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xae8c4d0c, __VMLINUX_SYMBOL_STR(set_bit) },
	{ 0x2e350c9e, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0x871f61b0, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x479c3c86, __VMLINUX_SYMBOL_STR(find_next_zero_bit) },
	{ 0xe369ba0c, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0xe1227f80, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5d6c0c8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x85c06c67, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xa87cf413, __VMLINUX_SYMBOL_STR(clear_bit) },
	{ 0x1f331cf9, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xa697a81b, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x8fa8f791, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irq) },
	{ 0x535fffb7, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0x20ffa7f6, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0xa46c8051, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Crohm,dh2228fv*");
