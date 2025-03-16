#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
    int n;
    scanf("%d", &n);

    int a[MAX_N + 1];
    int b[MAX_N + 1];
    int num[MAX_N + 1] = {0};
    int st[MAX_N + 1] = {0};

    // Read the elements of array a
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // Read the elements of array b
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    // Count the occurrences of each element in array b
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }

    // Initialize variables to store the result
    char ss[MAX_N * 2] = ""; // To store the sequence of indices
    int ans = 0;

    // Iterate through the elements of array a
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            // Mark the current element as visited
            st[i] = 1;

            // Build the sequence of indices
            char sb[MAX_N * 2] = ""; // To build the output string
            int x = b[i];
            char sss[20]; // Temporary string to hold the index
            sprintf(sss, "%d", i);
            strcat(sb, sss);
            strcat(sb, " ");
            int s = 1;

            // Continue building the sequence until a visited element or mismatch is found
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                sprintf(sss, "%d", x);
                strcat(sb, sss);
                strcat(sb, " ");
                st[x] = 1;
                x = b[x];
                s++;
            }

            // Update the result if a longer sequence is found
            if (s > ans) {
                ans = s;
                // Reverse the string
                char temp[MAX_N * 2];
                int len = strlen(sb);
                for (int j = 0; j < len; j++) {
                    temp[j] = sb[len - 1 - j];
                }
                temp[len] = '\0';
                strcpy(ss, temp);
            }
        }
    }

    // Print the result
    printf("%d\n", ans);
    printf("%s\n", ss);

    return 0;
}
