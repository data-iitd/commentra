#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, p = 97; // 'p' is initialized to 97, which is the ASCII value for 'a'
    scanf("%d", &n);
    char c[n];
    for (i = 0; i < 4; i++) { // Looping through the first 4 positions
        for (j = i; j < n; j += 4) { // Filling every 4th position starting from 'i'
            c[j] = p; // Assigning the character corresponding to ASCII value 'p'
            p++; // Incrementing 'p' to get the next character
        }
    }
    for (i = 0; i < n; i++) {
        printf("%c", c[i]); // Outputting each character in the array
    }
    return 0;
}

