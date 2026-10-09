SIM ?= icarus
TOPLEVEL_LANG = verilog

SIM_BUILD := ../../sim/load_store_decoder/build
COCOTB_RESULTS_FILE := ../../sim/load_store_decoder/results.xml

VERILOG_SOURCES = \
    ../../package/cpu_package.sv \
    ../../rtl/load_store_decoder.sv

TOPLEVEL = load_store_decoder
MODULE = test_load_store_decoder

include $(shell cocotb-config --makefiles)/Makefile.sim