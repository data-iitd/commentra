#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long x;
    scanf("%ld", &x);
    int pow = 0;
    long newNumber = 0;
    int list[100]; // Assuming the number won't have more than 100 digits
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

    for (int i = 0; i < size; i++) {
        newNumber = newNumber + list[i] * (long)pow(10, i);
    }

    printf("%ld\n", newNumber);
    return 0;
}
