#include <stdio.h>
#include <string.h>

int countOccurrences(const char *str, const char *sub) {
    int count = 0;
<<<<<<< HEAD
    const char *temp = str;

    while ((temp = strstr(temp, sub)) != NULL) {
        count++;
        temp++; // Move past the last found occurrence
=======
    const char *tmp = str;

    while ((tmp = strstr(tmp, sub)) != NULL) {
        count++;
        tmp++; // Move past the last found occurrence
>>>>>>> 98c87cb78a (data updated)
    }

    return count;
}

int main() {
    // Declare variables to hold the integer input and the string input
    int n;
    char s[100]; // Assuming the string will not exceed 99 characters

    // Read an integer from standard input
    scanf("%d", &n);
    
    // Read a string from standard input
    scanf("%s", s);
    
    // Count the occurrences of the substring "ABC" in the input string
    // and print the result
    printf("%d\n", countOccurrences(s, "ABC"));

    return 0;
}

// <END-OF-CODE>
