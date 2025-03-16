#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

<<<<<<< HEAD
// Function to convert an integer from base 10 to base n
=======
// Function to convert an integer from base 10 to base K
>>>>>>> 98c87cb78a (data updated)
char* tenToN(int number, int n) {
    char* s = (char*)malloc(32); // Allocate memory for the string
    int index = 0;
    int tmp = number;

    do {
        s[index++] = (tmp % n) + '0'; // Convert digit to character
        tmp /= n;
    } while (tmp > 0);

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = s[i];
        s[i] = s[index - i - 1];
        s[index - i - 1] = temp;
    }
    s[index] = '\0'; // Null-terminate the string
    return s;
}

int main() {
    int N, K;
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    // Read two integers N and K from standard input
    scanf("%d %d", &N, &K);

    // Convert N to base K and print the length of the resulting string
    char* s = tenToN(N, K);
    printf("%lu\n", strlen(s)); // Print the length of the string

    free(s); // Free allocated memory
    return 0;
}

/* <END-OF-CODE> */
