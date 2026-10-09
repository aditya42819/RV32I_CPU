SIM ?= icarus
TOPLEVEL_LANG = verilog

SIM_BUILD := ../../sim/reader/build
COCOTB_RESULTS_FILE := ../../sim/reader/results.xml

VERILOG_SOURCES = \
    ../../package/cpu_package.sv \
    ../../rtl/reader.sv

TOPLEVEL = reader
MODULE = test_reader

include $(shell cocotb-config --makefiles)/Makefile.sim