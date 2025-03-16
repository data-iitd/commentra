#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cleanString(char *str) {
    char temp[100];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            temp[j++] = tolower(str[i]);
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char word1[100], word2[100], word3[100];
    
    // Read three words from the input
    fgets(word1, sizeof(word1), stdin);
    fgets(word2, sizeof(word2), stdin);
    fgets(word3, sizeof(word3), stdin);
    
    // Clean the strings
    cleanString(word1);
    cleanString(word2);
    cleanString(word3);
    
    // Generate all possible permutations of the three words
    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    sprintf(perm1, "%s%s%s", word1, word2, word3);
    sprintf(perm2, "%s%s%s", word1, word3, word2);
    sprintf(perm3, "%s%s%s", word2, word1, word3);
    sprintf(perm4, "%s%s%s", word2, word3, word1);
    sprintf(perm5, "%s%s%s", word3, word2, word1);
    sprintf(perm6, "%s%s%s", word3, word1, word2);
    
    // Read the number of students (test cases)
    int students;
    scanf("%d\n", &students); // Read integer and consume newline
    
    // Loop through each student's test case
    for (int i = 0; i < students; i++) {
        char testCase[100];
        fgets(testCase, sizeof(testCase), stdin);
        
        // Clean the test case input
        cleanString(testCase);
        
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

// <END-OF-CODE>
