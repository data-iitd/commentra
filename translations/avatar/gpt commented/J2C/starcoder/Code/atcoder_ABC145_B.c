#include <stdio.h>
#include <string.h>

int main() {
    char str[100000], a[100000];
    int n;

    scanf("%d", &n);
    scanf("%s", str);

    for (int i = 0; i < n / 2; i++) {
        a[i] = str[i];
    }

    if (strcmp(str, a) == 0) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}

