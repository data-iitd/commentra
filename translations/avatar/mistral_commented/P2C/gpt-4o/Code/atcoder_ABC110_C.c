#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two frequency arrays
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b;
}

// Function to count character frequencies and check if they are the same
const char* run(const char* s, const char* t) {
    int countS[256] = {0}; // Array to count frequencies of characters in s
    int countT[256] = {0}; // Array to count frequencies of characters in t

    // Count frequencies of characters in string s
    for (int i = 0; s[i] != '\0'; i++) {
        countS[(unsigned char)s[i]]++;
    }

    // Count frequencies of characters in string t
    for (int i = 0; t[i] != '\0'; i++) {
        countT[(unsigned char)t[i]]++;
    }

    // Create arrays to hold the frequency counts
    int freqS[256], freqT[256];
    int sizeS = 0, sizeT = 0;

    // Fill freqS with non-zero counts from countS
    for (int i = 0; i < 256; i++) {
        if (countS[i] > 0) {
            freqS[sizeS++] = countS[i];
        }
    }

    // Fill freqT with non-zero counts from countT
    for (int i = 0; i < 256; i++) {
        if (countT[i] > 0) {
            freqT[sizeT++] = countT[i];
        }
    }

    // Sort the frequency arrays
    qsort(freqS, sizeS, sizeof(int), compare);
    qsort(freqT, sizeT, sizeof(int), compare);

    // Compare the sorted frequency arrays
    if (sizeS == sizeT) {
        for (int i = 0; i < sizeS; i++) {
            if (freqS[i] != freqT[i]) {
                return "No";
            }
        }
        return "Yes";
    } else {
        return "No";
    }
}

// Main function
int main() {
    char s[1000], t[1000];

    // Taking input strings s and t from the user
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);

    // Remove newline characters from the input strings
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    // Calling the run function with strings s and t as arguments and printing the result
    printf("%s\n", run(s, t));

    return 0;
}

// <END-OF-CODE>
