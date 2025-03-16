
#include <stdio.h>
#include <string.h>

int main() {
    // Create a Scanner object to read input from the console
    char word1[100], word2[100], word3[100], testCase[100];
    scanf("%s %s %s", word1, word2, word3);
    
    // Remove non-alphabetic characters and convert to lowercase
    for (int i = 0; word1[i]!= '\0'; i++) {
        if (!isalpha(word1[i])) {
            word1[i] = '\0';
        } else {
            word1[i] = tolower(word1[i]);
        }
    }
    for (int i = 0; word2[i]!= '\0'; i++) {
        if (!isalpha(word2[i])) {
            word2[i] = '\0';
        } else {
            word2[i] = tolower(word2[i]);
        }
    }
    for (int i = 0; word3[i]!= '\0'; i++) {
        if (!isalpha(word3[i])) {
            word3[i] = '\0';
        } else {
            word3[i] = tolower(word3[i]);
        }
    }
    
    // Generate all possible permutations of the three words
    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    strcpy(perm1, word1);
    strcat(perm1, word2);
    strcat(perm1, word3);
    strcpy(perm2, word1);
    strcat(perm2, word3);
    strcat(perm2, word2);
    strcpy(perm3, word2);
    strcat(perm3, word1);
    strcat(perm3, word3);
    strcpy(perm4, word2);
    strcat(perm4, word3);
    strcat(perm4, word1);
    strcpy(perm5, word3);
    strcat(perm5, word2);
    strcat(perm5, word1);
    strcpy(perm6, word3);
    strcat(perm6, word1);
    strcat(perm6, word2);
    
    // Read the number of students (test cases)
    int students;
    scanf("%d", &students);
    
    // Loop through each student's test case
    for (int i = 0; i < students; i++) {
        scanf("%s", testCase);
        
        // Remove non-alphabetic characters and convert to lowercase
        for (int j = 0; testCase[j]!= '\0'; j++) {
            if (!isalpha(testCase[j])) {
                testCase[j] = '\0';
            } else {
                testCase[j] = tolower(testCase[j]);
            }
        }
        
        // Check if the test case matches any of the generated permutations
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 ||
            strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 ||
            strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            // If it matches, print "ACC" (Accepted)
            printf("ACC\n");
        } else {
            // If it doesn't match, print "WA" (Wrong Answer)
            printf("WA\n");
        }
    }
    
    return 0;
}
