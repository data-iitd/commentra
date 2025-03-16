
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n); // Step 1: Reading Input - The program starts by reading an integer n which represents the number of test cases.

    for (int i = 0; i < n; i++) { // Step 2: Processing Each Test Case - The outer loop for (int i = 0; i < n; i++) iterates over each test case.
        char s[1000];
        scanf("%s", s); // For each test case, the program reads a string s.

        bool st[1000000]; // Step 3: Generating Substrings and Checking for Palindromes - A boolean array st is used to store unique substrings.
        memset(st, false, sizeof(st)); // The boolean array is initialized to false.

        int len = strlen(s); // The length of the string s is calculated.
        for (int j = 1; j < len; j++) { // The inner loop for (int j = 1; j < len; j++) iterates over possible split points in the string s.
            char res[1000]; // A character array res is used to construct substrings.
            for (int k = 0; k < j; k++) { // The first part of the string is extracted and reversed.
                res[k] = s[k];
            }
            res[j] = '\0';
            reverse(res, res + j); // The first part is reversed.

            char res2[1000]; // Another character array res2 is used to extract the second part of the string.
            for (int k = j; k < len; k++) { // The second part of the string is extracted and reversed.
                res2[k - j] = s[k];
            }
            res2[len - j] = '\0';
            reverse(res2, res2 + len - j); // The second part is reversed.

            char t[1000]; // The first part is concatenated with the reversed second part in both orders and added to the set.
            strcpy(t, res);
            strcat(t, res2);
            st[strlen(t)] = true;

            char t2[1000]; // The first part is concatenated with the reversed first part and added to the set.
            strcpy(t2, res);
            strcat(t2, res2);
            st[strlen(t2)] = true;

            char t3[1000]; // The reversed first part is concatenated with the second part and added to the set.
            strcpy(t3, res2);
            strcat(t3, res);
            st[strlen(t3)] = true;

            char t4[1000]; // The reversed first and second parts are concatenated in both orders and added to the set.
            strcpy(t4, res2);
            strcat(t4, res);
            st[strlen(t4)] = true;
        }

        int count = 0; // Step 4: Outputting the Result - After processing all split points for a string, the count of unique substrings is calculated.
        for (int j = 0; j < 1000000; j++) {
            if (st[j]) {
                count++;
            }
        }
        printf("%d\n", count); // The count of unique substrings is printed.
    }

    return 0; // Step 5: End of Program - The program ends with return 0.
}

