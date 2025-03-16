
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 3: Create a slice of integers with a length of 3
    int in[3];
    
    // Step 4: Prompt the user to input three integers
    for (int i = 0; i < 3; i++) {
        scanf("%d", &in[i]);
    }
    
    // Step 5: Sort the slice of integers in ascending order
    qsort(in, 3, sizeof(int), cmpfunc);
    
    // Step 6: Perform a calculation using the sorted integers and print the result
    printf("%d\n", in[2]*10 + in[1] + in[0]);
    
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

