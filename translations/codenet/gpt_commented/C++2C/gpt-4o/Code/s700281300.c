#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100
#define MAX_UNIQUE_COMBINATIONS 10000

// Function to check if a string is in the set of unique combinations
bool is_in_set(char set[][MAX_STRING_LENGTH], int count, const char *str) {
    for (int i = 0; i < count; i++) {
        if (strcmp(set[i], str) == 0) {
            return true;
        }
    }
    return false;
}

// Function to add a string to the set of unique combinations
void add_to_set(char set[][MAX_STRING_LENGTH], int *count, const char *str) {
    if (!is_in_set(set, *count, str)) {
        strcpy(set[*count], str);
        (*count)++;
    }
}

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Process each test case
    for (int i = 0; i < n; i++) {
        char s[MAX_STRING_LENGTH];
        // Read the string for the current test case
        scanf("%s", s);

        // Initialize a set to store unique combinations of strings
        char unique_combinations[MAX_UNIQUE_COMBINATIONS][MAX_STRING_LENGTH];
        int count = 0;

        // Insert the original string into the set
        add_to_set(unique_combinations, &count, s);

        // Generate combinations by splitting the string at different positions
        for (int j = 1; j < strlen(s); j++) {
<<<<<<< HEAD
            char res[MAX_STRING_LENGTH];
            char res2[MAX_STRING_LENGTH];

            // Create the first part of the split string
            strncpy(res, s, j);
            res[j] = '\0'; // Null-terminate the first part

            // Create the second part of the split string
            strcpy(res2, s + j); // Copy the second part
=======
            char res[MAX_STRING_LENGTH], res2[MAX_STRING_LENGTH];
            strncpy(res, s, j);
            res[j] = '\0'; // Null-terminate the first part

            strncpy(res2, s + j, strlen(s) - j);
            res2[strlen(s) - j] = '\0'; // Null-terminate the second part
>>>>>>> 98c87cb78a (data updated)

            // Create reversed versions of both parts
            char t[MAX_STRING_LENGTH], t2[MAX_STRING_LENGTH];
            strcpy(t, res);
            strrev(t); // Reverse the first part
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
            strcpy(t2, res2);
            strrev(t2); // Reverse the second part

            // Insert various combinations of the parts and their reverses into the set
<<<<<<< HEAD
            add_to_set(unique_combinations, &count, t);
            add_to_set(unique_combinations, &count, t2);
            add_to_set(unique_combinations, &count, strcat(t, res2)); // First part + second part
            add_to_set(unique_combinations, &count, strcat(res2, t)); // Second part + first part
            add_to_set(unique_combinations, &count, strcat(res, t2)); // First part + reversed second part
            add_to_set(unique_combinations, &count, strcat(t2, res)); // Reversed second part + first part
=======
            add_to_set(unique_combinations, &count, strcat(t, res2)); // Original order
            add_to_set(unique_combinations, &count, strcat(t2, res)); // Reversed order

            add_to_set(unique_combinations, &count, strcat(res, res2)); // First part + second part
            add_to_set(unique_combinations, &count, strcat(res2, res)); // Second part + first part

            add_to_set(unique_combinations, &count, strcat(res, t2)); // First part + reversed second part
            add_to_set(unique_combinations, &count, strcat(t2, res)); // Reversed second part + first part

>>>>>>> 98c87cb78a (data updated)
            add_to_set(unique_combinations, &count, strcat(res, res2)); // First part + second part (both original)
            add_to_set(unique_combinations, &count, strcat(res2, res)); // Second part + first part (both original)
        }

        // Output the number of unique combinations generated
        printf("%d\n", count);
    }

    return 0; // End of the program
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

<<<<<<< HEAD
// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
