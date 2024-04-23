MODULE=top

include $(NPC_HOME)/Makefile
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

VERILATOR_CFLAGS += -Wall --trace --x-assign unique \
					--x-initial unique -cc --top-module top
			
.PHONY:sim
sim: waveform.vcd
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/Vtop

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	# @./obj_dir/V$(MODULE)
	@./obj_dir/V$(MODULE) +verilator+rand+reset+2

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(VSRCS) $(CSRCS)
	@echo
	@echo "### VERILATING ###"

	# verilator --trace -cc $(VSRCS) --exe $(CSRCS)
	verilator $(VERILATOR_CFLAGS) $(VSRCS) --exe csrc/tb_$(MODULE).cpp
	@touch .stamp.verilate

.PHONY:lint
lint: $(VSRCS)
	verilator --lint-only $(VSRCS)

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
	rm -rf $(BUILD_DIR)
	rm -rf result/


PROJ_PATH = $(shell pwd)

DESIGN ?= gcd
SDC_FILE ?= $(PROJ_PATH)/gcd.sdc
RTL_FILES ?= $(shell find $(PROJ_PATH)/vsrc -name "*.v")
export CLK_FREQ_MHZ ?= 500

RESULT_DIR = $(PROJ_PATH)/result/$(DESIGN)-$(CLK_FREQ_MHZ)MHz
NETLIST_V  = $(RESULT_DIR)/$(DESIGN).netlist.v
TIMING_RPT = $(RESULT_DIR)/$(DESIGN).rpt

init:
	bash -c "$$(wget -O - https://ysyx.oscc.cc/slides/resources/scripts/init-yosys-sta.sh)"

syn: $(NETLIST_V)
$(NETLIST_V): $(RTL_FILES) yosys.tcl
	mkdir -p $(@D)
	echo tcl yosys.tcl $(DESIGN) \"$(RTL_FILES)\" $(NETLIST_V) | yosys -l $(@D)/yosys.log -s -

sta: $(TIMING_RPT)
$(TIMING_RPT): $(SDC_FILE) $(NETLIST_V)
	LD_LIBRARY_PATH=bin/ ./bin/iSTA $(PROJ_PATH)/sta.tcl $(DESIGN) $(SDC_FILE) $(NETLIST_V)

.PHONY: init syn sta 
