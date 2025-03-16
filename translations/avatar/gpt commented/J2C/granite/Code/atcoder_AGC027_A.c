
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of sweet items (N) and the initial amount of money (x)
    int N, x;
    scanf("%d %d", &N, &x);
    
    // Initialize an array to store the sweetness values of the items
    int sweet[N];
    
    // Read the sweetness values and store them in the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &sweet[i]);
    }
    
    // Sort the array of sweetness values in ascending order
    qsort(sweet, N, sizeof(int), cmpfunc);
    
    // Initialize a counter for the number of sweet items that can be bought
    int num = 0;
    
    // Iterate through the sorted sweetness values
    for (int i = 0; i < N; i++) {
        // Check if the current sweetness value can be bought with the remaining money
        if (x - sweet[num] >= 0) {
            // Deduct the sweetness value from the total money
            x = x - sweet[num];
            // Increment the count of items bought
            num++;
        } else {
            // If the current item cannot be bought, exit the loop
            break;
        }
    }
    
    // Adjust the count if all items were bought but there is still money left
    if ((num == N) && (x > 0)) {
        num -= 1;
    }
    
    // Print the total number of sweet items that can be bought
    printf("%d\n", num);
    
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

