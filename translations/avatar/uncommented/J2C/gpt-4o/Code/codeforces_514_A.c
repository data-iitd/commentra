#include <stdio.h>
#include <stdlib.h>

int main() {
    long x;
    scanf("%ld", &x);
    
    long *list = (long *)malloc(20 * sizeof(long)); // Assuming a maximum of 20 digits
    int size = 0;

    while (x > 0) {
        long r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0) {
                list[size++] = r;
            } else {
                list[size++] = 9 - r;
            }
        } else {
            list[size++] = r;
        }
        x = x / 10;
    }

    long newNumber = 0;
    for (int i = 0; i < size; i++) {
        newNumber += list[i] * (long)pow(10, i);
    }

    printf("%ld\n", newNumber);
    free(list);
    return 0;
}

// <END-OF-CODE>
