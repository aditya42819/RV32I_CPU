SIM ?= icarus
TOPLEVEL_LANG ?= verilog

VERILOG_SOURCES += ../../package/cpu_package.sv
VERILOG_SOURCES += ../../rtl/alu.sv

TOPLEVEL = alu
MODULE = test_alu

SIM_BUILD := ../../sim/alu/build
COCOTB_RESULTS_FILE := ../../sim/alu/results.xml

include $(shell cocotb-config --makefiles)/Makefile.sim