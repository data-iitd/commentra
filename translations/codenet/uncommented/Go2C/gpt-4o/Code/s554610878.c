#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1000000007;

char* getString() {
    static char buffer[100];
    scanf("%s", buffer);
    return buffer;
}

int main() {
    const char* week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    char* s = getString();
    int index = -1;

    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i;
            break;
        }
    }

    printf("%d\n", 7 - index);
    return 0;
}

/* <END-OF-CODE> */
