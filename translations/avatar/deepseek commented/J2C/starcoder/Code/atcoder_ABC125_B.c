
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    char *vStr = (char *)malloc(sizeof(char) * (n + 1));
    scanf("%s", vStr);
    char *cStr = (char *)malloc(sizeof(char) * (n + 1));
    scanf("%s", cStr);
    int *vArr = (int *)malloc(sizeof(int) * n);
    int *cArr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        vArr[i] = vStr[i] - '0';
        cArr[i] = cStr[i] - '0';
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        int profit = vArr[i] - cArr[i];
        if (profit > 0) {
            max += profit;
        }
    }
    printf("%d\n", max);
    return 0;
}

