include makefile.conf
PROJECT = test
.PHONY: clean

DEFINES =-D__STARTUP_CLEAR_BSS -D__START=main
OBJECTS += main.o
OBJECTS += startup_ARMCM0.o
TOOLCHAIN= arm-none-eabi
cflags = $(arch_flags) $(defines) $(cpu_defines) $(includes) -wall -ffunction-sections -fdata-sections -fno-builtin
LFLAGS=--specs=nosys.specs -Wl,--gc-sections -Wl,-Map=$(PROJECT).map -Tlink.ld
# Source Rules
%.o: %.S
	$(TOOLCHAIN)gcc $(CFLAGS) -c -o $@ $<

%.o: %.C
	$(TOOLCHAIN)gcc $(CFLAGS) -c -o $@ $<

$(PROJECT).elf: $(OBJECTS)
	$(TOOLCHAIN)gcc $(LFLAGS) $^ $(CFLAGS) -o $@

$(PROJECT).bin: $(PROJECT).elf
	$(TOOLCHAIN)objcopy -O binary $< $@
clean:
	rm -f *.bin *.map *.elf $(CPUDIR) output.txt
	find . -name '*.o' -delete
