#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define IO_BUFFER_SIZE 1 * 1024 * 1024

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    int h = nextInt();
    int n = nextInt();
    int a = 0;

    for (int i = 0; i < n; i++) {
        a += nextInt();
    }

    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
