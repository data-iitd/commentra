#include <stdio.h>
#include <string.h>

int countOccurrences(const char *str, const char *sub) {
    int count = 0;
    const char *tmp = str;
    while ((tmp = strstr(tmp, sub)) != NULL) {
        count++;
        tmp++; // Move past the last found occurrence
    }
    return count;
}

int main() {
    int n; // Declaring an integer variable to store the number of inputs
    char s[100]; // Declaring a string variable to store the input string (assuming max length of 99)
    
    scanf("%d %s", &n, s); // Reading input from the user and storing it in n and s
    printf("%d\n", countOccurrences(s, "ABC")); // Counting the occurrences of "ABC" in s and printing the result

    return 0;
}

// <END-OF-CODE>
