#include <stdio.h>
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 98c87cb78a (data updated)
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    char s[100]; // Assuming the maximum length of the string will not exceed 100
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

<<<<<<< HEAD
        n -= (n % 2 < 0) ? -1 : 0; // Adjust n if it's odd
=======
        n -= abs(n % 2);
>>>>>>> 98c87cb78a (data updated)
        n /= -2;
    }

    // Reverse the string
    for (int j = 0; j < index / 2; j++) {
        char temp = s[j];
        s[j] = s[index - j - 1];
        s[index - j - 1] = temp;
    }

    s[index] = '\0'; // Null-terminate the string

    printf("%s\n", s);

    return 0;
}

//<END-OF-CODE>
