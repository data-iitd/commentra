#include <stdio.h>
#include <string.h>

#define INF 1e15

int main() {
    char number[1000];
    int digits[1001];
    int bills = 0;

    // Read the input number as a string
    scanf("%s", number);

    // Initialize an array to hold the digits of the number in reverse order
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        digits[i] = number[length - 1 - i] - '0';
    }
    digits[length] = 0; // Null-terminate the string for safety

    // Process each digit to calculate the total number of bills needed
    for (int i = 0; i <= length; i++) {
        // Handle carry over for digits equal to 10
        if (digits[i] == 10) {
            digits[i + 1]++;
            digits[i] = 0;
        }

        // If the digit is less than 5, add it directly to the bills
        if (digits[i] < 5) {
            bills += digits[i];
        }
        // If the digit is exactly 5, check the next digit for rounding
        else if (digits[i] == 5) {
            if (digits[i + 1] >= 5) {
                digits[i + 1]++;
            }
            bills += 5;
        }
        // If the digit is greater than 5, round up to the next ten
        else {
            digits[i + 1]++;
            bills += 10 - digits[i];
        }
    }

    // Output the total number of bills calculated
    printf("%d\n", bills);

    return 0;
}
