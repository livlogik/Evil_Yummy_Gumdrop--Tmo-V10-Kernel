cmd_lib/string.o := /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/scripts/gcc-wrapper.py /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/aarch64-linux-android-gcc -Wp,-MD,lib/.string.o.d  -nostdinc -isystem /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/../lib/gcc/aarch64-linux-android/4.9/include -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include -Iarch/arm64/include/generated  -Iinclude -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi -Iinclude/generated/uapi -include /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -Wno-maybe-uninitialized -mgeneral-regs-only -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(string)"  -D"KBUILD_MODNAME=KBUILD_STR(string)" -c -o lib/.tmp_string.o lib/string.c

source_lib/string.o := lib/string.c

deps_lib/string.o := \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  include/uapi/linux/types.h \
  arch/arm64/include/generated/asm/types.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/uapi/asm-generic/bitsperlong.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
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
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi/asm/posix_types.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/asm-generic/posix_types.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/lib/gcc/aarch64-linux-android/4.9/include/stdarg.h \
  include/uapi/linux/string.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/asm/string.h \
  include/linux/ctype.h \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  include/linux/linkage.h \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/asm/linkage.h \
  include/linux/bitops.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/asm/bitops.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/asm/barrier.h \
    $(wildcard include/config/smp.h) \
  include/asm-generic/bitops/builtin-__ffs.h \
  include/asm-generic/bitops/builtin-ffs.h \
  include/asm-generic/bitops/builtin-__fls.h \
  include/asm-generic/bitops/builtin-fls.h \
  include/asm-generic/bitops/ffz.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/le.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/uapi/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  include/uapi/linux/swab.h \
  arch/arm64/include/generated/asm/swab.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/asm-generic/swab.h \
  include/linux/byteorder/generic.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/typecheck.h \
  include/linux/printk.h \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
    $(wildcard include/config/oops/log/buffer.h) \
  include/linux/init.h \
    $(wildcard include/config/broken/rodata.h) \
  include/linux/kern_levels.h \
  include/linux/dynamic_debug.h \
  include/uapi/linux/kernel.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/linux/sysinfo.h \
  include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/panic/on/data/corruption.h) \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  arch/arm64/include/generated/asm/errno.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/asm-generic/errno.h \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi/asm-generic/errno-base.h \
    $(wildcard include/config/mach/lge.h) \

lib/string.o: $(deps_lib/string.o)

$(deps_lib/string.o):
