#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

typedef long long ll;

typedef struct {
    char **data;
    int size;
    int capacity;
} Set;

void initSet(Set *set) {
    set->size = 0;
    set->capacity = 10;
    set->data = (char **)malloc(set->capacity * sizeof(char *));
}

void insertSet(Set *set, const char *str) {
    // Check for duplicates
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->data[i], str) == 0) {
            return; // Already exists
        }
    }
    // If not found, insert
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = (char **)realloc(set->data, set->capacity * sizeof(char *));
    }
    set->data[set->size] = strdup(str);
    set->size++;
}

void freeSet(Set *set) {
    for (int i = 0; i < set->size; i++) {
        free(set->data[i]);
    }
    free(set->data);
}

<<<<<<< HEAD
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

=======
>>>>>>> 98c87cb78a (data updated)
int main() {
    int n;
    scanf("%d", &n); // Step 1: Reading Input

    rep(i, n) { // Step 2: Processing Each Test Case
        char s[1001]; // Assuming max length of string is 1000
<<<<<<< HEAD
        scanf("%s", s); // Read the string

        Set st;
        initSet(&st); // Initialize the set
        insertSet(&st, s); // Insert the original string

        int len = strlen(s);
        REP(j, 1, len) { // Step 3: Generating Substrings and Checking for Palindromes
            char res[1001], res2[1001];

            // First part reversed
            strncpy(res, s, j);
            res[j] = '\0';
            reverseString(res);

            // Second part reversed
            strncpy(res2, s + j, len - j);
            res2[len - j] = '\0';
            reverseString(res2);
=======
        scanf("%s", s); // For each test case, read string s

        Set st;
        initSet(&st); // Step 3: Generating Substrings and Checking for Palindromes
        insertSet(&st, s); // Insert the original string

        int len = strlen(s);
        REP(j, 1, len) { // Iterate over possible split points
            char res[1001], res2[1001];
            // Reverse first part
            for (int k = 0; k < j; k++) {
                res[k] = s[j - 1 - k];
            }
            res[j] = '\0'; // Null-terminate the string

            // Reverse second part
            for (int k = j; k < len; k++) {
                res2[k - j] = s[len - 1 - (k - j)];
            }
            res2[len - j] = '\0'; // Null-terminate the string
>>>>>>> 98c87cb78a (data updated)

            char t[2002], t2[2002];

            // Concatenate and insert in both orders
            sprintf(t, "%s%s", res, res2);
            insertSet(&st, t);
<<<<<<< HEAD
            sprintf(t, "%s%s", res2, res);
            insertSet(&st, t);

            sprintf(t, "%s%s", res, s + j);
            insertSet(&st, t);
            sprintf(t, "%s%s", s + j, res);
            insertSet(&st, t);

            sprintf(t, "%s%s", s, res2);
            insertSet(&st, t);
            sprintf(t, "%s%s", res2, s);
            insertSet(&st, t);

            sprintf(t, "%s%s", res, s + j);
            insertSet(&st, t);
            sprintf(t, "%s%s", s + j, res);
            insertSet(&st, t);

            sprintf(t, "%s%s", res, res2);
            insertSet(&st, t);
            sprintf(t, "%s%s", res2, res);
            insertSet(&st, t);
=======
            sprintf(t2, "%s%s", res2, res);
            insertSet(&st, t2);

            sprintf(t, "%s%s", res, res2);
            insertSet(&st, t);
            sprintf(t2, "%s%s", res2, res);
            insertSet(&st, t2);

            sprintf(t, "%s%s", res, res2);
            insertSet(&st, t);
            sprintf(t2, "%s%s", res2, res);
            insertSet(&st, t2);

            sprintf(t, "%s%s", res, res2);
            insertSet(&st, t);
            sprintf(t2, "%s%s", res2, res);
            insertSet(&st, t2);
>>>>>>> 98c87cb78a (data updated)
        }

        printf("%d\n", st.size); // Step 4: Outputting the Result
        freeSet(&st); // Free the set
    }

    return 0; // Step 5: End of Program
<<<<<<< HEAD
}

// <END-OF-CODE>
=======
} // <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
