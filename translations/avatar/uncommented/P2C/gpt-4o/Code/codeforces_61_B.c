#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 100
#define MAX_PERM 720 // 6! permutations for 3 strings

void to_lowercase(char *s, char *result) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '-' && s[i] != ';' && s[i] != '_') {
            result[j++] = tolower(s[i]);
        }
    }
    result[j] = '\0';
}

void generate_permutations(char arr[][MAX_LEN], int n, char result[][MAX_LEN], int *count) {
    if (n == 1) {
        strcpy(result[*count], arr[0]);
        (*count)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        generate_permutations(arr, n - 1, result, count);
        if (n % 2 == 0) {
            char temp[MAX_LEN];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[n - 1]);
            strcpy(arr[n - 1], temp);
        } else {
            char temp[MAX_LEN];
            strcpy(temp, arr[0]);
            strcpy(arr[0], arr[n - 1]);
            strcpy(arr[n - 1], temp);
        }
    }
}

int main() {
    char input_strings[3][MAX_LEN];
    char processed_strings[3][MAX_LEN];
    char permutations[MAX_PERM][MAX_LEN];
    int perm_count = 0;

    for (int i = 0; i < 3; i++) {
        fgets(input_strings[i], MAX_LEN, stdin);
        input_strings[i][strcspn(input_strings[i], "\n")] = 0; // Remove newline
        to_lowercase(input_strings[i], processed_strings[i]);
    }

    generate_permutations(processed_strings, 3, permutations, &perm_count);

    int test_cases;
    scanf("%d\n", &test_cases);
    for (int i = 0; i < test_cases; i++) {
        char test_string[MAX_LEN];
        fgets(test_string, MAX_LEN, stdin);
        test_string[strcspn(test_string, "\n")] = 0; // Remove newline
        char processed_test[MAX_LEN];
        to_lowercase(test_string, processed_test);

        int found = 0;
        for (int j = 0; j < perm_count; j++) {
            if (strcmp(processed_test, permutations[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
