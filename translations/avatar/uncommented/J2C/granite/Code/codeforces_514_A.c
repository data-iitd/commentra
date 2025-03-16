
#include <stdio.h>
#include <stdlib.h>

int main() {
    long x;
    scanf("%ld", &x);
    long r;
    long newNumber = 0;
    int pow = 0;
    while (x > 0) {
        r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0) {
                newNumber += r * pow(10, pow);
            } else {
                newNumber += (9 - r) * pow(10, pow);
            }
        } else {
            newNumber += r * pow(10, pow);
        }
        x = x / 10;
        pow++;
    }
    printf("%ld\n", newNumber);
    return 0;
}

