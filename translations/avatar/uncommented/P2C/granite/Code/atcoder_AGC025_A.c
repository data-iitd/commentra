
#include <stdio.h>
#include <string.h>

int main() {
    char n[100];
    scanf("%s", n);
    int a[] = { 10, 100, 1000, 10000, 100000 };
    int new = 0;
    for (int i = 0; i < strlen(n); i++) {
        new += n[i] - '0';
    }
    int flag = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("10\n");
    } else {
        printf("%d\n", new);
    }
    return 0;
}
// END-OF-CODE