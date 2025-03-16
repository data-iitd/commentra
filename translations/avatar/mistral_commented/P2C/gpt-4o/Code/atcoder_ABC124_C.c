#include <stdio.h>
#include <string.h>

int main() {
    // Initialize an array to hold the input string
    char s[100]; // Assuming a maximum length of 100 for simplicity
    scanf("%s", s); // Take input from the user

    int len = strlen(s);
    int even0 = 0, even1 = 0, odd0 = 0, odd1 = 0;

    // Count the frequency of '0' and '1' in the first half and second half of the string
    for (int i = 0; i < len / 2; i++) {
        if (s[i] == '0') {
            even0++;
        } else if (s[i] == '1') {
            even1++;
        }
    }

    for (int i = len / 2; i < len; i++) {
        if (s[i] == '0') {
            odd0++;
        } else if (s[i] == '1') {
            odd1++;
        }
    }

    // Calculate the minimum difference
    int result1 = len - (even0 + odd1);
    int result2 = len - (even1 + odd0);
    int min_result = result1 < result2 ? result1 : result2;

    // Print the result
    printf("%d\n", min_result);

    return 0;
}

// <END-OF-CODE>
