cmd_arch/arm64/boot/dts/lge/../msm8992-pplus_tmo_us-rev-evb3.dtb := /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/scripts/gcc-wrapper.py /home/livlogik/android/ndk/android-ndk-r10e/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin/aarch64-linux-android-gcc -E -Wp,-MD,arch/arm64/boot/dts/lge/../.msm8992-pplus_tmo_us-rev-evb3.dtb.d.pre.tmp -nostdinc -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/boot/dts -I/home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/boot/dts/include -undef -D__DTS__ -x assembler-with-cpp -o arch/arm64/boot/dts/lge/../.msm8992-pplus_tmo_us-rev-evb3.dtb.dts.tmp arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-rev-evb3.dts ; /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/scripts/dtc/dtc -O dtb -o arch/arm64/boot/dts/lge/../msm8992-pplus_tmo_us-rev-evb3.dtb -b 0 -i arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/  -d arch/arm64/boot/dts/lge/../.msm8992-pplus_tmo_us-rev-evb3.dtb.d.dtc.tmp arch/arm64/boot/dts/lge/../.msm8992-pplus_tmo_us-rev-evb3.dtb.dts.tmp ; cat arch/arm64/boot/dts/lge/../.msm8992-pplus_tmo_us-rev-evb3.dtb.d.pre.tmp arch/arm64/boot/dts/lge/../.msm8992-pplus_tmo_us-rev-evb3.dtb.d.dtc.tmp > arch/arm64/boot/dts/lge/../.msm8992-pplus_tmo_us-rev-evb3.dtb.d

source_arch/arm64/boot/dts/lge/../msm8992-pplus_tmo_us-rev-evb3.dtb := arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-rev-evb3.dts

deps_arch/arm64/boot/dts/lge/../msm8992-pplus_tmo_us-rev-evb3.dtb := \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/skeleton64.dtsi \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/boot/dts/include/dt-bindings/clock/msm-clocks-8992.h \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm-gdsc.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8994-smp2p.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-mdss-pll.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-mdss.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-gpu.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-bus.dtsi \
    $(wildcard include/config/noc.h) \
  /home/livlogik/Git_Hub/Kernel--Evil_Yummy_Gumdrop/arch/arm64/boot/dts/include/dt-bindings/msm/msm-bus-ids.h \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-ion.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm-pm8994-rpm-regulator.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm-pm8994.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm-pmi8994.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-regulator.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-iommu.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm-iommu-v1.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-iommu-domains.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-smp2p.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-pm.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-coresight.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/msm8992-camera.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/dsi-panel-sim-video.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/dsi-panel-sim-dualmipi0-video.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/dsi-panel-sim-dualmipi1-video.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/dsi-panel-sim-cmd.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/dsi-panel-sim-dualmipi0-cmd.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/dsi-panel-sim-dualmipi1-cmd.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-pinctrl.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../msm8992-lge.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../msm8992-pplus.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-camera.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-connectivity.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-misc.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../pmi8994-haptic.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-panel.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi0-qhd-cmd.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi0-qhd-cmd-rev0.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi0-qhd-cmd-rev1.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi0-qhd-cmd-rev2.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi0-qhd-cmd-rev3.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi1-qhd-cmd.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi1-qhd-cmd-rev0.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi1-qhd-cmd-rev1.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi1-qhd-cmd-rev2.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../dsi-panel-lgd-lg4945-dualmipi1-qhd-cmd-rev3.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../msm8992-panel-backlight-lm3697.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-pm.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../LGE_BL51YF_LGC_3000mAh.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../LGE_BL51YF_Tocad_3000mAh.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../../qcom/batterydata-itech-3000mah.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-sound.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../msm8992-amp-ti-tas2552.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-hdmi.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-touch.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../msm8992-pplus-touch-sic-lg4945.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-nfc.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/msm8992-pplus_tmo_us-fingerprint.dtsi \
  arch/arm64/boot/dts/lge/msm8992-pplus_tmo_us/../msm8992-fingerprint-fpc1022.dtsi \

arch/arm64/boot/dts/lge/../msm8992-pplus_tmo_us-rev-evb3.dtb: $(deps_arch/arm64/boot/dts/lge/../msm8992-pplus_tmo_us-rev-evb3.dtb)

$(deps_arch/arm64/boot/dts/lge/../msm8992-pplus_tmo_us-rev-evb3.dtb):
