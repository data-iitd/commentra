
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100001], t[100001];
    int freqs[256] = {0}, freqt[256] = {0};
    int yay = 0, whoops = 0;

    // Read two strings from input
    scanf("%s", s);
    scanf("%s", t);

    // Count the frequency of each character in the first string's'
    for (int i = 0; s[i]!= '\0'; i++) {
        freqs[(int)s[i]]++;
    }

    // Count the frequency of each character in the second string 't'
    for (int i = 0; t[i]!= '\0'; i++) {
        freqt[(int)t[i]]++;
    }

    // Compare character frequencies from both strings to count exact matches
    for (int i = 0; i < 256; i++) {
        while (freqs[i] > 0 && freqt[i] > 0) {
            yay++;  // Increment the count of exact matches
            freqs[i]--;  // Decrease the count in the first string
            freqt[i]--;  // Decrease the count in the second string
        }
    }

    // Compare remaining characters for case-insensitive matches
    for (int i = 0; i < 256; i++) {
        while (freqs[i] > 0) {
            // Check for a lowercase letter in's' and its uppercase counterpart in 't'
            if (islower(i) && freqt[toupper(i)] > 0) {
                whoops++;  // Increment the count of case-insensitive matches
                freqs[i]--;  // Decrease the count in the first string
                freqt[toupper(i)]--;  // Decrease the count in the second string
            }
            // Check for an uppercase letter in's' and its lowercase counterpart in 't'
            else if (isupper(i) && freqt[tolower(i)] > 0) {
                whoops++;  // Increment the count of case-insensitive matches
                freqs[i]--;  // Decrease the count in the first string
                freqt[tolower(i)]--;  // Decrease the count in the second string
            }
            else {
                break;  // Exit the loop if no more matches can be found
            }
        }
    }

    // Print the results: number of exact matches and case-insensitive matches
    printf("%d %d\n", yay, whoops);

    return 0;
}
