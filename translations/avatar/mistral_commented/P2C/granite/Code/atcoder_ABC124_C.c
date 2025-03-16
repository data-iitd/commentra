
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an empty list's' by taking input from the user
    char s[100000];
    scanf("%s", s);

    // Create two dictionaries 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the list's' respectively
    int even[2] = {0}, odd[2] = {0};
    for (int i = 0; i < strlen(s); i++) {
        if (i < strlen(s) / 2) {
            even[s[i] - '0']++;
        } else {
            odd[s[i] - '0']++;
        }
    }

    // Print the minimum difference between the length of the list's' and the sum of the frequencies of '0' and '1' in either half of the list
    printf("%d", fmin(strlen(s) - (even[0] + odd[1]), strlen(s) - (even[1] + odd[0])));

    return 0;
}
