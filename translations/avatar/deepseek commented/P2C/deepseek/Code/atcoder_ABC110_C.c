#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare the frequency counts of two strings
int compare_counts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to run the comparison
int run(const char *s, const char *t) {
    int count_s[256] = {0}; // Array to count character frequencies in s
    int count_t[256] = {0}; // Array to count character frequencies in t

    // Count the frequency of each character in s
    for (int i = 0; s[i] != '\0'; i++) {
        count_s[(unsigned char)s[i]]++;
    }

    // Count the frequency of each character in t
    for (int i = 0; t[i] != '\0'; i++) {
        count_t[(unsigned char)t[i]]++;
    }

    // Copy the counts to arrays for sorting
    int ss[256], tt[256];
    int count_index = 0;
    for (int i = 0; i < 256; i++) {
        if (count_s[i] > 0) {
            ss[count_index] = count_s[i];
            count_index++;
        }
    }
    count_index = 0;
    for (int i = 0; i < 256; i++) {
        if (count_t[i] > 0) {
            tt[count_index] = count_t[i];
            count_index++;
        }
    }

    // Sort the arrays
    qsort(ss, count_index, sizeof(int), compare_counts);
    qsort(tt, count_index, sizeof(int), compare_counts);

    // Compare the sorted arrays
    for (int i = 0; i < count_index; i++) {
        if (ss[i] != tt[i]) {
            return 0; // Return 0 if arrays are not equal
        }
    }
    return 1; // Return 1 if arrays are equal
}

// Main function to get input and print the result
int main() {
    char s[1000], t[1000];

    // Read input strings
    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    // Call the run function and print the result
    if (run(s, t)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
