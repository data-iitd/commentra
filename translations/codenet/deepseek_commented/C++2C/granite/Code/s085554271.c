
#include <stdio.h>

int main() {
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            printf("OK\n");
            return 0;
        }
    }
    printf("NG\n");
    return 0;
}

/*
TELEVISION also no
RADIO also no
AUTOMobile also no
PIANO also no
BAR also no
GUARD patrol every day
WAKING up, take a walk
Two hours of walking
PHONE also no
WASHING machine also no
BUS come once a day
I'm in this village, I'm in this village
TOkyo go out, TOkyo go out
Save money, raise cows in TOkyo
*/