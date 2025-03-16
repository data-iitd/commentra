#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

// Function to check if a string is in the set
bool contains(char **set, int size, const char *str) {
    for (int i = 0; i < size; i++) {
        if (strcmp(set[i], str) == 0) {
            return true;
        }
    }
    return false;
}

// Function to add a string to the set if it's not already present
void add_to_set(char ***set, int *size, const char *str) {
    if (!contains(*set, *size, str)) {
        *set = realloc(*set, (*size + 1) * sizeof(char *));
        (*set)[*size] = strdup(str);
        (*size)++;
    }
}

// Main function starts here
int main() {
    int n; // number of strings to be processed

    // Read the number of strings from the standard input
    scanf("%d", &n);

    // Iterate through each string
    rep(i, n) {
        char s[1001]; // string to be processed (assuming max length of 1000)
        // Read the string from the standard input
        scanf("%s", s);

        // Create an empty set to store unique substrings
        char **st = NULL;
        int st_size = 0;

        // Process each substring of the string
        REP(j, 1, strlen(s) + 1) {
            // Create substrings
            char res[1001] = {0};
            char res2[1001] = {0};

            // Get the first j characters
            strncpy(res, s, j);
            res[j] = '\0';

            // Get the remaining characters
            strncpy(res2, s + j, strlen(s) - j);
            res2[strlen(s) - j] = '\0';

            // Create two temporary strings by reversing the substrings
            char t[1001], t2[1001];
            strcpy(t, res);
            strrev(t); // Reverse the first substring
            strcpy(t2, res2);
            strrev(t2); // Reverse the second substring

            // Insert all possible combinations of the substrings and their reversed versions into the set
            add_to_set(&st, &st_size, strcat(t, t2));
            add_to_set(&st, &st_size, strcat(t2, t));
            add_to_set(&st, &st_size, strcat(res, res2));
            add_to_set(&st, &st_size, strcat(res2, res));
            add_to_set(&st, &st_size, strcat(t, res2));
            add_to_set(&st, &st_size, strcat(res2, t));
            add_to_set(&st, &st_size, strcat(res, t2));
            add_to_set(&st, &st_size, strcat(t2, res));
        }

        // Print the size of the set, which represents the number of unique substrings
        printf("%d\n", st_size);

        // Free allocated memory for the set
        for (int k = 0; k < st_size; k++) {
            free(st[k]);
        }
        free(st);
    }

    // Main function ends here
    return 0;
}

// Function to reverse a string
void strrev(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

