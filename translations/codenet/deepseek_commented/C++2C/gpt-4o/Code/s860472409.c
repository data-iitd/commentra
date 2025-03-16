#include <stdio.h>

int main() {
    int N, ans, i, count; // Declare variables to store the number of elements, answer, index, and count
    scanf("%d", &N); // Read the number of elements N
    int A[N]; // Declare an array A with N elements
<<<<<<< HEAD
    for (i = 0; i < N; i++) { // Loop to read N elements into the array A
=======
    for(i = 0; i < N; i++) { // Loop to read N elements into the array A
>>>>>>> 98c87cb78a (data updated)
        scanf("%d", &A[i]);
    }
    i = 0; // Initialize index i to 0
    ans = 0; // Initialize answer variable ans to 0
    count = 0; // Initialize count variable to 0
<<<<<<< HEAD
    while (i < N - 1) { // Continue the loop until the next element is out of bounds
        if (A[i] == A[i + 1]) { // Check if the current element is equal to the next element
            count++; // Increment the count
            if (count % 2 != 0) // Check if the count is odd
=======
    while(i < N - 1) { // Continue the loop until the next element is out of bounds
        if(A[i] == A[i + 1]) { // Check if the current element is equal to the next element
            count++; // Increment the count
            if(count % 2 != 0) // Check if the count is odd
>>>>>>> 98c87cb78a (data updated)
                ans++; // Increment the answer variable ans
        } else {
            count = 0; // Reset the count to 0 if the current element is not equal to the next element
        }
        i++; // Increment the index i
    }
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    printf("%d\n", ans); // Print the value of ans
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
