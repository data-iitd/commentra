#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long x;
    scanf("%ld", &x);
    int pow = 0;
    long newNumber = 0;
    while (x > 0) {
        long r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0) {
                newNumber = newNumber + r * (long)pow(10, pow);
            } else {
                newNumber = newNumber + (9 - r) * (long)pow(10, pow);
            }
        } else {
            newNumber = newNumber + r * (long)pow(10, pow);
        }
        pow++;
        x = x / 10;
    }
    printf("%ld\n", newNumber);
    return 0;
}
