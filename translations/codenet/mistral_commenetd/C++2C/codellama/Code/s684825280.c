
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE (1e5 * 2) + 13 // Define the size of the vector

int *a; // Initialize an empty vector 'a' to store the frequency count of each element
int *cnt; // Initialize a vector 'cnt' of size 'SIZE' to store the frequency count of each element

int main(){
    int n, k; // Declare two integers 'n' and 'k' to read input

    scanf("%d %d", &n, &k); // Read the number of elements 'n' and the number of frequencies to consider 'k' from the standard input

    cnt = (int *)malloc(SIZE * sizeof(int)); // Allocate memory for the vector 'cnt'

    for(int i = 0; i < n; ++i){ // Loop through the input elements
        int x; // Declare an integer 'x' to read an element from the standard input

        scanf("%d", &x); // Read an element 'x' from the standard input

        cnt[x]++; // Increment the frequency count of the element 'x' in the vector 'cnt'
    }

    a = (int *)malloc(SIZE * sizeof(int)); // Allocate memory for the vector 'a'

    for(int i = 0; i < SIZE; ++i){ // Loop through all elements in the vector 'cnt'
        if(cnt[i] > 0) // If the frequency count of an element is greater than zero
            a[i] = cnt[i]; // Add the frequency count to the vector 'a'
    }

    int ans = 0; // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts

    qsort(a, SIZE, sizeof(int), compare); // Sort the vector 'a' in ascending order

    int m = SIZE - k; // Calculate the index of the last frequency count to be considered

    for(int i = 0; i < m; ++i){ // Loop through the first 'k' frequency counts and add them to the variable 'ans'
        ans += a[i];
    }

    printf("%d\n", ans); // Print the result 'ans' to the standard output

    free(cnt); // Free the memory allocated for the vector 'cnt'
    free(a); // Free the memory allocated for the vector 'a'

    return 0;
}

int compare(const void *a, const void *b){ // Define a function 'compare' to compare two integers
    return (*(int *)a - *(int *)b); // Return the difference between the two integers
}

