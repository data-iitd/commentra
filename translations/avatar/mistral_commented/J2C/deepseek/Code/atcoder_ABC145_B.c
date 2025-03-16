#include <stdio.h>
#include <string.h>

void cout(char* str) {
    printf("%s\n", str);
}

int main() {
    char a[1000] = "", b[1000] = "", str[1000];
    int n;

    scanf("%d", &n);
    getchar(); // Consuming the newline character left after reading an integer value

    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing the newline character at the end of the string

    for (int i = 0; i < n / 2; i++) {
        a[i] = str[i];
    }
    a[n / 2] = '\0'; // Null-terminating the string a

    if (strcmp(str, strcat(a, a)) == 0) {
        cout("Yes");
    } else {
        cout("No");
    }

    return 0;
}

