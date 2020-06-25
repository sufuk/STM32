PROJ_NAME=blinky
STM_DIR=STM32Cube_FW_F0_V1.11.0
# This is where the source files are located,
# which are not in the current directory
# (the sources of the standard peripheral library, which we use)
# see also "info:/make/Selective Search" in Konqueror
STM_SRC = $(STM_DIR)/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates

# Tell make to look in that folder if it cannot find a source
# in the current directory
vpath %.c $(STM_SRC)

# My source file
SRCS   = main.c

# Contains initialisation code and must be compiled into
# our project. This file is in the current directory and
# was writen by ST.
SRCS  += system_stm32f0xx.c
# Startup file written by ST
# The assembly code in this file is the first one to be
# executed. Normally you do not change this file.
SRCS += $(STM_DIR)/Drivers/CMSIS/Device/ST/STM32F0xx/Source/Templates/gcc/startup_stm32f051x8.s
# The header files we use are located here
INC_DIRS  = $(STM_DIR)/Drivers/CMSIS/Include
INC_DIRS += $(STM_DIR)/Drivers/CMSIS/Device/ST/STM32F0xx/Include
INC_DIRS += .

# in case we have to many sources and don't want 
# to compile all sources every time
# OBJS = $(SRCS:.c=.o)

######################################################################
#                         SETUP TOOLS                                #
######################################################################


# This is the path to the toolchain
TOOLS_DIR = /usr/bin
# The tool we use
CC      = $(TOOLS_DIR)/arm-none-eabi-gcc
OBJCOPY = $(TOOLS_DIR)/arm-none-eabi-objcopy
GDB     = $(TOOLS_DIR)/arm-none-eabi-gdb

## Preprocessor options

# directories to be searched for header files
INCLUDE = $(addprefix -I,$(INC_DIRS))

# #defines needed when working with the STM library
DEFS    = -DUSE_STDPERIPH_DRIVER
# if you use the following option, you must implement the function 
#    assert_failed(uint8_t* file, uint32_t line)
# because it is conditionally used in the library
# DEFS   += -DUSE_FULL_ASSERT

## Compiler options
CFLAGS  = -ggdb
# please do not optimize anything because we are debugging
CFLAGS += -O0 
CFLAGS += -Wall -Wextra -Warray-bounds
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -mthumb-interwork

## Linker options
# tell ld which linker file to use
# (this file is in the current directory)
LFLAGS  = -Tlinker.ld


######################################################################
#                         SETUP TARGETS                              #
######################################################################

.PHONY: $(PROJ_NAME)
$(PROJ_NAME): $(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(INCLUDE) $(DEFS) $(CFLAGS) $(LFLAGS) $^ -o $@ 
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf   $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

clean:
	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin

# Flash the STM32F4
flash: 
	st-flash write $(PROJ_NAME).bin 0x8000000

.PHONY: debug
debug:
# before you start gdb, you must start st-util
	$(GDB) $(PROJ_NAME).elf
