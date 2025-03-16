#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

int main() {
    char s[MAX_CHAR], t[MAX_CHAR];
    int freqs[MAX_CHAR] = {0}, freqt[MAX_CHAR] = {0};
    int yay = 0, whoops = 0;

    // Read input strings
    fgets(s, MAX_CHAR, stdin);
    fgets(t, MAX_CHAR, stdin);

    // Remove newline characters if present
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    // Count frequency of characters in s
    for (int i = 0; s[i] != '\0'; i++) {
        freqs[(unsigned char)s[i]]++;
    }

    // Count frequency of characters in t
    for (int i = 0; t[i] != '\0'; i++) {
        freqt[(unsigned char)t[i]]++;
    }

    // Count matches for yay
    for (int i = 0; i < MAX_CHAR; i++) {
        while (freqs[i] > 0 && freqt[i] > 0) {
            yay++;
            freqs[i]--;
            freqt[i]--;
        }
    }

    // Count matches for whoops
    for (int i = 0; i < MAX_CHAR; i++) {
        while (freqs[i] > 0) {
            if (islower(i) && freqt[toupper(i)] > 0) {
                whoops++;
                freqs[i]--;
                freqt[toupper(i)]--;
            } else if (isupper(i) && freqt[tolower(i)] > 0) {
                whoops++;
                freqs[i]--;
                freqt[tolower(i)]--;
            } else {
                break;
            }
        }
    }

    // Print results
    printf("%d %d\n", yay, whoops);

    return 0;
}

// <END-OF-CODE>
