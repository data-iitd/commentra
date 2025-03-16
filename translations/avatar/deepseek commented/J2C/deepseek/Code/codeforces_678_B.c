#include <stdio.h>
#include <stdbool.h>

// Function to check if a year is a leap year
bool check_leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    int y;
    printf("Enter the year: ");
    scanf("%d", &y);

    int sum = 0;
    int mod = 0;

    // Starting a loop from the next year after 'y' to find the first year where the sum of days is a multiple of 7
    for (int i = y + 1; ; i++) {
        if (check_leap(i)) {
            sum += 366;
        } else {
            sum += 365;
        }
        if (sum % 7 == 0) {
            if ((check_leap(i) && check_leap(y)) || (!check_leap(i) && !check_leap(y))) {
                printf("%d\n", i);
                return 0;
            } else {
                continue;
            }
        }
    }
}
