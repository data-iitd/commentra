#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Function to count the frequency of characters in a string
void countFrequency(const char *str, int *freq) {
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
}

// Function to compare two frequency arrays
int compareFrequencies(int *freq1, int *freq2) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq1[i] != freq2[i]) {
            return 0; // Not equal
        }
    }
    return 1; // Equal
}

const char* run(const char *s, const char *t) {
    int freqS[MAX_CHAR] = {0};
    int freqT[MAX_CHAR] = {0};

    countFrequency(s, freqS);
    countFrequency(t, freqT);

    if (compareFrequencies(freqS, freqT)) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    char s[1001]; // Assuming the maximum length of the input string is 1000
    char t[1001];

    // Read input strings
    scanf("%1000s", s);
    scanf("%1000s", t);

    // Print the result of the run function
    printf("%s\n", run(s, t));

    return 0;
}

// <END-OF-CODE>
