#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define INF 2147483647

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int main() {
    char N[1000];
    scanf("%s", N);
    int n = 0;
    int len = strlen(N);

    for (int i = 0; i < len; i++) {
        n += N[i] - '0';
    }

    int m = atoi(N);
    if (m % n == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
