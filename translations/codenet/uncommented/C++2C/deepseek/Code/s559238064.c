#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char z[100];
    int a;
    bool bad = false;

    scanf("%s", z);
    a = strlen(z);

    for (int i = 0; i < a - 1; i++) {
        if (z[i] == z[i + 1]) {
            bad = true;
            break;
        }
    }

    if (bad) {
        printf("Bad\n");
    } else {
        printf("Good\n");
    }

    return 0;
}
