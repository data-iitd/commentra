#include <stdio.h>  // For handling input/output
#include <string.h> // For using string functions

int main() {
    const long INF = (long)1e15;  // Initialize a constant value for large numbers

    char number[100];  // Declare a character array to store the number as a string
    scanf("%s", number);  // Read the number as a string from the user

    int length = strlen(number);  // Get the length of the number string
    int digits[101] = {0};  // Initialize an array of size length + 1 to store digits of the number

    for (int i = 0; i < length; i++) {  // Loop through each digit of the number starting from the last digit
        digits[i] = number[length - 1 - i] - '0';  // Store the digit value in the array
    }

    int bills = 0;  // Initialize a variable to store the total bill amount

    for (int i = 0; i <= length; i++) {  // Loop through each digit of the number including the last digit
        if (digits[i] == 10) {  // If the current digit is 0
            digits[i + 1]++;  // Increment the next digit
            digits[i] = 0;  // Set the current digit to 0
        }

        if (digits[i] < 5) {  // If the current digit is less than 5
            bills += digits[i];  // Add the digit value to the total bill amount
        } else if (digits[i] == 5) {  // If the current digit is 5
            if (digits[i + 1] >= 5) {  // If the next digit is also 5 or greater
                digits[i + 1]++;  // Increment the next digit
            }
            bills += 5;  // Add 5 to the total bill amount
        } else {  // If the current digit is greater than 5
            digits[i + 1]++;  // Increment the next digit
            bills += 10 - digits[i];  // Add the difference between 10 and the current digit to the total bill amount
        }
    }

    printf("%d\n", bills);  // Print the total bill amount
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
