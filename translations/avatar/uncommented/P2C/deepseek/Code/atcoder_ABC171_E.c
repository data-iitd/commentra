#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        total ^= a[i];
    }

    char result[10000];
    result[0] = '\0';
    for (int i = 0; i < N; i++) {
        int temp = a[i] ^ total;
        char temp_str[12];
        sprintf(temp_str, "%d", temp);
        if (i == 0) {
            strcpy(result, temp_str);
        } else {
            strcat(result, " ");
            strcat(result, temp_str);
        }
    }
    printf("%s\n", result);
    return 0;
}
