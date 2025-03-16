#include <stdio.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);

    int price = 700;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'o') {
            price += 100;
        }
    }
    printf("%d\n", price);
    return 0;
}

// <END-OF-CODE>
