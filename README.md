# Hash Table with Binary Search Tree

Implementing **hash table** data structure that uses *separate chaining* to avoid collisions. While in each indiex it uses a **binary search tree** instead of *linked lists* to store data that has similar indices produced by the hashing function to achieve **faster lookup**.


**Two C dynamic shared libraries** are developed that are ready to reuse along with the **Makefile** to reproduce them.
###### The makefile is for linux but some small tweaks will make it for Windows like changing shared libs extension from .so to .dll etc.

The first library, **bstree.so**, includes the binary search tree data structure and its **algorithms** and operations. While the second one, **hash.so**, builds the hash table above of it.

Accompanied an example program to demonstrate the functionalities.

**The data structures accept int, float and char* data types.** 

#### Build the libraries:
```bash
make

gcc -fPIC -c ./src/bstree.c -o ./src/bstree.o
gcc -shared ./src/bstree.o -o ./libs/libbstree.so
gcc -fPIC -c ./src/hash.c -o ./src/hash.o
gcc -shared ./src/hash.o -L./libs -lbstree -o ./libs/libhash.so
rm ./src/*.o
```

#### Build the example program:
```bash
gcc prog.c -L./libs -lbstree -lhash -o prog
```

**Then we need to add the directory to libraries path:**
```bash
export LD_LIBRARY_PATH=D_LIBRARY_PATH:./libs  
```

###### This is for linux. For Cygwin for example we would use --> PATH="$PATH:./libs".

#### Run the program:
```bash
./prog

starting with an empty table

table now is not empty:

index(0):
index(1): 11 -> 91 ->
index(2): 12 -> 22 ->
index(3): 13 ->
index(4): 94 ->
index(5):
index(6):
index(7):
index(8):
index(9): 19 ->

try now to search for and delete some values: (0 means False while 1 is True)
search for value 13 --> 1
search for value 11 --> 1
search by index 1 --> value 11 found
table size --> 10 while filled buckets --> 5
remove value 13 -->
search again for value 13 --> 0
try again to remove value 13 -->
The value does not exist

print the table after the deletion

index(0):
index(1): 11 -> 91 ->
index(2): 12 -> 22 ->
index(3):
index(4): 94 ->
index(5):
index(6):
index(7):
index(8):
index(9): 19 ->

table size --> 10 while filled buckets --> 4
index where value 19 exists is --> 9
insert value 4

index(0):
index(1): 11 -> 91 ->
index(2): 12 -> 22 ->
index(3):
index(4): 4 -> 94 ->
index(5):
index(6):
index(7):
index(8):
index(9): 19 ->

table size --> 10 while filled buckets --> 4

retrieve all elements in index 4
4 94

index where value 22 exists is --> 2

search by index 4 --> value 94 is found

remove value 91 -->

table is now looking like:

index(0):
index(1): 11 ->
index(2): 12 -> 22 ->
index(3):
index(4): 4 -> 94 ->
index(5):
index(6):
index(7):
index(8):
index(9): 19 ->

table size --> 10 while filled buckets --> 4
```