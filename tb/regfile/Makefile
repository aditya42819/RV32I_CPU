SIM ?= icarus
TOPLEVEL_LANG ?= verilog

# RTL source being tested
VERILOG_SOURCES += ../../rtl/regfile.sv

# Cocotb test configuration
TOPLEVEL = regfile
MODULE = test_regfile

# Keep generated simulation files out of tb/
SIM_BUILD := ../../sim/regfile/build
COCOTB_RESULTS_FILE := ../../sim/regfile/results.xml

include $(shell cocotb-config --makefiles)/Makefile.sim