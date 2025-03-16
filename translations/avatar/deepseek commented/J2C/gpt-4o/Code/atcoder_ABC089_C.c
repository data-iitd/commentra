#include <stdio.h>
#include <string.h>

int main() {
    int n;
    long cnt[5] = {0}; // Initialize count array to zero

    scanf("%d", &n); // Read the number of strings

    for (int i = 0; i < n; ++i) {
        char str[100]; // Assuming the maximum length of the string is 99
        scanf("%s", str); // Read the string

        // Count the occurrences of each character at the start of the strings
        if (str[0] == 'M') {
            cnt[0]++;
        } else if (str[0] == 'A') {
            cnt[1]++;
        } else if (str[0] == 'R') {
            cnt[2]++;
        } else if (str[0] == 'C') {
            cnt[3]++;
        } else if (str[0] == 'H') {
            cnt[4]++;
        }
    }

    // Calculate the number of combinations
    long res = cnt[0] * cnt[1] * cnt[2] +
               cnt[0] * cnt[1] * cnt[3] +
               cnt[0] * cnt[1] * cnt[4] +
               cnt[0] * cnt[2] * cnt[3] +
               cnt[0] * cnt[2] * cnt[4] +
               cnt[0] * cnt[3] * cnt[4] +
               cnt[1] * cnt[2] * cnt[3] +
               cnt[1] * cnt[2] * cnt[4] +
               cnt[1] * cnt[3] * cnt[4] +
               cnt[2] * cnt[3] * cnt[4];

    printf("%ld\n", res); // Print the result

    return 0;
}

// <END-OF-CODE>
