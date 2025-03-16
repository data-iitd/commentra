#include <stdio.h>
#include <string.h> // For string manipulation

// Function to print a string to the console
void cout(const char *str) {
    printf("%s\n", str);
}

// Main function where the program execution begins
int main() {
    // Initializing variables to hold parts of the input string
    char a[100], str[100]; // Assuming the maximum length of the string is 100
    int n;

    // Reading an integer input which represents the length of the string
    scanf("%d", &n);
    getchar(); // Consuming the newline character after the integer input

    // Reading the actual string input
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Removing the newline character from the string

    // Initializing 'a' as an empty string
    a[0] = '\0';

    // Loop to construct the first half of the string
    for (int i = 0; i < n / 2; i++) {
        strncat(a, &str[i], 1); // Appending characters from the first half of the string to 'a'
    }

    // Checking if the string is made up of two identical halves
    if (strcmp(str, strcat(a, a)) == 0) {
        cout("Yes"); // If true, print "Yes"
    } else {
        cout("No"); // If false, print "No"
    }

    return 0;
}
