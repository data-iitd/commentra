#include <stdio.h>
#include <string.h>

// Method to print a string to the console
void cout(char *str) {
    printf("%s\n", str);
}

// Main method where the program execution begins
int main() {
    // Creating a Scanner object to read input from the console
    char str[100];
    int n;

    // Reading an integer input which represents the length of the string
    scanf("%d", &n);
    scanf("%*c"); // Consuming the newline character after the integer input
    
    // Reading the actual string input
    scanf("%[^\n]%*c", str);

    // Loop to construct the first half of the string
    char a[100];
    for (int i = 0; i < n / 2; i++) {
        a[i] = str[i]; // Appending characters from the first half of the string to 'a'
    }

    // Checking if the string is made up of two identical halves
    if (strcmp(str, a) == 0) {
        cout("Yes"); // If true, print "Yes"
    } else {
        cout("No"); // If false, print "No"
    }

    return 0;
}

