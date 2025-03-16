#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

int main() {
    // We start by defining two arrays to store the frequency of each character in the strings s and t respectively
    int freqs[MAX_CHAR] = {0};
    int freqt[MAX_CHAR] = {0};

    // We read the two strings s and t from the user input
    char s[100], t[100];
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);

    // Remove newline characters from the input strings
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    // We iterate through each character in the string s and update the frequency count in the freqs array
    for (int i = 0; s[i] != '\0'; i++) {
        freqs[(unsigned char)s[i]]++;
    }

    // We iterate through each character in the string t and update the frequency count in the freqt array
    for (int i = 0; t[i] != '\0'; i++) {
        freqt[(unsigned char)t[i]]++;
    }

    // We initialize two counters, yay and whoops, to zero
    int yay = 0, whoops = 0;

    // We iterate through each character in the freqs array and check if its frequency is greater than zero
    for (int i = 0; i < MAX_CHAR; i++) {
        while (freqs[i] > 0 && freqt[i] > 0) {
            yay++;
            freqs[i]--;
            freqt[i]--;
        }
    }

    // We iterate through each character in the freqs array again
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

    // Finally, we print the values of yay and whoops
    printf("%d %d\n", yay, whoops);

    return 0;
}

// <END-OF-CODE>
