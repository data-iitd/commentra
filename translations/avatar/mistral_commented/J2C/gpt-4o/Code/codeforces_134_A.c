#include <stdio.h> // Including the standard input-output library

int main() { // Starting the main function
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements from standard input
    int arr[n]; // Creating an integer array of size n
    int sum = 0; // Initializing the sum variable to 0

    for (int i = 0; i < n; i++) { // Starting a for loop to read and store the elements in the array
        scanf("%d", &arr[i]); // Reading an integer value from standard input and storing it in the current index of the array
        sum += arr[i]; // Adding the current element to the sum variable
    }

    int c = 0; // Initializing the counter variable to 0
    // Using a buffer to store the indices of the elements that satisfy the condition
    char sb[1000] = ""; // Assuming a maximum of 1000 characters for the output string

    for (int i = 0; i < n; i++) { // Starting a for loop to check if an element satisfies the condition
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) { // Checking if the current element satisfies the condition
            c++; // Incrementing the counter variable if the condition is true
            char buffer[20]; // Buffer to hold the index as a string
            sprintf(buffer, "%d ", i + 1); // Formatting the index to a string
            strcat(sb, buffer); // Appending the index of the current element to the sb string
        }
    }

    printf("%d\n", c); // Printing the number of elements that satisfy the condition
    printf("%s\n", sb); // Printing the indices of the elements that satisfy the condition separated by a space

    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
