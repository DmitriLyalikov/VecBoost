# Compiler and linker settings
CC := riscv64-unknown-elf-gcc
AS := riscv64-unknown-elf-as
LD := riscv64-unknown-elf-ld

# Compiler and linker flags
CFLAGS := -march=rv32i -mabi=ilp32 -O2 -ffreestanding -nostdlib
ASFLAGS := -march=rv32i
LDFLAGS := -T link.ld

# Source files
ASM_SRCS := my_asm_functions.S
C_SRCS := main.c

# Object files
ASM_OBJS := $(ASM_SRCS:.S=.o)
C_OBJS := $(C_SRCS:.c=.o)
OBJS := $(ASM_OBJS) $(C_OBJS)

# Executable name
TARGET := my_program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJS)

$(ASM_OBJS): $(ASM_SRCS)
	$(AS) $(ASFLAGS) -o $@ $<

$(C_OBJS): $(C_SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)