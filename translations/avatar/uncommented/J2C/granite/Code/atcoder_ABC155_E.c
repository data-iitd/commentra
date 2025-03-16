
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    const long long int INF = (long long int)1e15;
    char number[100000];
    fgets(number, 100000, stdin);
    int digits[100000];
    int i;
    for (i = 0; i < strlen(number); i++) {
        digits[i] = number[strlen(number) - 1 - i] - '0';
    }
    int bills = 0;
    for (i = 0; i <= strlen(number); i++) {
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
//END-OF-CODE