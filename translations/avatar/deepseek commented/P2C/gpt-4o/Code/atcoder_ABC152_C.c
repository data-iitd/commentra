#include <stdio.h>

int main() {
    int N;
    
    // Take the number of elements as input
    scanf("%d", &N);
    
    // Declare an array to hold the integers
    int n[N];
    
    // Take a space-separated string of integers as input and convert them to an array of integers
    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
    
    // Initialize a counter to 1 and a position index to 0
    int a = 1;
    int pos = 0;
    
    // Loop through the array from the second element to the last
    for (int i = 1; i < N; i++) {
        // Check if the current minimum element is greater than the current element
        if (n[pos] > n[i]) {
            // Increment the counter and update the position index
            a++;
            pos = i;
        }
    }
    
    // Print the final count of elements that are greater than the current minimum
    printf("%d\n", a);
    
    return 0;
}

// <END-OF-CODE>
