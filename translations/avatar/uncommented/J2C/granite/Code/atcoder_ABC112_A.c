
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 0;
    char buf[1024] = {0};
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);
    if (n == 1) {
        printf("Hello World\n");
    } else {
        char buf1[1024] = {0};
        char buf2[1024] = {0};
        fgets(buf1, sizeof(buf1), stdin);
        fgets(buf2, sizeof(buf2), stdin);
        int a = 0, b = 0;
        sscanf(buf1, "%d", &a);
        sscanf(buf2, "%d", &b);
        printf("%d\n", a + b);
    }
    return 0;
}

