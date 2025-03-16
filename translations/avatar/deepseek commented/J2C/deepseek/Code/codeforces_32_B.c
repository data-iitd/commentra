#include <stdio.h>
#include <stdlib.h>

int main() {
    char n[100];
    int s = 0;

    // Read the input string
    scanf("%s", n);

    // Process each character in the character array
    for (int i = 0; n[i] != '\0'; i++) {
        if (n[i] == '.') {
            if (s) {
                printf("1");
                s = 0;
            } else {
                printf("0");
                s = 0;
            }
        } else {
            if (s) {
                printf("2");
                s = 0;
            } else {
                s = 1;
            }
        }
    }
    printf("\n");
    return 0;
}
