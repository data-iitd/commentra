#include <stdio.h>
#include <string.h>

int main() {
    long INF = 1000000000000000;
    char number[100005];
    int digits[100005];
    int bills = 0;

    scanf("%s", number);
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        digits[i] = number[length - 1 - i] - '0';
    }

    for (int i = 0; i <= length; i++) {
        if (digits[i] == 10) {
            digits[i + 1]++;
            digits[i] = 0;
        }
        if (digits[i] < 5) {
            bills += digits[i];
        } else if (digits[i] == 5) {
            if (digits[i + 1] >= 5) {
                digits[i + 1]++;
            }
            bills += 5;
        } else {
            digits[i + 1]++;
            bills += 10 - digits[i];
        }
    }

    printf("%d\n", bills);
    return 0;
}
