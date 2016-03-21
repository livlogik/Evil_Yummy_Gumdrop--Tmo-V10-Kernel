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
	{ 0xa5d6c0c8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xed0adb95, __VMLINUX_SYMBOL_STR(v4l2_event_unsubscribe) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0x1a54296c, __VMLINUX_SYMBOL_STR(video_device_release_empty) },
	{ 0x15692c87, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x67c2fa54, __VMLINUX_SYMBOL_STR(__copy_to_user) },
	{ 0x535fffb7, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0xfe86ff6c, __VMLINUX_SYMBOL_STR(v4l2_device_unregister) },
	{ 0xab628181, __VMLINUX_SYMBOL_STR(v4l2_ctrl_handler_free) },
	{ 0x2288f136, __VMLINUX_SYMBOL_STR(v4l2_ctrl_g_ctrl) },
	{ 0xc87c1f84, __VMLINUX_SYMBOL_STR(ktime_get) },
	{ 0xfe033e97, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0xef4f8e25, __VMLINUX_SYMBOL_STR(__video_register_device) },
	{ 0x85c06c67, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x9b45797c, __VMLINUX_SYMBOL_STR(v4l2_device_register) },
	{ 0xab40cca9, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xf9c0b663, __VMLINUX_SYMBOL_STR(strlcat) },
	{ 0xcab0abec, __VMLINUX_SYMBOL_STR(v4l2_device_disconnect) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x6a50c637, __VMLINUX_SYMBOL_STR(v4l2_ctrl_s_ctrl) },
	{ 0xd5c3986e, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0xe369ba0c, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x3ee2875f, __VMLINUX_SYMBOL_STR(video_unregister_device) },
	{ 0xdffdffbc, __VMLINUX_SYMBOL_STR(usb_set_interface) },
	{ 0xa7033f0f, __VMLINUX_SYMBOL_STR(v4l2_ctrl_subscribe_event) },
	{ 0x5792f848, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xa697a81b, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xff787721, __VMLINUX_SYMBOL_STR(v4l2_fh_release) },
	{ 0xbe08e026, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x967823c9, __VMLINUX_SYMBOL_STR(vm_insert_page) },
	{ 0xe2968248, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0x127b2b03, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0x905b1115, __VMLINUX_SYMBOL_STR(video_devdata) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0xc033d025, __VMLINUX_SYMBOL_STR(input_register_device) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0xa76355fc, __VMLINUX_SYMBOL_STR(v4l2_ctrl_handler_setup) },
	{ 0xadfcc789, __VMLINUX_SYMBOL_STR(usb_clear_halt) },
	{ 0xa65fe88e, __VMLINUX_SYMBOL_STR(input_free_device) },
	{ 0xa0b04675, __VMLINUX_SYMBOL_STR(vmalloc_32) },
	{ 0xe1227f80, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xca769294, __VMLINUX_SYMBOL_STR(v4l2_fh_open) },
	{ 0x65345022, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4829a47e, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xd5bd6760, __VMLINUX_SYMBOL_STR(input_unregister_device) },
	{ 0x1bca2a90, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0xae8c4d0c, __VMLINUX_SYMBOL_STR(set_bit) },
	{ 0x9c5bc552, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0xe787fa78, __VMLINUX_SYMBOL_STR(usb_ifnum_to_if) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xa7adc3f8, __VMLINUX_SYMBOL_STR(vmalloc_to_page) },
	{ 0x75e5a334, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0x3ae375dd, __VMLINUX_SYMBOL_STR(v4l2_device_put) },
	{ 0xa46c8051, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0xf2c5dad7, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x9a44f853, __VMLINUX_SYMBOL_STR(video_ioctl2) },
	{ 0xe2a11ecd, __VMLINUX_SYMBOL_STR(v4l2_ctrl_poll) },
	{ 0xd954b7e5, __VMLINUX_SYMBOL_STR(try_module_get) },
	{ 0x7a8d0239, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0x4cdb3178, __VMLINUX_SYMBOL_STR(ns_to_timeval) },
	{ 0xa26857de, __VMLINUX_SYMBOL_STR(input_allocate_device) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "4DFDEDC74050A350E879D49");
