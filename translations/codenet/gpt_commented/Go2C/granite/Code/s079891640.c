
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100]; // Declare a character array to hold the input string
    scanf("%s", s); // Read input from the user and store it in the array's'

    int i;
    for (i = 0; i < strlen(s); i++) {
        if (strchr(s + i + 1, s[i])!= NULL) {
            printf("no\n"); // If a duplicate character is found, print "no" and exit
            exit(0);
        }
    }

    printf("yes\n"); // If no duplicate characters were found, print "yes"
    return 0;
}
