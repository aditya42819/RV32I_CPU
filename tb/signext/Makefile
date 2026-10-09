SIM ?= icarus
TOPLEVEL_LANG ?= verilog

# RTL source
VERILOG_SOURCES += ../../rtl/signext.sv

# Cocotb test configuration
TOPLEVEL = signext
MODULE = test_signext

# Simulation output
SIM_BUILD := ../../sim/signext/build
COCOTB_RESULTS_FILE := ../../sim/signext/results.xml

include $(shell cocotb-config --makefiles)/Makefile.sim