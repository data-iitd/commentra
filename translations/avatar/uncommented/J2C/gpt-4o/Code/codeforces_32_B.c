#include <stdio.h>
#include <stdbool.h>

int main() {
    char n[100]; // Assuming a maximum length of 100 for the input
    scanf("%s", n);
    bool s = false;

    for (int i = 0; n[i] != '\0'; i++) {
        if (n[i] == '.') {
            if (s) {
                printf("1");
                s = false;
            } else {
                printf("0");
            }
        } else {
            if (s) {
                printf("2");
                s = false;
            } else {
                s = true;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
