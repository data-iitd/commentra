
#include <stdio.h>
#include <math.h>

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

char* week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
    char s[10];
    scanf("%s", s);

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

