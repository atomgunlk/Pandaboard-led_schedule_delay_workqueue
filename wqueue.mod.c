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

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x771b4d74, "module_layout" },
	{ 0xfd6293c2, "boot_tvec_bases" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x42160169, "flush_workqueue" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0xd5f2172f, "del_timer_sync" },
	{ 0x88a193, "__alloc_workqueue_key" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x7d11c268, "jiffies" },
	{ 0x47c149ab, "queue_delayed_work" },
	{ 0x27e1a049, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2E748BB74353345847256BF");
