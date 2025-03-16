
#include <stdio.h> // Include the standard input/output library

int main() {
    // Declare and initialize variables n and x
    int n, x;
    scanf("%d %d", &n, &x);
    
    // Call the print function with the inputs x and n
    print(x, n);
    
    return 0; // Return 0 to indicate successful execution
}

void print(int x, int n) {
    // Calculate the maximum value based on n
    int max = n * 2 - 1;
    
    // Check if x is equal to 1 or max, if so, print "No" and exit the function
    if (x == 1 || x == max) {
        printf("No\n");
        return; // Exit the function early
    }
    
    // If x is valid, print "Yes"
    printf("Yes\n");
    
    // Prepare the line separator for formatting output
    char sep = '\n';
    
    // Generate a sequence of numbers based on the input x and n
    for (int i = x + n - 1; i < x + n + max - 1; i++) {
        // Adjust the number to fit within the range
        int num = (i % max + 1);
        
        // Print the number with the line separator
        printf("%d%c", num, sep);
    }
}

// END-OF-CODE