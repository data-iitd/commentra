#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareAsc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

int main() {
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);

    // Sort the first string in ascending order
    size_t len1 = strlen(str1);
    qsort(str1, len1, sizeof(char), compareAsc);

    // Sort the second string in descending order
    size_t len2 = strlen(str2);
    qsort(str2, len2, sizeof(char), compareDesc);

    // Determine the loop limit based on the length of the shorter string
    int loop = len1 > len2 ? len2 : len1;
    int flag = 0;

    // Compare characters of the two sorted strings
    for (int i = 0; i < loop; i++) {
        char ch1 = str1[i];
        char ch2 = str2[i];

        // If characters match, continue to the next character
        if (ch1 == ch2) {
            if (loop == i + 1 && len1 < len2) {
                flag = 1;
                break;
            } else {
                continue;
            }
        } else {
            // If characters do not match, check if the character from the second string is greater
            if (ch2 > ch1) {
                flag = 1;
                break;
            } else {
                break;
            }
        }
    }

    // Check the flag and print the result
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
