#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100], t[100];
    int i, j, yay = 0, whoops = 0;
    int freqs[26] = {0}, freqt[26] = {0};

    // Read two strings from input
    scanf("%s", s);
    scanf("%s", t);

    // Count the frequency of each character in the first string 's'
    for (i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            freqs[tolower(s[i]) - 'a']++;
        }
    }

    // Count the frequency of each character in the second string 't'
    for (i = 0; i < strlen(t); i++) {
        if (isalpha(t[i])) {
            freqt[tolower(t[i]) - 'a']++;
        }
    }

    // Compare character frequencies from both strings to count exact matches
    for (i = 0; i < 26; i++) {
        while (freqs[i] > 0 && freqt[i] > 0) {
            yay++;
            freqs[i]--;
            freqt[i]--;
        }
    }

    // Compare remaining characters for case-insensitive matches
    for (i = 0; i < 26; i++) {
        while (freqs[i] > 0) {
            if (islower(i + 'a') && isupper(i + 'a') && freqt[toupper(i + 'a') - 'A'] > 0) {
                whoops++;
                freqs[i]--;
                freqt[toupper(i + 'a') - 'A']--;
            } else if (isupper(i + 'a') && islower(i + 'a') && freqt[tolower(i + 'a') - 'a'] > 0) {
                whoops++;
                freqs[i]--;
                freqt[tolower(i + 'a') - 'a']--;
            } else {
                break;
            }
        }
    }

    // Print the results: number of exact matches and case-insensitive matches
    printf("%d %d\n", yay, whoops);

    return 0;
}

