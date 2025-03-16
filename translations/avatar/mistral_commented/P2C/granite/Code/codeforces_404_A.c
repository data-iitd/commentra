
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Take the number of rows as input
    int n;
    scanf("%d", &n);

    // Initialize an empty list's' to store the rows
    char **s = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = (char *)malloc(n * sizeof(char));
    }

    // Read each row and store it in the list's'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &s[i][j]);
        }
    }

    // Initialize flags and empty lists 'd1' and 'd2'
    int flag = 0;
    char *d1 = (char *)malloc(n * sizeof(char));
    char *d2 = (char *)malloc(n * sizeof(char));

    // Iterate through each element in the list's'
    for (int i = 0; i < n; i++) {
        // Iterate through each element in the same row and in the reverse order
        for (int j = 0; j < n; j++) {
            // If the current indices are same, append the element to 'd1'
            if (i == j) {
                d1[i] = s[i][j];
            }
            // If the current indices are reverse of each other, append the element to 'd2'
            if (i == n - j) {
                d2[i] = s[i][j];
            }
            // If the current indices are not same and not reverse, add the element to'rem' set
            if (i!= j && i!= n - j) {
                // Add the element to'rem' set
                //...
            }
        }
    }

    // Check if the size of'rem' set is not equal to 1
    if (/* condition */) {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // Check if 'd1' and 'd2' lists are equal
    if (/* condition */) {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // Check if all elements in 'd1' are same
    if (/* condition */) {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // Check if all elements in 'd1' are present in'rem' set
    if (/* condition */) {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // If all the above conditions are false, print 'YES'
    printf("YES\n");

    // Free the memory allocated for's' and 'd1' and 'd2'
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    free(d1);
    free(d2);

    return 0;
}
