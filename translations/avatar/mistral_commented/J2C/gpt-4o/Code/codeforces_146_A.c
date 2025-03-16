#include <stdio.h>  // Including standard input-output library
#include <string.h> // Including string library for string manipulation

int main() {
    int x = 0, y = 0;  // Declaring and initializing two integer variables x and y
    int t = 0;        // Declaring and initializing an integer variable t
    int n = 0;        // Declaring and initializing an integer variable n to store the length of the input string
    
    char str[100];    // Declaring a character array str to store the input string (assuming max length of 100)
    
    scanf("%d", &n);  // Reading the integer value of n from the standard input
    scanf("%s", str); // Reading the string value of the input from the standard input
    
    for (int i = 0; i < n; i++) {  // Iterating through each character in the input string
        if (str[i] != '4' && str[i] != '7') {  // Checking if the current character is not equal to '4' or '7'
            t = 1;  // Setting the value of t to 1 if the condition is true
        }
    }
    
    if (t == 1) {  // Checking if the value of t is equal to 1
        printf("NO\n");  // Printing "NO" if the condition is true
    } else {  // Else part of the if statement
        int sumX = 0;  // Declaring and initializing an integer variable sumX to store the sum of the digits in the first half of the string
        int sumY = 0;  // Declaring and initializing an integer variable sumY to store the sum of the digits in the second half
        
        for (int i = 0; i < n / 2; i++) {  // Iterating through the first half of the string to calculate the sum of its digits
            x += str[i] - '0';  // Adding the value of the current digit to the variable x
        }
        
        for (int i = n - 1; i >= n / 2; i--) {  // Iterating through the second half of the string to calculate the sum of its digits
            y += str[i] - '0';  // Adding the value of the current digit to the variable y
        }
        
        if (x == y) {  // Checking if the sum of digits in the first half is equal to the sum of digits in the second half
            printf("YES\n");  // Printing "YES" if the condition is true
        } else {  // Else part of the if statement
            printf("NO\n");  // Printing "NO" if the condition is false
        }
    }
    
    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
