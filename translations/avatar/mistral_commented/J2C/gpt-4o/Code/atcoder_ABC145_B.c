#include <stdio.h>
#include <string.h>

void cout(const char *str) { // Defining a function named cout that takes a string argument and prints it to the console
    printf("%s\n", str); // Printing the given string to the console
}

int main() { // Defining the main function that is the entry point of the program
    char str[100]; // Declaring a character array to hold the input string
    char a[50]; // Declaring a character array to hold the first half of the string
    int n; // Declaring an integer variable named n

    scanf("%d", &n); // Reading an integer value from the console and assigning it to the variable n
    getchar(); // Consuming the newline character left after reading an integer value

    fgets(str, sizeof(str), stdin); // Reading a line of text from the console and assigning it to the variable str
    str[strcspn(str, "\n")] = 0; // Removing the newline character from the string if present

    a[0] = '\0'; // Initializing the string a to be empty

    for (int i = 0; i < n / 2; i++) { // Starting a for loop that iterates n/2 times
        strncat(a, &str[i], 1); // Appending the character at the current index of str to the variable a
    }

    if (strcmp(str, strcat(a, a)) == 0) { // Checking if the given string is a palindrome
        cout("Yes"); // Printing "Yes" to the console if the given string is a palindrome
    } else {
        cout("No"); // Printing "No" to the console if the given string is not a palindrome
    }

    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
