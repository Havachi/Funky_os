

all: iso

build:
	./build.sh
iso:
	./iso.sh
run:
	./qemu.sh
clean:
	./clean

