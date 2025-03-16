#include <stdio.h>

int main() {
    // Declare variables for the number of elements (n), the threshold value (x), and a slice to hold the integers (l)
    int n, x;
    int l[100]; // Assuming the maximum number of elements is 100
    
    // Read the number of elements (n) from standard input
    scanf("%d", &n);
    // Read the threshold value (x) from standard input
    scanf("%d", &x);
    
    // Loop to read n integers from standard input and store them in the array l
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    // Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
    int tmpSum = 0;
    int rs = 0;
    
    // Loop through the array l to calculate the cumulative sum and determine the result
    for (int i = 0; i < n; i++) {
        // Add the current value to the cumulative sum
        tmpSum += l[i];
        
        // If the cumulative sum is less than or equal to x, update the result
        if (tmpSum <= x) {
            rs = i + 2; // Update result to the current index + 2
        } else {
            break; // Exit the loop if the cumulative sum exceeds x
        }
    }
    
    // Print the final result
    printf("%d\n", rs);
    
    return 0;
}
