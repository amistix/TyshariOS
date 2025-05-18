# OS? 
It is my first attempt to create OS without any knowledge in that sphere:)
# How to check it out?
### Download TyshariOS:
```shell
git clone https://github.com/amistix/TyshariOS.git ; cd TyshariOS
```
### Install requared tools
## 🧰 Requirements

You need a full cross-compilation toolchain for `x86_64-elf`:

- `x86_64-elf-gcc`  (compiler)
- `x86_64-elf-ld`   (linker)
- `x86_64-elf-as`   (assembler, usually included)
- `nasm` (for .asm files)
- `grub-mkrescue` (for ISO creation)
- `qemu` (to run the OS)
- `make`

### Build OS:

```shell
make build-x86_64
```
Afterwards, you'll get your iso file here: `dist/kernel.iso`.
To launch it just use qemu:
```shell
qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso
```