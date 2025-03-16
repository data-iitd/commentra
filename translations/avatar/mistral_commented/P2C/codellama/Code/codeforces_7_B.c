#######
# Code
#######

# Include header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the memory allocation status array
int alocuente[1000000];

// Define the index for the next allocation
int ind = 1;

// Define the number of tests
int t;

// Define the memory size
int m;

// Define the operation type and arguments
char op[1000000][1000000];

// Define the position counter
int pos;

// Define the free block counter
int cnt;

// Define the allocated block counter
int cnt_alloc;

// Define the index for the next allocation
int ind_alloc;

// Define the index for the next free
int ind_free;

// Define the index for the next defragment
int ind_defrag;

// Define the index for the next erase
int ind_erase;

// Define the index for the next print
int ind_print;

// Define the index for the next print
int ind_print_alloc;

// Define the index for the next print
int ind_print_free;

// Define the index for the next print
int ind_print_defrag;

// Define the index for the next print
int ind_print_erase;

// Define the index for the next print
int ind_print_null;

// Define the index for the next print
int ind_print_illegal;

// Define the index for the next print
int ind_print_illegal_erase;

// Define the index for the next print
int ind_print_illegal_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg;

// Define the index for the next print
int ind_print_illegal_defrag_arg;

// Define the index for the next print
int ind_print_illegal_erase_arg_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print_defrag;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print_erase;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print_print;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print_print_alloc;

// Define the index for the next print
int ind_print_illegal_erase_arg_print_print_print_print_print_print_print_print_free;

// Define the index for the next print
int ind_print_illegal_defrag_arg_print_print_print_print_print_print_print_print_free;
