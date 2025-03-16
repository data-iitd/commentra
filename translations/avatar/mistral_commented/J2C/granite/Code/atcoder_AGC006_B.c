

#include <stdio.h> // Include the standard input/output library

int main() { // Main function to start the execution of the program
    int n, x; // Declare two integer variables n and x
    scanf("%d %d", &n, &x); // Read the first and second integer inputs from the user using scanf
    print(x, n); // Call the print function with x and n as arguments
    return 0; // Return 0 to indicate successful execution
}

void print(int x, int n) { // Function to print the answer based on the given input
    int max = n * 2 - 1; // Calculate the maximum index for the sequence
    if (x == 1 || x == max) { // Check if x is the first or last index in the sequence
        printf("No\n"); // If true, print "No" and return
        return;
    }
    printf("Yes\n"); // If false, print "Yes"
    for (int i = x + n - 1; i <= x + n + max - 2; i++) { // Generate a sequence of integers from x+n-1 to x+n+max-2
        int index = (i % max) + 1; // Calculate the index of the current integer in the sequence
        printf("%d\n", index); // Print the current integer with a new line
    }
}

The comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!