#include <stdio.h>
#include <string.h>

// Function to print a string to the console
void cout(char* str) {
    printf("%s\n", str);
}

int main() {
    // Initializing variables to hold parts of the input string
    char a[1000] = "", b[1000] = "", str[1000];
    int n;

    // Reading an integer input which represents the length of the string
    scanf("%d", &n);
    getchar(); // Consuming the newline character after the integer input
    
    // Reading the actual string input
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing the newline character from the input string

    // Loop to construct the first half of the string
    for (int i = 0; i < n / 2; i++) {
        a[i] = str[i]; // Appending characters from the first half of the string to 'a'
    }
    a[n / 2] = '\0'; // Null-terminating the first half string

    // Checking if the string is made up of two identical halves
    if (strcmp(str, strncat(a, a, n / 2)) == 0) {
        cout("Yes"); // If true, print "Yes"
    } else {
        cout("No"); // If false, print "No"
    }

    return 0;
}
