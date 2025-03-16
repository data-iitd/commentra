#include <stdio.h>

int main() {
    int x;
<<<<<<< HEAD
    scanf("%d", &x); // Read an integer from input
=======
    scanf("%d", &x); // Read an integer from standard input
>>>>>>> 98c87cb78a (data updated)

    int i = 1;
    int sum = 0;

    while (1) {
        sum += i;
        if (sum >= x) {
            break;
        }
        i++;
    }

    printf("%d\n", i); // Print the result
    return 0;
}

/* <END-OF-CODE> */
