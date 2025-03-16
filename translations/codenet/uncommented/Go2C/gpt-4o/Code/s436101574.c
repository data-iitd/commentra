#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000000

void scanString(char *buffer) {
    scanf("%s", buffer);
}

int main() {
    char s[MAX_LEN], t[MAX_LEN];
    char ans[MAX_LEN][MAX_LEN]; // To store possible answers
    int ansCount = 0;

    scanString(s);
    scanString(t);

    int lenS = strlen(s);
    int lenT = strlen(t);

    for (int i = 0; i <= lenS - lenT; i++) {
        bool f = true;
        char ss[MAX_LEN];
        strcpy(ss, s);

        for (int j = 0; j < lenT; j++) {
            if (s[i + j] != t[j] && s[i + j] != '?') {
                f = false;
                break;
            } else {
                ss[i + j] = t[j];
            }
        }
        if (f) {
            for (int k = 0; k < lenS; k++) {
                if (ss[k] == '?') {
                    ss[k] = 'a'; // Replace '?' with 'a'
                }
            }
            strcpy(ans[ansCount++], ss);
        }
    }

    // Sort the answers
    if (ansCount == 0) {
        printf("UNRESTORABLE\n");
    } else {
        // Simple bubble sort for demonstration, can be replaced with qsort for efficiency
        for (int i = 0; i < ansCount - 1; i++) {
            for (int j = 0; j < ansCount - i - 1; j++) {
                if (strcmp(ans[j], ans[j + 1]) > 0) {
                    char temp[MAX_LEN];
                    strcpy(temp, ans[j]);
                    strcpy(ans[j], ans[j + 1]);
                    strcpy(ans[j + 1], temp);
                }
            }
        }
        printf("%s\n", ans[0]);
    }

    return 0;
}

// <END-OF-CODE>
