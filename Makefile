compile:
	nasm -f bin boot/boot.asm -o ./boot.bin

	dd if=/dev/zero of=image.bin bs=512 count=2880
	dd if=boot.bin of=image.bin conv=notrunc

	nasm -f bin kernel/kernel.asm -o kernel.bin
	dd if=kernel.bin of=image.bin conv=notrunc bs=512 seek=1

run: compile
	qemu-system-x86_64 --drive format=raw,file=image.bin

clear:
	rm -f *.bin *.iso *.img