#include <stdio.h>
#include <string.h>

void cout(const char *str) {
    printf("%s\n", str);
}

int main() {
    char str[100]; // Assuming a maximum length of 100 for the input string
    char a[50];   // To store the first half of the string
    int n;

    scanf("%d", &n);
    getchar(); // To consume the newline character after the integer input
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character from the string

    a[0] = '\0'; // Initialize 'a' as an empty string

    for (int i = 0; i < n / 2; i++) {
        strncat(a, (char[]){str[i], '\0'}, 1); // Append one character at a time
    }

    if (strcmp(str, strcat(a, a)) == 0) {
        cout("Yes");
    } else {
        cout("No");
    }

    return 0;
}
