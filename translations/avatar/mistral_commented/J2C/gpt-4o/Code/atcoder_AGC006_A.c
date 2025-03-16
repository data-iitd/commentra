#include <stdio.h>
#include <string.h>

#define N 210  // Size of the arrays

int f[N];  // Failure function array
char b[N];  // Character array

void getFail(char b[], int m) {
    int j = 0;
    f[0] = f[1] = 0;  // Initializing the first two elements of the failure function array

    // Main logic of the function
    for (int i = 2; i <= m; i++) {
        while (j > 0 && b[j + 1] != b[i]) {
            j = f[j];  // Searching for the longest common prefix
        }
        if (b[j + 1] == b[i]) {
            j++;  // If the characters match, move to the next character
        }
        f[i] = j;  // Updating the failure function for the current index
    }
}

int main() {
    int n;
    scanf("%d", &n);  // Reading the number of characters in the strings

    char s1[N], str[N];
    scanf("%s %s", str, s1);  // Reading the two strings

    int cnt = 0;  // Counter for the number of characters in the combined string

    // Concatenating the two strings into the character array
    for (int i = 0; i < n; i++) {
        b[++cnt] = str[i];
    }
    for (int i = 0; i < n; i++) {
        b[++cnt] = s1[i];
    }

    getFail(b, cnt);  // Calling the getFail function to compute the failure function

    int len = f[cnt] < n ? f[cnt] : n;  // Computing the length of the longest common prefix

    printf("%d\n", 2 * n - len);  // Writing the output to the console

    return 0;  // End of the program
}

// <END-OF-CODE>
