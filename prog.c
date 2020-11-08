#include <stdio.h>
#include <stdlib.h>
#include "src/bstree.h"
#include "src/hash.h"
#undef TABLE_SIZE
#define TABLE_SIZE 10

int main() {
  ht * table = hash_init(TABLE_SIZE, 0);
  int i;
  Tuple t;
  int arr[7] = {
    13,
    11,
    19,
    91,
    22,
    12,
    94
  };
  for (i = 0; i < 7; ++i){
	  t = int_in(arr[i]);
    insert(table, t);
  }
  puts("table now is not empty:");
  print_hash(table);
  puts("");
  puts("try now to search for and delete some values: (0 means False while 1 is True)");
  printf("search for value 13 --> %d \n", val_search(table, int_in(13)));
  printf("search for value 11 --> %d \n", val_search(table, int_in(11)));
  printf("search by index 1 --> value %s found\n", search_by_index(table, 1));
  printf("table size --> %d while filled buckets --> %d\n", len(table), filled_indices(table));
  printf("remove value 13 -->\n"); 
  delete_val(table, int_in(13));
  printf("search again for value 13 --> %d \n", val_search(table, int_in(13)));
  printf("try again to remove value 13 -->\n"); 
  delete_val(table, int_in(13));
  puts("\nprint the table after the deletion");
  print_hash(table);
  printf("\ntable size --> %d while filled buckets --> %d\n", len(table), filled_indices(table));
  printf("index where value 19 exists is --> %d\n", get_indx(table, int_in(19)));
  puts("insert value 4");
  insert(table, int_in(4));
  print_hash(table);
  printf("\ntable size --> %d while filled buckets --> %d\n", len(table), filled_indices(table));
  printf("index where value 22 exists is --> %d\n", get_indx(table, int_in(22)));
  printf("\nsearch by index 4 --> value %s is found \n\n", search_by_index(table, 4));
  printf("remove value 91 -->\n");
  delete_val(table, int_in(91));
  puts("\ntable is now looking like:");
  print_hash(table);
  printf("\ntable size --> %d while filled buckets --> %d\n", len(table), filled_indices(table));
}