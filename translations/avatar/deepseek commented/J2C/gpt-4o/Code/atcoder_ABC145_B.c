#include <stdio.h>
#include <string.h>

void cout(const char *str) {
    printf("%s\n", str);
}

int main() {
    int n;
    scanf("%d\n", &n); // Read the integer input n

    char str[100]; // Assuming the maximum length of the input string is 100
    fgets(str, sizeof(str), stdin); // Read the string input str

    char a[100] = ""; // Initialize an empty string a
    // Constructing the string a by taking the first n/2 characters of str
    for (int i = 0; i < n / 2; i++) {
        strncat(a, (char[]){str[i], '\0'}, 1); // Append one character at a time
    }

    // Checking if str is equal to a + a and printing the result
    if (strcmp(str, strcat(a, a)) == 0) {
        cout("Yes");
    } else {
        cout("No");
    }

    return 0;
}

// <END-OF-CODE>
