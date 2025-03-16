#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Function to count character frequencies and return a sorted frequency array
int* get_frequency_sorted(const char* str, int* size) {
    int* freq = (int*)calloc(MAX_CHAR, sizeof(int));
    int count = 0;

    // Count frequencies
    for (const char* p = str; *p != '\0'; p++) {
        freq[(unsigned char)*p]++;
    }

    // Count non-zero frequencies
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            count++;
        }
    }

    // Create a sorted frequency array
    int* sorted_freq = (int*)malloc(count * sizeof(int));
    int index = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            sorted_freq[index++] = freq[i];
        }
    }

    // Sort the frequency array
    qsort(sorted_freq, count, sizeof(int), (int(*)(const void*, const void*))strcmp);

    *size = count;
    free(freq);
    return sorted_freq;
}

// Function to compare the frequency distributions of two strings
const char* run(const char* s, const char* t) {
    int size_s, size_t;
    int* ss = get_frequency_sorted(s, &size_s);
    int* tt = get_frequency_sorted(t, &size_t);

    // Compare sizes first
    if (size_s != size_t) {
        free(ss);
        free(tt);
        return "No";
    }

    // Compare sorted frequency arrays
    for (int i = 0; i < size_s; i++) {
        if (ss[i] != tt[i]) {
            free(ss);
            free(tt);
            return "No";
        }
    }

    free(ss);
    free(tt);
    return "Yes";
}

int main() {
    char s[1000], t[1000];

    // Read input strings s and t from the user
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);

    // Remove newline characters from the input
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    // Print the result of the run function which checks the character frequency
    printf("%s\n", run(s, t));

    return 0;
}

// <END-OF-CODE>
