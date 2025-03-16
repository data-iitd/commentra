#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    long k;
    int n;

    // Step 1: Read input from the user
    scanf("%s", str);
    n = strlen(str);

    // Step 4: Read the value of k
    scanf("%ld", &k);

    for (int i = 0; i < k; i++) {
        // Step 7: Check if the character at the current index is '1'
        if (str[i] == '1') {
            // Step 8: Check if the current index is the last index
            if (i == k - 1) {
                printf("1\n");
                return 0;
            }
        } else {
            // Step 11: Print the character and return
            printf("%c\n", str[i]);
            return 0;
        }
    }

