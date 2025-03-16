
#include <stdio.h>
#include <string.h>

int main () {
    // We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
    int freqs [256] = {0}, freqt [256] = {0};

    // We read the two strings s and t from the user input
    char s [1000], t [1000];
    scanf ("%s", s);
    scanf ("%s", t);

    // We iterate through each character in the string s and update the frequency count in the freqs array
    for (int i = 0; s [i]!= '\0'; i++) {
        freqs [(int) s [i]]++;
    }

    // We iterate through each character in the string t and update the frequency count in the freqt array
    for (int i = 0; t [i]!= '\0'; i++) {
        freqt [(int) t [i]]++;
    }

    // We initialize two counters, yay and whoops, to zero
    int yay = 0, whoops = 0;

    // We iterate through each character in the freqs array and check if its frequency is greater than zero and if it is present in the freqt array with a frequency greater than zero. If both conditions are true, we increment the yay counter
    for (int i = 0; i < 256; i++) {
        while (freqs [i] > 0 && freqt [i] > 0) {
            yay++;
            freqs [i]--;
            freqt [i]--;
        }
    }

    // We iterate through each character in the freqs array again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt array with a frequency greater than zero or if its uppercase version is present in the freqt array with a frequency greater than zero. If either condition is true, we increment the whoops counter
    for (int i = 0; i < 256; i++) {
        while (freqs [i] > 0) {
            if (i >= 65 && i <= 90 && freqt [i + 32] > 0) {
                whoops++;
                freqs [i]--;
                freqt [i + 32]--;
            } else if (i >= 97 && i <= 122 && freqt [i - 32] > 0) {
                whoops++;
                freqs [i]--;
                freqt [i - 32]--;
            } else {
                break;
            }
        }
    }

    // Finally, we print the values of yay and whoops
    printf ("%d %d\n", yay, whoops);

    return 0;
}
