#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    int freqs[256] = {0}, freqt[256] = {0};
    int yay = 0, whoops = 0;
    int i;

    // Read the two strings s and t from the user input
    fgets(s, MAX_LEN, stdin);
    fgets(t, MAX_LEN, stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    // Update the frequency count in the freqs array for string s
    for (i = 0; i < strlen(s); i++) {
        freqs[(unsigned char)s[i]]++;
    }

    // Update the frequency count in the freqt array for string t
    for (i = 0; i < strlen(t); i++) {
        freqt[(unsigned char)t[i]]++;
    }

    // Count yay pairs
    for (i = 0; i < 256; i++) {
        if (freqs[i] > 0 && freqt[i] > 0) {
            int min = freqs[i] < freqt[i] ? freqs[i] : freqt[i];
            yay += min;
            freqs[i] -= min;
            freqt[i] -= min;
        }
    }

    // Count whoops pairs
    for (i = 0; i < 256; i++) {
        if (freqs[i] > 0) {
            if (i >= 'a' && i <= 'z' && freqt[i - 'a' + 'A'] > 0) {
                whoops += 1;
                freqs[i] -= 1;
                freqt[i - 'a' + 'A'] -= 1;
            } else if (i >= 'A' && i <= 'Z' && freqt[i - 'A' + 'a'] > 0) {
                whoops += 1;
                freqs[i] -= 1;
                freqt[i - 'A' + 'a'] -= 1;
            }
        }
    }

    // Print the values of yay and whoops
    printf("%d %d\n", yay, whoops);

    return 0;
}
