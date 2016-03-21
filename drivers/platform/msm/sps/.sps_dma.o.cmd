cmd_drivers/platform/msm/sps/sps_dma.o := /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/scripts/gcc-wrapper.py /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/aarch64-linux-android-gcc -Wp,-MD,drivers/platform/msm/sps/.sps_dma.o.d  -nostdinc -isystem /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/../lib/gcc/aarch64-linux-android/4.9/include -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include -Iarch/arm64/include/generated  -Iinclude -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi -Iinclude/generated/uapi -include /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -Wno-maybe-uninitialized -mgeneral-regs-only -Wframe-larger-than=2048 -fno-stack-protector -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(sps_dma)"  -D"KBUILD_MODNAME=KBUILD_STR(sps_dma)" -c -o drivers/platform/msm/sps/.tmp_sps_dma.o drivers/platform/msm/sps/sps_dma.c

source_drivers/platform/msm/sps/sps_dma.o := drivers/platform/msm/sps/sps_dma.c

deps_drivers/platform/msm/sps/sps_dma.o := \
    $(wildcard include/config/sps/support/bamdma.h) \
    $(wildcard include/config/sps/support/ndp/bam.h) \

drivers/platform/msm/sps/sps_dma.o: $(deps_drivers/platform/msm/sps/sps_dma.o)

$(deps_drivers/platform/msm/sps/sps_dma.o):
