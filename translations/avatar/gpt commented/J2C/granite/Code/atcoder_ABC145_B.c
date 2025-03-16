
#include <stdio.h> // Including the standard input/output library
#include <string.h> // Including the string manipulation library

// Method to print a string to the console
void cout(char *str) {
    printf("%s\n", str);
}

int main() {
    // Creating variables to hold parts of the input string
    char a[1000], b[1000], str[1000];
    int n;

    // Reading an integer input which represents the length of the string
    scanf("%d", &n);
    getchar(); // Consuming the newline character after the integer input
    
    // Reading the actual string input
    gets(str);

    // Loop to construct the first half of the string
    for (int i = 0; i < n / 2; i++) {
        a[i] = str[i]; // Appending characters from the first half of the string to 'a'
    }

    // Checking if the string is made up of two identical halves
    if (strcmp(str, a) == 0) {
        cout("Yes"); // If true, print "Yes"
    } else {
        cout("No"); // If false, print "No"
    }

    return 0; // Returning 0 to indicate successful program execution
}

