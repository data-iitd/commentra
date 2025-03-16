#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000], t[1000];
    int freqs[256] = {0}, freqt[256] = {0};
    int yay = 0, whoops = 0;

    scanf("%s %s", s, t);

    for (int i = 0; i < strlen(s); i++) {
        freqs[(int)s[i]]++;
    }
    for (int i = 0; i < strlen(t); i++) {
        freqt[(int)t[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        while (freqs[i] > 0 && freqt[i] > 0) {
            yay++;
            freqs[i]--;
            freqt[i]--;
        }
    }

    for (int i = 0; i < 256; i++) {
        while (freqs[i] > 0) {
            if ((i >= 'a' && i <= 'z' && freqs[i] > 0 && freqs[i - 'a' + 'A'] > 0)) {
                whoops++;
                freqs[i]--;
                freqs[i - 'a' + 'A']--;
            } else if ((i >= 'A' && i <= 'Z' && freqs[i] > 0 && freqs[i - 'A' + 'a'] > 0)) {
                whoops++;
                freqs[i]--;
                freqs[i - 'A' + 'a']--;
            } else {
                break;
            }
        }
    }

    printf("%d %d\n", yay, whoops);
    return 0;
}
