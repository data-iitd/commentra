// Include standard input-output library
#include <stdio.h>
#include <string.h>

int main() {
    // Initialize a variable s of type char array to hold the string input
    char s[100]; // Assuming the input string will not exceed 99 characters
    // Read a string input from the standard input
    scanf("%s", s);

    // Initialize a variable ans with the string value "No"
    char *ans = "No";

    // Check if the index of the substring "C" in the string s is less than the index of the substring "F"
    if (strchr(s, 'C') != NULL && strchr(s, 'F') != NULL && 
        (strchr(s, 'C') - s) < (strrchr(s, 'F') - s)) {
        // If it is, then change the value of ans to "Yes"
        ans = "Yes";
    }

    // Check if the index of the substring "C" in the string s is less than 0
    if (strchr(s, 'C') == NULL) {
        // If it is, then do not change the value of ans
    }

    // Print the value of ans to the standard output
    printf("%s\n", ans);

    return 0;
}

// <END-OF-CODE>
