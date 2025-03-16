#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int n, ans = 0;

    // Take the input string 's' and an integer 'n' from the user
    scanf("%s", s);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char x[3];
        int a = 0, b = 0;

        // Take the next string 'x' as input
        scanf("%s", x);

        // Iterate through each character 'j' in the string 's'
        for (int j = 0; s[j] != '\0'; j++) {
            // If the character 'j' matches the first character of the string 'x', increment 'a'
            if (s[j] == x[0]) {
                a++;
            }
            // If the character 'j' matches the second character of the string 'x', increment 'b'
            else if (s[j] == x[1]) {
                b++;
            }
            // If the current character 'j' does not match any character in the string 'x',
            // add the minimum of 'a' and 'b' to the answer variable 'ans' and reset 'a' and 'b' to 0
            else {
                ans += (a < b) ? a : b;
                a = 0;
                b = 0;
            }
        }

        // Add the minimum of 'a' and 'b' to the answer variable 'ans' after the inner loop completes
        ans += (a < b) ? a : b;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
