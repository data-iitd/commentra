
#include <stdio.h>
#include <string.h>

int main() {
    // Take an integer 'n' as input
    int n;
    scanf("%d", &n);

    // Take two strings's' and 't' of length 'n' as input
    char s[n], t[n];
    scanf("%s", s);
    scanf("%s", t);

    // Check if both strings's' and 't' are equal or not
    if (strcmp(s, t) == 0) {
        // If they are equal, print the value of 'n'
        printf("%d\n", n);
    } else {
        // Initialize a counter 'cnt' to store the length of the longest common substring
        int cnt = 0;

        // Iterate through all possible substrings of's' starting from the first character
        for (int i = 0; i < n; i++) {
            // Iterate through all possible substrings of 't' starting from the first character
            for (int j = 0; j < n - i; j++) {
                // Check if the substring of's' starting from index 'i+j' is equal to the substring of 't' starting from index 'j'
                if (s[i + j]!= t[j]) {
                    // If they are not equal, break the inner loop and move to the next substring of's'
                    break;
                }

                // If they are equal and we have reached the end of the substring of's', update the value of 'cnt'
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }

        // If's' and 't' have no common substring, 'cnt' will be 0. In that case, print 2*n
        printf("%d\n", 2 * n - cnt);
    }

    return 0;
}
