#include <stdio.h>
#include <string.h>

int main() {
    // Read a string from standard input
    char s[1000];
    scanf("%s", s);

    // Initialize variables to keep track of the maximum lengths
    int max_tmp = 0;
    int max = 0;

    // Iterate over each character in the string
    for (int i = 0; i < strlen(s); i++) {
        int flag = 0;
        // Check if the character is one of 'A', 'C', 'T', 'G'
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G') {
            // Increment the temporary maximum length counter
            max_tmp++;
        } else {
            // Set the flag to true if the character is not 'A', 'C', 'T', 'G'
            flag = 1;
        }

        // At the end of the loop, if the flag is true, update the overall maximum length
        if (i == strlen(s) - 1) {
            flag = 1;
        }
        if (flag == 1) {
            if (max < max_tmp) {
                max = max_tmp;
            }
            // Reset the temporary maximum length counter
            max_tmp = 0;
        }
    }

    // Print the value of the overall maximum length
    printf("%d\n", max);

    return 0;
}
