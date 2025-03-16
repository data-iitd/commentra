#include <stdio.h>

int main() {
    // Declare a variable n of type int and initialize it to zero
    int n;
    // Read an integer value from the standard input and store it in the variable n
    scanf("%d", &n);
    // Declare a variable ans of type int and initialize it to zero
    int ans = 0;
    // Use a for loop to iterate through all possible factors of n
    for (int i = 1; i * i < n; i++) {
        // Check if i is a factor of n
        if (n % i == 0) {
            // Check if i is the last factor of n
            if (n % (n / i - 1) == i) {
                // If both conditions are true, add the last factor to the answer
                ans += n / i - 1;
            }
        }
    }
    // Print the answer to the standard output
    printf("%d\n", ans);
    // End of the code
    return 0;
}
