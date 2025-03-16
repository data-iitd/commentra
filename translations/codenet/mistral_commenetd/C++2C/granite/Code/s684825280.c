

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE (1e5 * 2) + 13 // Define the size of the array

int main(){
    int n, k; // Declare two integers 'n' and 'k' to read input

    scanf("%d %d", &n, &k); // Read the number of elements 'n' and the number of frequencies to consider 'k' from the standard input

    int *cnt = (int *)malloc(sizeof(int) * SIZE); // Allocate memory for an array 'cnt' of size 'SIZE' to store the frequency count of each element

    memset(cnt, 0, sizeof(int) * SIZE); // Initialize the array 'cnt' with zeros

    for(int i = 0; i < n; ++i){ // Loop through the input elements
        int x; // Declare an integer 'x' to read an element from the standard input

        scanf("%d", &x); // Read an element 'x' from the standard input

        cnt[x]++; // Increment the frequency count of the element 'x' in the array 'cnt'
    }

    int *a = (int *)malloc(sizeof(int) * SIZE); // Allocate memory for an array 'a' to store the frequency counts of all elements

    int m = 0; // Initialize an integer'm' to store the number of elements with non-zero frequency counts

    for(int i = 0; i < SIZE; ++i){ // Loop through all elements in the array 'cnt'
        if(cnt[i] > 0){ // If the frequency count of an element is greater than zero
            a[m++] = cnt[i]; // Add the frequency count to the array 'a' and increment the variable'm'
        }
    }

    qsort(a, m, sizeof(int)); // Sort the array 'a' in ascending order

    int ans = 0; // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts

    int l = m - k; // Calculate the index of the last frequency count to be considered

    for(int i = 0; i < l; ++i){ // Loop through the first 'k' frequency counts and add them to the variable 'ans'
        ans += a[i];
    }

    printf("%d\n", ans); // Print the result 'ans' to the standard output

    free(cnt); // Free the memory allocated for the array 'cnt'
    free(a); // Free the memory allocated for the array 'a'

    return 0; // Return 0 to indicate successful execution
}



