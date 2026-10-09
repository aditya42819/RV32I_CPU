SIM ?= icarus
TOPLEVEL_LANG ?= verilog

TOPLEVEL := cpu_harness
MODULE := test_cpu

COCOTB_RESULTS_FILE := ../../sim/cpu/results.xml
SIM_BUILD := ../../sim/cpu/build

VERILOG_SOURCES := \
    ../../package/cpu_package.sv \
    ../../rtl/alu.sv \
    ../../rtl/control.sv \
    ../../rtl/load_store_decoder.sv \
    ../../rtl/memory.sv \
    ../../rtl/program_counter.sv \
    ../../rtl/reader.sv \
    ../../rtl/regfile.sv \
    ../../rtl/signext.sv \
    ../../rtl/cpu.sv \
    cpu_harness.sv

include $(shell cocotb-config --makefiles)/Makefile.sim