#include <stdio.h>
#include <string.h>

void cout(char* str) {
    printf("%s\n", str);
}

int main() {
    int n;
    char str[1000], a[500], b[500];

    // Reading the integer input n
    scanf("%d", &n);
    getchar(); // Consume the newline character after the integer input

    // Reading the string input str
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character from fgets

    // Constructing the string a by taking the first n/2 characters of str
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        a[i] = str[i];
    }
    a[len / 2] = '\0'; // Null-terminate the string a

    // Checking if str is equal to a + a and printing the result
    if (strcmp(str, strncat(a, a, len / 2)) == 0) {
        cout("Yes");
    } else {
        cout("No");
    }

    return 0;
}
