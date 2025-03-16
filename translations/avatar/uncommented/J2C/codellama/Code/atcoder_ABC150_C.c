
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *target, char *ans, int n, int *list) {
    if (n <= 1) {
        list[0] = atoi(ans);
        list[1] = atoi(target);
    } else {
        for (int i = 0; i < n; i++) {
            permutation(target, ans, n - 1, list);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char line[2][100];
    for (int i = 0; i < 2; i++) {
        scanf("%s", line[i]);
    }
    char number[100];
    for (int i = 1; i <= n; i++) {
        sprintf(number, "%d", i);
    }
    int listA[100];
    permutation(number, "", n, listA);
    int sum = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            if (strcmp(line[j], number) == 0) {
                if (sum == 0) {
                    sum += i;
                } else {
                    sum -= i;
                }
            }
        }
    }
    printf("%d", sum);
    return 0;
}

