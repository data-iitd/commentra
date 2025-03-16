#include <stdio.h>
#include <string.h>

int main() {
    char n[100];
    int i;

    scanf("%s", n);

    for (i = 0; i < 3; i++) {
        if (n[i] == '7') {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}

