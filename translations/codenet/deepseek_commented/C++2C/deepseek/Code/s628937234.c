#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100], t[100];
    int size;

    // Read a string from the standard input and store it in s
    scanf("%s", s);

    // Assign the first character of s to t
    t[0] = s[0];

    // Calculate the size of s
    size = strlen(s);

    // Append the size of s minus 2 to t
    char sizeStr[20];
    sprintf(sizeStr, "%d", size - 2);
    strcat(t, sizeStr);

    // Append the last character of s to t
    t[strlen(t)] = s[size - 1];
    t[strlen(t) + 1] = '\0';

    // Print the modified string t
    printf("%s\n", t);

    return 0;
}
