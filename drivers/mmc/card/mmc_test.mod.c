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
	{ 0x2f9dfa79, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0xdbb4267b, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x6d758a51, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x71c5d5fb, __VMLINUX_SYMBOL_STR(mmc_unregister_driver) },
	{ 0x1c85ecc7, __VMLINUX_SYMBOL_STR(mmc_register_driver) },
	{ 0x42edd599, __VMLINUX_SYMBOL_STR(__alloc_pages_nodemask) },
	{ 0x97e58500, __VMLINUX_SYMBOL_STR(contig_page_data) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x27fa66e1, __VMLINUX_SYMBOL_STR(nr_free_buffer_pages) },
	{ 0x31e66220, __VMLINUX_SYMBOL_STR(mmc_can_trim) },
	{ 0x7fe38f48, __VMLINUX_SYMBOL_STR(sg_copy_to_buffer) },
	{ 0x1bdc26cf, __VMLINUX_SYMBOL_STR(sg_copy_from_buffer) },
	{ 0xb6244511, __VMLINUX_SYMBOL_STR(sg_init_one) },
	{ 0x3b2fe37a, __VMLINUX_SYMBOL_STR(mmc_set_blocklen) },
	{ 0x46608fa0, __VMLINUX_SYMBOL_STR(getnstimeofday) },
	{ 0x3fec048f, __VMLINUX_SYMBOL_STR(sg_next) },
	{ 0xf8e398fc, __VMLINUX_SYMBOL_STR(memstart_addr) },
	{ 0xc897c382, __VMLINUX_SYMBOL_STR(sg_init_table) },
	{ 0xc3ea7261, __VMLINUX_SYMBOL_STR(mmc_wait_for_req) },
	{ 0xf332d8f9, __VMLINUX_SYMBOL_STR(mmc_wait_for_cmd) },
	{ 0xa05a7983, __VMLINUX_SYMBOL_STR(mmc_start_req) },
	{ 0xe48534ec, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0x3d5fc100, __VMLINUX_SYMBOL_STR(mmc_set_data_timeout) },
	{ 0x8c6bbc22, __VMLINUX_SYMBOL_STR(mmc_erase) },
	{ 0x3af7e999, __VMLINUX_SYMBOL_STR(mmc_can_erase) },
	{ 0xe6da44a, __VMLINUX_SYMBOL_STR(set_normalized_timespec) },
	{ 0x14c031bd, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x3e3835fd, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xc7b78ba8, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0xc4b33531, __VMLINUX_SYMBOL_STR(mmc_rpm_release) },
	{ 0x76e0e685, __VMLINUX_SYMBOL_STR(mmc_release_host) },
	{ 0xe1227f80, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5d6c0c8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x2a35e33a, __VMLINUX_SYMBOL_STR(__mmc_claim_host) },
	{ 0x1097f692, __VMLINUX_SYMBOL_STR(mmc_rpm_hold) },
	{ 0xa202a8e5, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0x1b17e06c, __VMLINUX_SYMBOL_STR(kstrtoll) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xfbc74f64, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xeb6136d0, __VMLINUX_SYMBOL_STR(mmc_can_reset) },
	{ 0x4ac67ee9, __VMLINUX_SYMBOL_STR(mmc_hw_reset_check) },
	{ 0x9b2a7476, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x2af785a7, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xf1bd8323, __VMLINUX_SYMBOL_STR(debugfs_remove) },
	{ 0x85c06c67, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xa697a81b, __VMLINUX_SYMBOL_STR(mutex_lock) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

