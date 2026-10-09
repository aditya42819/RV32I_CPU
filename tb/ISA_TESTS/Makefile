# Makefile for Cocotb + Icarus Verilog (ISA Tests)

SIM ?= icarus
TOPLEVEL_LANG ?= verilog

# RTL Sources (Pure relative paths to avoid Windows space issues)
VERILOG_SOURCES += ../../package/cpu_package.sv
VERILOG_SOURCES += ../../rtl/program_counter.sv
VERILOG_SOURCES += ../../rtl/signext.sv
VERILOG_SOURCES += ../../rtl/alu.sv
VERILOG_SOURCES += ../../rtl/regfile.sv
VERILOG_SOURCES += ../../rtl/control.sv
VERILOG_SOURCES += ../../rtl/load_store_decoder.sv
VERILOG_SOURCES += ../../rtl/reader.sv
VERILOG_SOURCES += ../../rtl/memory.sv
VERILOG_SOURCES += ../../rtl/cpu.sv

# Testbench Top
VERILOG_SOURCES += tb_top.sv

# Top level module name (must match the module name in tb_top.sv)
TOPLEVEL = tb_top

# Python test module name (matches test_cpu.py)
MODULE = test_cpu

# Custom build and results paths to keep things organized
SIM_BUILD := ../../sim/ISA_TESTS/build
COCOTB_RESULTS_FILE := ../../sim/ISA_TESTS/results.xml

include $(shell cocotb-config --makefiles)/Makefile.sim
