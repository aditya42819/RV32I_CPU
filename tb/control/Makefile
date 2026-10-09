SIM ?= icarus
TOPLEVEL_LANG = verilog

SIM_BUILD := ../../sim/control/build
COCOTB_RESULTS_FILE := ../../sim/control/results.xml

VERILOG_SOURCES = \
    ../../package/cpu_package.sv \
    ../../rtl/control.sv

TOPLEVEL = control
MODULE = test_control

include $(shell cocotb-config --makefiles)/Makefile.sim