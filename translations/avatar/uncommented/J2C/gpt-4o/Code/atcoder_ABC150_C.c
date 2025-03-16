#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *target, char *ans, int depth, char ***result, int *count) {
    if (target[0] == '\0') {
        (*result)[*count] = (char *)malloc((strlen(ans) + 1) * sizeof(char));
        strcpy((*result)[*count], ans);
        (*count)++;
    } else {
        for (int i = 0; i < strlen(target); i++) {
            char newTarget[10]; // Assuming n <= 9 for simplicity
            strncpy(newTarget, target, i);
            newTarget[i] = '\0';
            strcat(newTarget, target + i + 1);
            char newAns[10]; // Assuming n <= 9 for simplicity
            sprintf(newAns, "%s%c", ans, target[i]);
            permutation(newTarget, newAns, depth + 1, result, count);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    char line[2][10] = { "", "" }; // Assuming max length of input is 9
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            char temp[2];
            scanf("%s", temp);
            strcat(line[i], temp);
        }
    }

    char number[10]; // Assuming n <= 9
    for (int i = 1; i <= n; i++) {
        sprintf(number + strlen(number), "%d", i);
    }

    char **listA = (char **)malloc(362880 * sizeof(char *)); // 9! = 362880
    int count = 0;
    permutation(number, "", 0, &listA, &count);

    int sum = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < count; i++) {
            if (strcmp(listA[i], line[j]) == 0) {
                if (sum == 0) {
                    sum += i;
                } else {
                    sum -= i;
                }
            }
        }
    }

    printf("%d\n", abs(sum));

    for (int i = 0; i < count; i++) {
        free(listA[i]);
    }
    free(listA);

    return 0;
}

// <END-OF-CODE>
