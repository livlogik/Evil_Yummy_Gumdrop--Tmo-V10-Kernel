cmd_kernel/configs.ko := /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/aarch64-linux-android-ld -EL -r  -T /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/scripts/module-common.lds --build-id   --fix-cortex-a53-843419 -o kernel/configs.ko kernel/configs.o kernel/configs.mod.o
