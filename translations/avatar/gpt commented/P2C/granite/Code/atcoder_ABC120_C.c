
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read input string
    char s[100001];
    fgets(s, 100001, stdin);

    // Remove the trailing newline character
    s[strcspn(s, "\n")] = 0;

    // Check if all characters in the string are the same
    if (strlen(s) == 1 || strlen(s) == strnlen(s, 100000)) {
        printf("0\n");  // If true, print 0 and exit
        return 0;
    }

    // Count the occurrences of each character in the string
    int a[256] = {0};
    for (int i = 0; s[i]!= '\0'; i++) {
        a[s[i]]++;
    }

    // Calculate the answer as twice the minimum frequency of any character
    int ans = 100000000;
    for (int i = 0; i < 256; i++) {
        if (a[i] > 0) {
            ans = ans < a[i]? ans : a[i];
        }
    }
    ans *= 2;

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

