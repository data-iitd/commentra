
#include <stdio.h>  // Include the standard input/output library
#include <math.h>  // Include the standard math library

int main() {
    int n, num;  // Declare two integer variables: n and num
    scanf("%d %d", &n, &num);  // Read two integers from input

    int a[n];  // Declare an array of size n to store the input numbers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);  // Read n integers from input and store them in the array
    }

    int count = 0;  // Initialize a variable to count the number of times a number can be divided by 2
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {  // Check if the number can be divided by 2
            a[i] /= 2;  // Divide the number by 2
            count++;  // Increment the count
        }
    }

    if (count == 0) {  // If no number can be divided by 2, print 0
        printf("0\n");
    } else {
        int lcm = a[0];  // Initialize the least common multiple (LCM) with the first element of the array
        for (int i = 1; i < n; i++) {
            int temp = a[i];  // Store the current number in a temporary variable
            while (temp!= lcm) {  // Calculate the LCM using the Euclidean algorithm
                if (temp > lcm) {
                    temp -= lcm;
                } else {
                    lcm -= temp;
                }
            }
        }

        int result = (num - lcm / 2) / lcm + 1;  // Calculate the final result based on the LCM and the input number
        printf("%d\n", result);  // Print the result
    }

    return 0;  // Return 0 to indicate successful execution
}
