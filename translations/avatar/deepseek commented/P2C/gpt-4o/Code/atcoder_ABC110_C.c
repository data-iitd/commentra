#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b;
}

// Function to count character frequencies
void countFrequencies(const char *str, int *freq) {
    while (*str) {
        freq[*str - 'a']++;
        str++;
    }
}

// Function to check if two strings have the same character frequency
const char* run(const char *s, const char *t) {
    int freqS[26] = {0}; // Frequency array for string s
    int freqT[26] = {0}; // Frequency array for string t

    countFrequencies(s, freqS);
    countFrequencies(t, freqT);

    // Create arrays to hold the frequency counts
    int countS[26] = {0};
    int countT[26] = {0};

    for (int i = 0; i < 26; i++) {
        if (freqS[i] > 0) countS[freqS[i]]++;
        if (freqT[i] > 0) countT[freqT[i]]++;
    }

    // Sort the frequency counts
    qsort(countS, 26, sizeof(int), compare);
    qsort(countT, 26, sizeof(int), compare);

    // Compare the sorted frequency counts
    for (int i = 0; i < 26; i++) {
        if (countS[i] != countT[i]) {
            return "No";
        }
    }
    return "Yes";
}

int main() {
    char s[100], t[100];
    // Get input for s from the user
    scanf("%s", s);
    // Get input for t from the user
    scanf("%s", t);
    // Call the run function with s and t as arguments and print the result
    printf("%s\n", run(s, t));
    return 0;
}

// <END-OF-CODE>
