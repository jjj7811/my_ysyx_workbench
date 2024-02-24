MODULE=top

include $(NPC_HOME)/Makefile
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

VERILATOR_CFLAGS += -Wall --trace --x-assign unique \
					--x-initial unique -cc --top-module top \
					-Wno-lint 			
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

	# verilator -Wall --trace -cc $(VSRCS) --exe $(CSRCS)
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
