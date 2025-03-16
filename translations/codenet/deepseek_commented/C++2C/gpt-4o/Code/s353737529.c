#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

<<<<<<< HEAD
    char s[100]; // Assuming the maximum length of the base -2 representation won't exceed 100 characters
=======
    char s[100]; // Assuming a maximum length for the base -2 representation
>>>>>>> 98c87cb78a (data updated)
    int index = 0;

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    while (n != 0) {
        if (n % 2 == 0) {
            s[index++] = '0';
        } else {
            s[index++] = '1';
        }

        n -= abs(n % 2);
        n /= -2;
    }

    // Reverse the string
<<<<<<< HEAD
    for (int i = 0; i < index / 2; i++) {
        char temp = s[i];
        s[i] = s[index - 1 - i];
        s[index - 1 - i] = temp;
=======
    for (int j = 0; j < index / 2; j++) {
        char temp = s[j];
        s[j] = s[index - j - 1];
        s[index - j - 1] = temp;
>>>>>>> 98c87cb78a (data updated)
    }

    s[index] = '\0'; // Null-terminate the string
    printf("%s\n", s);

    return 0;
}

/* <END-OF-CODE> */
