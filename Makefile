all: build_bst build_hash clean

build_bst:
	$(shell mkdir -p ./libs)
	gcc -fPIC -c ./src/bstree.c -o ./src/bstree.o
	gcc -shared ./src/bstree.o -o ./libs/libbstree.so
	
build_hash:
	gcc -fPIC -c ./src/hash.c -o ./src/hash.o
	gcc -shared ./src/hash.o -L./libs -lbstree -o ./libs/libhash.so
	
clean:
	rm ./src/*.o
	
buildexe:
	gcc prog.c -L./libs -lbstree -lhash -o prog
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs