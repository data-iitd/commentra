
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the occurrences of each character in a string
int *count_characters(char *str) {
    int *counts = (int *)malloc(256 * sizeof(int));
    memset(counts, 0, 256 * sizeof(int));

    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        counts[str[i]]++;
    }

    return counts;
}

// Function to compare two arrays of integers
int arrays_equal(int *arr1, int *arr2, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr1[i]!= arr2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if two strings have the same frequency distribution of characters
char *run(char *s, char *t) {
    int *s_counts = count_characters(s);
    int *t_counts = count_characters(t);

    int *sorted_s_counts = (int *)malloc(256 * sizeof(int));
    memcpy(sorted_s_counts, s_counts, 256 * sizeof(int));
    qsort(sorted_s_counts, 256, sizeof(int), compare_int);

    int *sorted_t_counts = (int *)malloc(256 * sizeof(int));
    memcpy(sorted_t_counts, t_counts, 256 * sizeof(int));
    qsort(sorted_t_counts, 256, sizeof(int), compare_int);

    if (arrays_equal(sorted_s_counts, sorted_t_counts, 256)) {
        return "Yes";
    } else {
        return "No";
    }
}

// Function to compare two integers
int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Main function to take input strings and call the 'run' function
int main() {
    char s[1000];
    char t[1000];

    scanf("%s", s);
    scanf("%s", t);

    char *result = run(s, t);
    printf("%s\n", result);

    return 0;
}

// End of code