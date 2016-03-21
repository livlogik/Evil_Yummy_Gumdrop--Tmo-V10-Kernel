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
	{ 0xc89dd62f, __VMLINUX_SYMBOL_STR(noop_llseek) },
	{ 0x862ed075, __VMLINUX_SYMBOL_STR(misc_deregister) },
	{ 0xa7837a77, __VMLINUX_SYMBOL_STR(misc_register) },
	{ 0xbbccdff9, __VMLINUX_SYMBOL_STR(msm_rpm_free_request) },
	{ 0xcd9436d6, __VMLINUX_SYMBOL_STR(msm_rpm_wait_for_ack) },
	{ 0xd60cf4cf, __VMLINUX_SYMBOL_STR(msm_rpm_send_request) },
	{ 0x47cfdaeb, __VMLINUX_SYMBOL_STR(msm_rpm_add_kvp_data) },
	{ 0x980434a2, __VMLINUX_SYMBOL_STR(msm_rpm_create_request) },
	{ 0xdcb764ad, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x67c2fa54, __VMLINUX_SYMBOL_STR(__copy_to_user) },
	{ 0xfbc74f64, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0xad214ab2, __VMLINUX_SYMBOL_STR(dma_alloc_from_coherent) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xdfaf505b, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0xe1227f80, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa5d6c0c8, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xb0d20f61, __VMLINUX_SYMBOL_STR(dma_release_from_coherent) },
	{ 0x73f8ae2c, __VMLINUX_SYMBOL_STR(dma_ops) },
	{ 0xf087137d, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "16E920A156C589B232D16DD");
