#include <stdio.h>

int main(void)
{
    // Declare a variable to hold the input number
    unsigned long n;
    
    // Read the input number from the user
    scanf("%lu", &n);
    
    // Initialize a flag to indicate if a solution is found
    int flg = 0;
    
    // Check if the input number is less than 4
    if (n < 4) {
        // If n is less than 4, output "No" since it's not possible to form n with 4s and 7s
        printf("No\n");
    } else {
        // Iterate through possible counts of 4s (i)
        for (int i = 0; i <= (n / 4); i++) {
            // Iterate through possible counts of 7s (j)
            for (int j = 0; j <= (n / 7); j++) {
                // Check if the current combination of 4s and 7s equals n
                if ((i * 4 + j * 7) == n) {
                    // If a valid combination is found, set the flag to true
                    flg = 1;
                    break; // Exit the inner loop
                }
            }
            // If a valid combination has been found, exit the outer loop
            if (flg) break;
        }
        
        // Check if a valid combination was found
        if (flg) {
            // Output "Yes" if a combination of 4s and 7s can form n
            printf("Yes\n");
        } else {
            // Output "No" if no combination can form n
            printf("No\n");
        }
    }
}
