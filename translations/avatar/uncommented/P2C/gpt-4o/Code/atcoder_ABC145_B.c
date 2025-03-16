#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[100]; // Assuming the maximum length of the string is 100
    scanf("%s", s);

    if (n % 2 != 0) {
        printf("No\n");
    } else {
        int half = n / 2;
        if (strncmp(s, s + half, half) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
