
#include <stdio.h>
#include <string.h>

char leapyear(int n) {  // Function to check if a year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
        return 'y';
    } else {
        return 'n';
    }
}

int main() {
    int n;  // Declare an integer variable n
    char d = 'f';  // Initialize the variable d to "f"
    char ans[2];  // Declare a character array ans of size 2

    printf("Enter an integer: ");  // Prompt the user to enter an integer
    scanf("%d", &n);  // Read the integer input from the user

    // Determine if the year is a leap year and initialize ans accordingly
    if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
        strcpy(ans, "ly");  // Copy the string "ly" to ans
    } else {
        strcpy(ans, "nly");  // Copy the string "nly" to ans
    }

    // Start an infinite loop to find the next Friday the 13th
    while (1) {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {  // Check if n is a leap year
            if (d =='m') {  // Update d and n based on the current day
                d = 'w';
                n++;
            } else if (d == 't') {
                d = 'th';
                n++;
            } else if (d == 'w') {
                d = 'f';
                n++;
            } else if (d == 'th') {
                d ='sa';
                n++;
            } else if (d == 'f') {
                d ='s';
                n++;
            } else if (d =='sa') {
                d ='m';
                n++;
            } else if (d =='s') {
                d = 't';
                n++;
            }
        } else {
            if (d =='m') {
                d = 't';
                n++;
            } else if (d == 't') {
                d = 'w';
                n++;
            } else if (d == 'w') {
                d = 'th';
                n++;
            } else if (d == 'th') {
                d = 'f';
                n++;
            } else if (d == 'f') {
                d ='sa';
                n++;
            } else if (d =='sa') {
                d ='s';
                n++;
            } else if (d =='s') {
                d ='m';
                n++;
            }
        }

        // Check if the current day is Friday and the year is a leap year or not
        if (d == 'f' && (strcmp(ans, "ly") == 0 && leapyear(n) == 'y')) {
            break;  // Exit the loop if the condition is met
        } else if (d == 'f' && (strcmp(ans, "nly") == 0 && leapyear(n) == 'n')) {
            break;  // Exit the loop if the condition is met
        }
    }

    printf("The next Friday the 13th is in the year %d.\n", n);  // Print the final year after finding the next Friday the 13th

    return 0;  // Return 0 to indicate successful execution
}

// Translate the above C code to Java and end with comment "