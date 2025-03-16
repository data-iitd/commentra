#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *target, char *ans, int depth, int n, int *sum, int *foundIndex, int *index) {
    if (depth == n) {
        ans[depth] = '\0'; // Null-terminate the string
        if (strcmp(ans, target) == 0) {
            if (*foundIndex == -1) {
                *foundIndex = *index;
            } else {
                *sum -= *index;
            }
        }
        (*index)++;
    } else {
        for (int i = 0; i < n; i++) {
            if (target[i] != '\0') {
                char temp = target[i];
                target[i] = '\0'; // Mark as used
                ans[depth] = temp;
                permutation(target, ans, depth + 1, n, sum, foundIndex, index);
                target[i] = temp; // Backtrack
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    char line[2][100] = {""}; // Assuming max length of concatenated strings is 99
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            char input[100];
            scanf("%s", input);
            strcat(line[i], input);
        }
    }

    char number[10]; // Assuming n <= 9
    for (int i = 1; i <= n; i++) {
        number[i - 1] = '0' + i; // Convert integer to character
    }
    number[n] = '\0'; // Null-terminate the string

    int sum = 0;
    int foundIndex = -1;
    int index = 0;
    char ans[10]; // Assuming n <= 9

    permutation(number, ans, 0, n, &sum, &foundIndex, &index);

    printf("%d\n", abs(sum));
    return 0;
}

// <END-OF-CODE>
