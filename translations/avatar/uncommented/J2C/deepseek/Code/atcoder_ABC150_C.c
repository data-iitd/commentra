#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char **list, char *target, char *ans, int *index) {
    if (strlen(target) <= 1) {
        int len = strlen(ans) + strlen(target);
        char *result = (char *)malloc(len + 1);
        snprintf(result, len + 1, "%s%s", ans, target);
        list[*index] = result;
        (*index)++;
    } else {
        for (int i = 0; i < strlen(target); i++) {
            char temp[256];
            strncpy(temp, target, i);
            temp[i] = '\0';
            strcat(temp, target + i + 1);
            permutation(list, temp, strncat(ans, target + i, 1), index);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char line[2][256];
    for (int i = 0; i < 2; i++) {
        scanf("%s", line[i]);
    }
    char number[256] = "";
    for (int i = 1; i <= n; i++) {
        char num[10];
        sprintf(num, "%d", i);
        strcat(number, num);
    }
    char *listA[256];
    int index = 0;
    permutation(listA, number, "", &index);
    int sum = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < index; i++) {
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
    for (int i = 0; i < index; i++) {
        free(listA[i]);
    }
    return 0;
}
