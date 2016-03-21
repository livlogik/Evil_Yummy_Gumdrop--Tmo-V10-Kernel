cmd_firmware/sic/pplus/pplus_limit.txt.gen.o := /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/scripts/gcc-wrapper.py /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/aarch64-linux-android-gcc -Wp,-MD,firmware/sic/pplus/.pplus_limit.txt.gen.o.d  -nostdinc -isystem /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/../lib/gcc/aarch64-linux-android/4.9/include -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include -Iarch/arm64/include/generated  -Iinclude -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/uapi -Iinclude/generated/uapi -include /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian  -D__ASSEMBLY__ -gdwarf-2         -c -o firmware/sic/pplus/pplus_limit.txt.gen.o firmware/sic/pplus/pplus_limit.txt.gen.S

source_firmware/sic/pplus/pplus_limit.txt.gen.o := firmware/sic/pplus/pplus_limit.txt.gen.S

deps_firmware/sic/pplus/pplus_limit.txt.gen.o := \

firmware/sic/pplus/pplus_limit.txt.gen.o: $(deps_firmware/sic/pplus/pplus_limit.txt.gen.o)

$(deps_firmware/sic/pplus/pplus_limit.txt.gen.o):
