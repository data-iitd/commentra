
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char abcd[] = "abcdefghijklmnopqrstuvwxyz";
const char ABCD[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int main() {
    char N[10000];
    scanf("%s", N);
    int n = 0;
    for (int i = 0; N[i]!= '\0'; i++) {
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
