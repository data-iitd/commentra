#include <stdio.h>

int main() {
    char s[100];
    int price = 700;
    int i;

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'o') {
            price += 100;
        }
    }

    printf("%d\n", price);

    return 0;
}

