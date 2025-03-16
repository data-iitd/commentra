#include <stdio.h>

int main() {
    int n;
    char s[100];

    // Reading input from the user
    scanf("%d %s", &n, s);

    // Variable declaration and initialization for maximum count and current count
    int max = 0;
    int cnt = 0;

    // Iterating through each character in the string 's'
    for (int i = 0; s[i] != '\0'; i++) {
        // Checking if the character is 'I'
        if (s[i] == 'I') {
            // Incrementing the current count
            cnt++;
        } else {
            // Decrementing the current count
            cnt--;
        }

        // Updating the maximum count if the current count is greater
        if (cnt > max) {
            max = cnt
        }
    }

    // Printing the maximum count
    printf("%d\n", max);

    // End of the code
    return 0;
}
