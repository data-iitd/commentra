
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable N to store the input integer
    int N;
    scanf("%d", &N);

    // Initialize a long variable i starting from 357
    long i = 357;

    // Initialize a counter to keep track of valid numbers
    int c = 0;

    // Loop until i exceeds N
    while (i <= N) {
        // Convert the current number i to a String
        char s[20];
        sprintf(s, "%ld", i);

        // Check if the string contains '3', '5', and '7'
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7"))
            c++; // Increment the counter if all digits are present

        // Create a StringBuilder to construct a new number
        char sb[20];
        int f = 0; // Flag to indicate if a replacement has occurred

        // Iterate through the digits of the number in reverse order
        for (int j = strlen(s) - 1; j >= 0; j--) {
            char a = s[j]; // Get the current digit

            // If a replacement has occurred, append the digit as is
            if (f) {
                sb[strlen(sb)] = a;
            } else {
                // Replace '3' with '5' and set the flag
                if (a == '3') {
                    sb[strlen(sb)] = '5';
                    f = 1;
                }
                // Replace '5' with '7' and set the flag
                else if (a == '5') {
                    sb[strlen(sb)] = '7';
                    f = 1;
                }
                // If it's neither, append '3'
                else {
                    sb[strlen(sb)] = '3';
                }
            }
        }

        // If no replacement occurred, append '3' to the StringBuilder
        if (!f)
            sb[strlen(sb)] = '3';

        // Reverse the constructed number and parse it back to long
        char sb2[20];
        int k = 0;
        for (int j = strlen(sb) - 1; j >= 0; j--) {
            sb2[k++] = sb[j];
        }
        sb2[k] = '\0';
        i = atol(sb2);
    }

    // Print the total count of valid numbers found
    printf("%d\n", c);

    return 0;
}
