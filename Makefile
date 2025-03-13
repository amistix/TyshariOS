# Compiler and required tools
CC = gcc
NASM = nasm
DD = dd
QEMU = qemu-system-x86_64

# Required tools to check
REQUIRED_TOOLS = $(CC) $(NASM) $(DD) $(QEMU) $(GENISOIMAGE)

# Check if the required tools are installed
check:
	@echo "Checking for required tools..."
	@for tool in $(REQUIRED_TOOLS); do \
		if ! command -v $$tool &> /dev/null; then \
			echo "Error: $$tool is required but not installed."; \
			exit 1; \
		fi \
	done
	@echo "All required tools are installed."

# Compile the bootloader and kernel, and create a bootable image
compile: check
	nasm -f bin boot/boot.asm -o ./boot.bin || { echo "Bootloader assembly failed"; exit 1; }
	dd if=/dev/zero of=image.bin bs=512 count=2880 || { echo "dd failed for image.bin"; exit 1; }
	dd if=boot.bin of=image.bin conv=notrunc || { echo "Bootloader dd failed"; exit 1; }
	nasm -f bin kernel/kernel.asm -o kernel.bin || { echo "Kernel assembly failed"; exit 1; }
	dd if=kernel.bin of=image.bin conv=notrunc bs=512 seek=1 || { echo "Kernel dd failed"; exit 1; }

# Run the emulation
run: compile
	qemu-system-x86_64 --drive format=raw,file=image.bin

# Clean up generated files
clear:
	rm -f *.bin *.iso *.img
