BUILD_DIR = ./build

PRJ = playground

# EXTERNAL_LIB = /home/hehe/ysyx-workbench/npc/csrc/t1.a

VSRCS = $(shell find $(abspath ./build) -name "*.sv")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
MODULE=Top
VERILATOR_CFLAGS += --trace --x-assign unique \
					-I/home/hehe/ysyx-workbench/npc/csrc/include \
					--x-initial unique -cc --top-module Top \

IMG ?= /home/hehe/ysyx-workbench/am-kernels/tests/cpu-tests/build/dummy-riscv32e-npc
HEX_FILE ?= src/main/hex/dummy.hex


# include搜索路径
CXXFLAGS += -I/home/hehe/ysyx-workbench/npc/csrc/include -I/home/hehe/ysyx-workbench/npc/csrc/isa/include \
						-I/home/hehe/ysyx-workbench/npc/csrc/utils -I/home/hehe/ysyx-workbench/npc/csrc
CFLAGS += -I/home/hehe/ysyx-workbench/npc/csrc/include -I/home/hehe/ysyx-workbench/npc/csrc/isa/include \
						-I/home/hehe/ysyx-workbench/npc/csrc/utils -I/home/hehe/ysyx-workbench/npc/csrc

FILELIST_MK = $(shell find -L ./ -name "filelist.mk")
include $(FILELIST_MK)

tt:
#	echo $(CXXFLAGS)
	# echo $(LIBS)

test:
	mill -i $(PRJ).test

verilog:
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i $(PRJ).runMain Elaborate --target-dir $(BUILD_DIR) --split-verilog

help:
	mill -i $(PRJ).runMain Elaborate --help

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

clean_v:
	-rm -rf $(BUILD_DIR)

.PHONY: test verilog help reformat checkformat clean_c

# sim:
# 	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

# 	@echo "Write this Makefile by yourself."
sim: waveform.vcd
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

verilate: .stamp.verilate

build: obj_dir/Vtop

waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
# 	@./obj_dir/V$(MODULE)
#	添加格式转换
#	xxd -p -c 16 $(IMG).bin | sed 's/\(..\)/\1 /g' > $(IMG)16.bin
	@echo $(IMG)16.bin
	$(eval HEX_FILE=$(IMG)16.bin)
	@echo "hexfile: $(HEX_FILE)"
#	添加over
	@./obj_dir/V$(MODULE) +verilator+rand+reset+2+hexfile=$(HEX_FILE)

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE) CXXFLAGS="$(CXXFLAGS)" CFLAGS="$(CFLAGS)" LDLIBS="-lreadline $(LIBS)"

.stamp.verilate: $(VSRCS) $(CSRCS)
	@echo
	@echo "### VERILATING ###"

#	verilator -Wall --trace -cc $(VSRCS) --exe $(CSRCS)
#	verilator $(VERILATOR_CFLAGS) $(VSRCS) --exe csrc/tb_$(MODULE).cpp
	verilator $(VERILATOR_CFLAGS) $(VSRCS) --exe $(CSRCS) 

	@touch .stamp.verilate

clean_c:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
	rm -rf result/

clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
	rm -rf $(BUILD_DIR)
	rm -rf result/

run:
#	xxd -p -c 16 $(IMG).bin | sed 's/\(..\)/\1 /g' > $(IMG)16.bin
	@echo $(IMG)16.bin
	$(eval HEX_FILE=$(IMG)16.bin)
	@echo "hexfile: $(HEX_FILE)"
	./obj_dir/VTop +hexfile=$(HEX_FILE)

all: verilog sim

.PHONY: run clean clean_v waves build verilate sim all


-include ../Makefile
