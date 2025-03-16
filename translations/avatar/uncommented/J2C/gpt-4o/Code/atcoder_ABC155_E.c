#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const long INF = (long)1e15;
    char number[100]; // Assuming the number won't exceed 99 digits
    scanf("%s", number);
    
    int length = strlen(number);
    int *digits = (int *)malloc((length + 1) * sizeof(int));
    
    for (int i = 0; i < length; i++) {
        digits[i] = number[length - 1 - i] - '0';
    }
    
    int bills = 0;
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
    free(digits);
    return 0;
}

// <END-OF-CODE>
