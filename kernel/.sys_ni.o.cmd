cmd_kernel/sys_ni.o := /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/scripts/gcc-wrapper.py /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/aarch64-linux-android-gcc -Wp,-MD,kernel/.sys_ni.o.d  -nostdinc -isystem /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/../lib/gcc/aarch64-linux-android/4.9/include -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include -Iarch/arm64/include/generated  -Iinclude -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi -Iinclude/generated/uapi -include /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -Wno-maybe-uninitialized -mgeneral-regs-only -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(sys_ni)"  -D"KBUILD_MODNAME=KBUILD_STR(sys_ni)" -c -o kernel/.tmp_sys_ni.o kernel/sys_ni.c

source_kernel/sys_ni.o := kernel/sys_ni.c

deps_kernel/sys_ni.o := \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/asm/linkage.h \
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  arch/arm64/include/generated/asm/errno.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/asm-generic/errno.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/asm-generic/errno-base.h \
    $(wildcard include/config/mach/lge.h) \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/asm/unistd.h \
    $(wildcard include/config/compat.h) \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi/asm/unistd.h \
  include/asm-generic/unistd.h \
  include/uapi/asm-generic/unistd.h \
    $(wildcard include/config/mmu.h) \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  include/uapi/asm-generic/bitsperlong.h \

kernel/sys_ni.o: $(deps_kernel/sys_ni.o)

$(deps_kernel/sys_ni.o):
