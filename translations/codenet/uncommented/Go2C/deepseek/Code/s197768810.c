#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

double readFloat64() {
    double num;
    scanf("%lf", &num);
    return num;
}

char* readString() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

int main() {
    int n = readInt();
    int m = readInt();
    int a[m];
    int sum = 0;
    for (int i = 0; i < m; i++) {
        a[i] = readInt();
        sum += a[i];
    }
    if (sum > n) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", n - sum);
    return 0;
}
