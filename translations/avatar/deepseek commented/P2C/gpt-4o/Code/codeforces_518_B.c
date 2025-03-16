#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

int main() {
    char s[MAX_CHAR], t[MAX_CHAR];
    int freqs[MAX_CHAR] = {0};  // Frequency array for characters in s
    int freqt[MAX_CHAR] = {0};  // Frequency array for characters in t
    int yay = 0, whoops = 0;    // Initializing counters for yay and whoops

    // Taking two input strings
    fgets(s, MAX_CHAR, stdin);
    fgets(t, MAX_CHAR, stdin);

    // Removing newline characters from the input
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    // Populating the frequency arrays
    for (int i = 0; s[i] != '\0'; i++) {
        freqs[(unsigned char)s[i]]++;  // Incrementing the count for character in s
    }

    for (int i = 0; t[i] != '\0'; i++) {
        freqt[(unsigned char)t[i]]++;  // Incrementing the count for character in t
    }

    // Counting yay by matching characters in freqs and freqt
    for (int i = 0; i < MAX_CHAR; i++) {
        while (freqs[i] > 0 && freqt[i] > 0) {
            yay++;  // Incrementing yay if characters match
            freqs[i]--;  // Decrementing the count in freqs
            freqt[i]--;  // Decrementing the count in freqt
        }
    }

    // Counting whoops by transforming characters to match
    for (int i = 0; i < MAX_CHAR; i++) {
        while (freqs[i] > 0) {
            if (islower(i) && freqt[toupper(i)] > 0) {
                whoops++;  // Incrementing whoops if transformation is possible
                freqs[i]--;  // Decrementing the count in freqs
                freqt[toupper(i)]--;  // Decrementing the count in freqt
            } else if (isupper(i) && freqt[tolower(i)] > 0) {
                whoops++;  // Incrementing whoops if transformation is possible
                freqs[i]--;  // Decrementing the count in freqs
                freqt[tolower(i)]--;  // Decrementing the count in freqt
            } else {
                break;  // Breaking the loop if no more transformations are possible
            }
        }
    }

    printf("%d %d\n", yay, whoops);  // Printing the final counts of yay and whoops

    return 0;
}

// <END-OF-CODE>
