
#include <stdio.h>

int main() {
    // Synchronize the input and output streams with stdio
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    // Read an integer n from the standard input
    int n;
    scanf("%d", &n);

    // Allocate an array p of size n to store the input integers
    int p[n];

    // Initialize the variable ans to 0
    int ans = 0;

    // Iterate through the array p from index 0 to n-3
    for (int i = 0; i < n - 2; i++) {
        // Check if the current element p[i] is smaller than the next two elements p[i+1] and p[i+2]
        if (p[i] < p[i+1] && p[i+1] < p[i+2]) {
            // Increment the ans variable if both conditions are true
            ans++;
        }

        // Check if the current element p[i] is greater than the next two elements p[i+1] and p[i+2]
        if (p[i] > p[i+1] && p[i+1] > p[i+2]) {
            // Increment the ans variable if both conditions are true
            ans++;
        }
    }

    // Print the value of ans to the standard output
    printf("%d\n", ans);

    // Return 0 from the main function to indicate successful execution
    return 0;
}


Translate the above C code to Rust and end with comment "