
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *str, int l, int r, char *ans, int *sum) {
    if (l == r) {
        char *tmp = (char *)malloc(strlen(ans) + strlen(str + l) + 1);
        strcpy(tmp, ans);
        strcat(tmp, str + l);
        int index = atoi(tmp) - 1;
        if (*sum == 0) {
            *sum += index;
        } else {
            *sum -= index;
        }
        free(tmp);
    } else {
        for (int i = l; i <= r; i++) {
            char tmp = str[l];
            str[l] = str[i];
            str[i] = tmp;
            permutation(str, l + 1, r, ans + 1, sum);
            tmp = str[l];
            str[l] = str[i];
            str[i] = tmp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char *line[2][1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", line[i][0]);
        }
    }
    char number[10];
    for (int i = 1; i <= n; i++) {
        number[i - 1] = '0' + i;
    }
    int sum = 0;
    for (int j = 0; j < 2; j++) {
        permutation(number, 0, n - 1, "", &sum);
    }
    printf("%d\n", abs(sum));
    return 0;
}

