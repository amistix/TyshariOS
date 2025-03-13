# OS? 
It is my first attempt to create OS without any knowledge in that sphere:)
# How to check it out?
## On Linux:
### Download TyshariOS:
```shell
git clone https://github.com/amistix/TyshariOS.git ; cd TyshariOS
```
### Install requared tools
On Ubuntu/Debian:
```shell
sudo apt install gcc nasm qemu
```
On Fedora/RHEL/CentOS:
```shell
sudo dnf install gcc nasm qemu 
```
On Arch:
```shell
sudo pacman -S gcc nasm qemu-full
```
### Run qemu
```shell
make run
```