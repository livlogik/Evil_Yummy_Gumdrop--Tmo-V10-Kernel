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
	{ 0xf158f338, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0xa5d6c0c8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x9a908b80, __VMLINUX_SYMBOL_STR(test_and_clear_bit) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xf33847d3, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0xd705b4c7, __VMLINUX_SYMBOL_STR(schedule_hrtimeout) },
	{ 0xa0fbac79, __VMLINUX_SYMBOL_STR(wake_up_bit) },
	{ 0xf5f54c7c, __VMLINUX_SYMBOL_STR(bmap) },
	{ 0x64999478, __VMLINUX_SYMBOL_STR(congestion_wait) },
	{ 0xfa13c034, __VMLINUX_SYMBOL_STR(end_buffer_write_sync) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0xd8c7fbc0, __VMLINUX_SYMBOL_STR(blkdev_issue_flush) },
	{ 0x7ab88a45, __VMLINUX_SYMBOL_STR(system_freezing_cnt) },
	{ 0x36ddcc86, __VMLINUX_SYMBOL_STR(__lock_page) },
	{ 0x8f1dbb2, __VMLINUX_SYMBOL_STR(ll_rw_block) },
	{ 0x545b6a6e, __VMLINUX_SYMBOL_STR(__lock_buffer) },
	{ 0xc87c1f84, __VMLINUX_SYMBOL_STR(ktime_get) },
	{ 0x24fdac79, __VMLINUX_SYMBOL_STR(wake_bit_function) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x9621849f, __VMLINUX_SYMBOL_STR(ring_buffer_event_data) },
	{ 0x85c06c67, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xa87cf413, __VMLINUX_SYMBOL_STR(clear_bit) },
	{ 0xe957e030, __VMLINUX_SYMBOL_STR(filter_current_check_discard) },
	{ 0x99a8ea36, __VMLINUX_SYMBOL_STR(unlock_buffer) },
	{ 0xeb273e20, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xba8cd15, __VMLINUX_SYMBOL_STR(set_bh_page) },
	{ 0xab40cca9, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xd5f2172f, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0xbabb60a8, __VMLINUX_SYMBOL_STR(trace_event_buffer_lock_reserve) },
	{ 0x4775e0ee, __VMLINUX_SYMBOL_STR(trace_define_field) },
	{ 0xd3259d65, __VMLINUX_SYMBOL_STR(test_and_set_bit) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xc07e4f89, __VMLINUX_SYMBOL_STR(freezing_slow_path) },
	{ 0xe369ba0c, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xf8e398fc, __VMLINUX_SYMBOL_STR(memstart_addr) },
	{ 0xac765f9d, __VMLINUX_SYMBOL_STR(__sync_dirty_buffer) },
	{ 0x7dd46fcf, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xa697a81b, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x6ad90cbb, __VMLINUX_SYMBOL_STR(__wait_on_buffer) },
	{ 0xac313d44, __VMLINUX_SYMBOL_STR(sync_dirty_buffer) },
	{ 0xbe2c0274, __VMLINUX_SYMBOL_STR(add_timer) },
	{ 0x43b0c9c3, __VMLINUX_SYMBOL_STR(preempt_schedule) },
	{ 0x17ca4f88, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0xade04b49, __VMLINUX_SYMBOL_STR(__get_page_tail) },
	{ 0xfc04e902, __VMLINUX_SYMBOL_STR(__brelse) },
	{ 0x2de1327b, __VMLINUX_SYMBOL_STR(bit_waitqueue) },
	{ 0xee238982, __VMLINUX_SYMBOL_STR(ftrace_event_reg) },
	{ 0x360f8f8a, __VMLINUX_SYMBOL_STR(__cond_resched_lock) },
	{ 0x13b715e2, __VMLINUX_SYMBOL_STR(blk_finish_plug) },
	{ 0x514f0ff, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x3a586b71, __VMLINUX_SYMBOL_STR(free_buffer_head) },
	{ 0x8954140b, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0xf4b726de, __VMLINUX_SYMBOL_STR(sync_blockdev) },
	{ 0x993ce1a7, __VMLINUX_SYMBOL_STR(try_to_free_buffers) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x5239ce3b, __VMLINUX_SYMBOL_STR(___ratelimit) },
	{ 0x4482cdb, __VMLINUX_SYMBOL_STR(__refrigerator) },
	{ 0x50fad434, __VMLINUX_SYMBOL_STR(round_jiffies_up) },
	{ 0x7f24de73, __VMLINUX_SYMBOL_STR(jiffies_to_usecs) },
	{ 0x8edd7249, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x7a7b4e80, __VMLINUX_SYMBOL_STR(alloc_buffer_head) },
	{ 0x4429570a, __VMLINUX_SYMBOL_STR(submit_bh) },
	{ 0xe1227f80, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x5cd885d5, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xd173a8a9, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0x65345022, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x1e047854, __VMLINUX_SYMBOL_STR(warn_slowpath_fmt) },
	{ 0xca0200f3, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x9839f033, __VMLINUX_SYMBOL_STR(trace_event_raw_init) },
	{ 0x1bca2a90, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x9e61bb05, __VMLINUX_SYMBOL_STR(set_freezable) },
	{ 0xae8c4d0c, __VMLINUX_SYMBOL_STR(set_bit) },
	{ 0xc4e445a2, __VMLINUX_SYMBOL_STR(_submit_bh) },
	{ 0x60b4160, __VMLINUX_SYMBOL_STR(write_dirty_buffer) },
	{ 0xcd112ca, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0xc6cd053d, __VMLINUX_SYMBOL_STR(__bforget) },
	{ 0x9c5bc552, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x13b16b7, __VMLINUX_SYMBOL_STR(__find_get_block) },
	{ 0xf7eaa198, __VMLINUX_SYMBOL_STR(mark_buffer_dirty) },
	{ 0x1e3a88fb, __VMLINUX_SYMBOL_STR(trace_seq_printf) },
	{ 0x92c3ffa2, __VMLINUX_SYMBOL_STR(__getblk) },
	{ 0x65d67a20, __VMLINUX_SYMBOL_STR(blk_start_plug) },
	{ 0x1f2b74e0, __VMLINUX_SYMBOL_STR(ftrace_raw_output_prep) },
	{ 0x498d293a, __VMLINUX_SYMBOL_STR(trace_buffer_unlock_commit) },
	{ 0x760a0f4f, __VMLINUX_SYMBOL_STR(yield) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

