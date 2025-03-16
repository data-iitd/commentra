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
    // Declare two string variables and read input from the user
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);

    // Sort the characters in string str1 in ascending order and in string str2 in descending order
    qsort(str1, strlen(str1), sizeof(char), compareAsc);
    qsort(str2, strlen(str2), sizeof(char), compareDesc);

    // Determine the length of the shorter string to be used as the loop limit
    int loop = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1);

    // Initialize a boolean flag to false
    int flag = 0;

    // Loop through the characters in both strings up to the length of the shorter string
    for (int i = 0; i < loop; i++) {
        // Get the characters at the current index in both strings
        char ch1 = str1[i];
        char ch2 = str2[i];

        // Check if the characters are equal. If they are, check if we have reached the end of the strings
        if (ch1 == ch2) {
            // If we have reached the end of str1 and str2 is not empty, set the flag to true and break out of the loop
            if (loop == i + 1 && strlen(str1) < strlen(str2)) {
                flag = 1;
                break;
            } else {
                // If we have not reached the end of the strings, continue to the next iteration of the loop
                continue;
            }
        } else {
            // If the characters are not equal, compare their ASCII values. If ch2 is greater than ch1, set the flag to true and break out of the loop
            if (ch2 > ch1) {
                flag = 1;
                break;
            } else {
                // If ch1 is greater than or equal to ch2, continue to the next iteration of the loop
                break;
            }
        }
    }

    // If the flag is true, print "Yes" to the console. Otherwise, print "No" to the console
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
