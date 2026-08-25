# TyshariOS

TyshariOS is a small x86-64 operating system written in C and assembly.

This is my first attempt at building an operating system, so the project is primarily a learning experience. The goal is to gradually build the kernel from the ground up while learning how CPUs, memory, hardware I/O, interrupts, and operating-system components work.

# Current status

TyshariOS is currently in early development.

At the moment, the project includes:

- x86-64 kernel booting through GRUB
- VGA text-mode terminal output
- Basic terminal functions
- Low-level x86 I/O port access
- Basic PS/2 keyboard polling
- Basic keyboard input and command-line interaction
- A freestanding x86_64-elf build

Interrupt-driven keyboard input and other kernel features are planned for later development.

## Project structure
```
TyshariOS/
├── src/
│   ├── impl/
│   │   ├── kernel/       # Platform-independent kernel code
│   │   └── x86_64/      # x86-64-specific implementation and boot code
│   └── intf/             # Public interfaces/headers
├── targets/
│   └── x86_64/           # Linker script and GRUB ISO configuration
├── Makefile
└── README.md
```
# Requirements

You need an x86_64-elf cross-compilation toolchain and the tools used to create and run the bootable ISO.

- ```x86_64-elf-gcc```
- ```x86_64-elf-ld```
- ```nasm```
- ```grub-mkrescue```
- ```qemu-system-x86_64```
- ```make```

# Building

Clone the repository:

```
git clone https://github.com/amistix/TyshariOS.git
cd TyshariOS
```

Build the x86-64 kernel and ISO:
```
make build-x86_64
```

The resulting files are placed under:```dist/x86_64/```<br>
The bootable ISO is:
```dist/x86_64/kernel.iso```

## Running in QEMU

Run the operating system with:
```
qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso
```

You should see the TyshariOS terminal inside the QEMU window.

# Development

The development is difficult due to my lack of knowledge. I make an effort to commit periodically though.
