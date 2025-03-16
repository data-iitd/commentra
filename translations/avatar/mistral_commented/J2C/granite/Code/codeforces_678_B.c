

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool check_leap(int y) {
    // Returning true if the given year is divisible by 400, or if it is divisible by 4 and not divisible by 100, but not divisible by 100 if the century is not divisible by 4
    return y % 400 == 0 || (y % 4 == 0 && y % 100!= 0);
}

int main() {
    int y;
    scanf("%d", &y);

    bool leap = check_leap(y);
    int sum = 0;
    int mod = 0;

    for (int i = y + 1; ; i++) {
        if (check_leap(i)) {
            sum += 366;
            if ((leap && check_leap(i)) || (!leap &&!check_leap(i))) {
                printf("%d\n", i);
                return 0;
            }
        } else {
            sum += 365;
        }

        if (sum % 7 == 0) {
            if ((leap && check_leap(i)) || (!leap &&!check_leap(i))) {
                continue;
            }
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}

