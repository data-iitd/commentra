
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %d", &n, &k);
    if (n % k == 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    return 0;
}
