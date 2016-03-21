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
	{ 0xb59b1ea5, __VMLINUX_SYMBOL_STR(test_iosched_unregister) },
	{ 0xe3777068, __VMLINUX_SYMBOL_STR(test_iosched_register) },
	{ 0x1b7d43a, __VMLINUX_SYMBOL_STR(mmc_blk_get_packed_statistics) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xf4d73e61, __VMLINUX_SYMBOL_STR(mmc_blk_init_bkops_statistics) },
	{ 0x6377c279, __VMLINUX_SYMBOL_STR(test_iosched_add_unique_test_req) },
	{ 0xc7b78ba8, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x6a9fae0e, __VMLINUX_SYMBOL_STR(debugfs_create_u32) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xab40cca9, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xe1227f80, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5d6c0c8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xf1bd8323, __VMLINUX_SYMBOL_STR(debugfs_remove) },
	{ 0xd48ca0d, __VMLINUX_SYMBOL_STR(test_iosched_create_test_req) },
	{ 0x57d7060f, __VMLINUX_SYMBOL_STR(check_test_completion) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x3e179d3c, __VMLINUX_SYMBOL_STR(test_iosched_free_test_req_data_buffer) },
	{ 0x48ba2939, __VMLINUX_SYMBOL_STR(__blk_put_request) },
	{ 0x8fa8f791, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irq) },
	{ 0x20ffa7f6, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0x4cdb3178, __VMLINUX_SYMBOL_STR(ns_to_timeval) },
	{ 0x65345022, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x3c3cc850, __VMLINUX_SYMBOL_STR(test_iosched_mark_test_completion) },
	{ 0x9c5bc552, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x1bca2a90, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0xa916b694, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xda88bade, __VMLINUX_SYMBOL_STR(test_iosched_set_test_result) },
	{ 0x3a6efc10, __VMLINUX_SYMBOL_STR(__blk_run_queue) },
	{ 0x1af7ebc5, __VMLINUX_SYMBOL_STR(test_iosched_add_wr_rd_test_req) },
	{ 0xcbb02f7a, __VMLINUX_SYMBOL_STR(mmc_blk_init_packed_statistics) },
	{ 0x591d386b, __VMLINUX_SYMBOL_STR(test_iosched_set_ignore_round) },
	{ 0x7e29cbda, __VMLINUX_SYMBOL_STR(test_iosched_start_test) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0xf33847d3, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x5cd885d5, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=test-iosched";

