#include <stdio.h>  // Including standard input-output library
#include <stdbool.h>  // Including library for boolean type
#include <string.h>  // Including string manipulation library

#define MAX_N 1000  // Defining a maximum size for the arrays

int main() {
    int n;  // Number of test cases
    scanf("%d", &n);  // Reading the number of test cases

    int a[MAX_N + 1];  // Array 'a' of size 'n+1'
    int b[MAX_N + 1];  // Array 'b' of size 'n+1'
    int num[MAX_N + 1] = {0};  // Array 'num' of size 'n+1', initialized to 0

    for (int i = 1; i <= n; i++) {  // Loop to read the elements of arrays 'a' and 'b'
        scanf("%d %d", &a[i], &b[i]);
    }

    char ss[2000] = "";  // String to store the final answer
    int ans = 0;  // Variable to store the maximum length of the answer
    bool st[MAX_N + 1] = {false};  // Boolean array 'st' of size 'n+1'

    for (int i = 1; i <= n; i++) {  // Loop to find the longest chain of numbers
        if (a[i] == 1) {  // If the current number 'i' in array 'a' is 1
            st[i] = true;  // Mark the current number as visited
            char sb[2000] = "";  // String to store the answer
            int x = b[i];  // Assigning the value of 'b[i]' to 'x'
            char sss[10];  // Buffer to store the current number 'i'
            sprintf(sss, "%d", i);  // Convert 'i' to string
            strncat(sb, sss, sizeof(sb) - strlen(sb) - 1);  // Append 'i' to 'sb'
            strncat(sb, " ", sizeof(sb) - strlen(sb) - 1);  // Append space to 'sb'
            strrev(sss);  // Reverse the string 'sss'
            strncat(sb, sss, sizeof(sb) - strlen(sb) - 1);  // Append reversed 'sss' to 'sb'
            int s = 1;  // Initialize length of the current chain

            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {  // Loop to traverse the graph
                sprintf(sss, "%d", x);  // Convert 'x' to string
                strncat(sb, " ", sizeof(sb) - strlen(sb) - 1);  // Append space to 'sb'
                strncat(sb, sss, sizeof(sb) - strlen(sb) - 1);  // Append 'x' to 'sb'
                strrev(sss);  // Reverse the string 'sss'
                strncat(sb, " ", sizeof(sb) - strlen(sb) - 1);  // Append space to 'sb'
                strncat(sb, sss, sizeof(sb) - strlen(sb) - 1);  // Append reversed 'sss' to 'sb'
                st[x] = true;  // Marking the current number 'x' as visited
                x = b[x];  // Assigning the value of 'b[x]' to 'x'
                s++;  // Incrementing the length of the current chain
            }

            if (s > ans) {  // If the length of the current chain is greater than the current maximum length
                ans = s;  // Updating the maximum length
                strcpy(ss, sb);  // Updating the final answer
            }
        }
    }

    printf("%d\n", ans);  // Printing the maximum length of the longest chain
    printf("%s\n", ss);  // Printing the longest chain as a string

    return 0;  // Return success
}

// <END-OF-CODE>
