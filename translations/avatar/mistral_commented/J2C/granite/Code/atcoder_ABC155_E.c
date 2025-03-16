

#include <stdio.h>
#include <string.h>

int main() {
    const long long INF = 1e15;  // Initialize a constant value for large numbers
    char number[100001];  // Declare a character array to store the number
    int digits[100001];  // Declare an integer array to store the digits of the number
    int bills = 0;  // Initialize a variable to store the total bill amount

    scanf("%s", number);  // Read the number from the user

    for (int i = 0; i < strlen(number); i++) {  // Loop through each digit of the number starting from the last digit
        digits[i] = number[strlen(number) - 1 - i] - '0';  // Store the digit value in the array
    }

    for (int i = 0; i <= strlen(number); i++) {  // Loop through each digit of the number including the last digit
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

    return 0;
}
