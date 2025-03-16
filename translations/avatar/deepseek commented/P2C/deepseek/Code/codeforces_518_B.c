#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    int freqs[256] = {0}, freqt[256] = {0};
    int yay = 0, whoops = 0;

    // Taking two input strings
    scanf("%s %s", s, t);

    // Populating the frequency arrays
    for (int i = 0; i < strlen(s); i++) {
        freqs[(unsigned char)s[i]]++;
    }

    for (int i = 0; i < strlen(t); i++) {
        freqt[(unsigned char)t[i]]++;
    }

    // Counting yay by matching characters in freqs and freqt
    for (int i = 0; i < 256; i++) {
        while (freqs[i] > 0 && freqt[i] > 0) {
            yay++;
            freqs[i]--;
            freqt[i]--;
        }
    }

    // Counting whoops by transforming characters to match
    for (int i = 0; i < 256; i++) {
        while (freqs[i] > 0) {
            if ((char)i >= 'a' && (char)i <= 'z' && (char)(i - 32) >= 'A' && (char)(i - 32) <= 'Z' && freqt[(unsigned char)(i - 32)] > 0) {
                whoops++;
                freqs[i]--;
                freqt[(unsigned char)(i - 32)]--;
            } else if ((char)i >= 'A' && (char)i <= 'Z' && (char)(i + 32) >= 'a' && (char)(i + 32) <= 'z' && freqt[(unsigned char)(i + 32)] > 0) {
                whoops++;
                freqs[i]--;
                freqt[(unsigned char)(i + 32)]--;
            } else {
                break;
            }
        }
    }

    printf("%d %d\n", yay, whoops);

    return 0;
}
