#include <stdio.h>
#include <string.h>

void cout(char* str) {
    printf("%s\n", str);
}

int main() {
    int n;
    char a[1000] = "", b[1000] = "", str[1000];
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer input
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character from fgets
    for (int i = 0; i < n / 2; i++) {
        a[i] = str[i];
    }
    a[n / 2] = '\0'; // Null-terminate the string a
    if (strcmp(str, strncat(a, a, n / 2)) == 0) {
        cout("Yes");
    } else {
        cout("No");
    }
    return 0;
}
