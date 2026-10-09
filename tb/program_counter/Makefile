SIM ?= icarus
TOPLEVEL_LANG ?= verilog

# RTL source being tested
VERILOG_SOURCES += ../../rtl/program_counter.sv

# Cocotb test configuration
TOPLEVEL = program_counter
MODULE = test_program_counter

# Keep generated simulation files out of tb/.
SIM_BUILD := ../../sim/program_counter/build
COCOTB_RESULTS_FILE := ../../sim/program_counter/results.xml

include $(shell cocotb-config --makefiles)/Makefile.sim