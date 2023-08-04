# RISCV Hwacha YOLOV3 Sublayer optimization
## To configure
```
cd firesim-nvdla/sim
export DESIGN=FireSimNoNIC TARGET_CONFIG=FireSimRocketChipQuadCoreConfig_WithNVDLALarge \
PLATFORM_CONFIG=FireSimDDR3FRFCFSLLC4MBConfig75MHz
make run-verilator-debug SIM_BINARY=../target-design/firechip/tests/hwacha-layers.riscv -j
```