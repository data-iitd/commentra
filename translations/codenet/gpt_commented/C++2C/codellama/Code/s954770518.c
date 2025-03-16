#include<stdio.h>
#include<stdlib.h>

int main()
{
    // Declare an array to hold 10 integers
    int s[11], i;

    // Input 10 integers from the user
    for(i = 0; i < 10; i++) {
        scanf("%d", &s[i]);
    }

    // Sort the array of integers in ascending order
    qsort(s, 10, sizeof(int), compare);

    // Print the three largest integers from the sorted array
    for(i = 9; i > 6; i--) {
        printf("%d\n", s[i]);
    }

    return 0; // Indicate that the program ended successfully
}

int compare(const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b );
}

