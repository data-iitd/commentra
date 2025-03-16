#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    int freqs[256] = {0}, freqt[256] = {0};
    int yay = 0, whoops = 0;

    // Read two strings from input
    fgets(s, MAX_LEN, stdin);
    fgets(t, MAX_LEN, stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    // Count the frequency of each character in the first string 's'
    for (int i = 0; s[i] != '\0'; i++) {
        freqs[(unsigned char)s[i]]++;
    }

    // Count the frequency of each character in the second string 't'
    for (int i = 0; t[i] != '\0'; i++) {
        freqt[(unsigned char)t[i]]++;
    }

    // Compare character frequencies from both strings to count exact matches
    for (int i = 0; i < 256; i++) {
        if (freqs[i] > 0 && freqt[i] > 0) {
            int min = freqs[i] < freqt[i] ? freqs[i] : freqt[i];
            yay += min;
            freqs[i] -= min;
            freqt[i] -= min;
        }
    }

    // Compare remaining characters for case-insensitive matches
    for (int i = 0; i < 256; i++) {
        if (freqs[i] > 0) {
            if (i >= 'a' && i <= 'z' && freqs[i] > 0 && freqs[i - 'a' + 'A'] > 0 && freqt[i - 'a' + 'A'] > 0) {
                whoops += freqs[i] < freqs[i - 'a' + 'A'] ? freqs[i] : freqs[i - 'a' + 'A'];
                freqs[i] -= whoops;
                freqs[i - 'a' + 'A'] -= whoops;
            } else if (i >= 'A' && i <= 'Z' && freqs[i] > 0 && freqs[i - 'A' + 'a'] > 0 && freqt[i - 'A' + 'a'] > 0) {
                whoops += freqs[i] < freqs[i - 'A' + 'a'] ? freqs[i] : freqs[i - 'A' + 'a'];
                freqs[i] -= whoops;
                freqs[i - 'A' + 'a'] -= whoops;
            }
        }
    }

    // Print the results: number of exact matches and case-insensitive matches
    printf("%d %d\n", yay, whoops);

    return 0;
}
