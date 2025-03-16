
#include <stdio.h>
#include <string.h>

int main() {
    // Read an integer input n which represents the threshold for majority
    int n;
    scanf("%d", &n);

    // Read a line of input, split it into a list of strings, and store it in m
    char m[1000];
    fgets(m, 1000, stdin);
    char *token = strtok(m, " ");

    // Initialize a variable to track if a majority element is possible
    int possible = 1;

    // Iterate through each unique element in the list m
    while (token!= NULL) {
        // Check if the count of the current element token is greater than or equal to n/2 + 1
        int count = 0;
        char *p = m;
        while ((p = strstr(p, token))!= NULL) {
            count++;
            p += strlen(token);
        }
        if (count >= n / 2 + 1) {
            // If it is, set possible to 0 and break the loop
            possible = 0;
            break;
        }
        token = strtok(NULL, " ");
    }

    // Print 'YES' if a majority element is not found, otherwise print 'NO'
    printf("%s\n", possible? "YES" : "NO");

    return 0;
}
