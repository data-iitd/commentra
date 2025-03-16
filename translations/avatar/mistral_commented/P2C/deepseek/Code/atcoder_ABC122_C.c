#include <stdio.h>
#include <stdlib.h>

// Function to count the number of 'AC' substrings in the given string 's'
int count(int total, char *s, int i) {
    // Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
    return total + 1;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Allocate memory for the string 's'
    char *s = (char *)malloc(n + 1);
    scanf("%s", s);

    // Allocate memory for the list 'problems'
    int **problems = (int **)malloc(q * sizeof(int *));
    for (int i = 0; i < q; i++) {
        problems[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }

    // Calculate the cumulative sum of 'AC' substrings in the string 's'
    int *cumsum = (int *)malloc((n + 1) * sizeof(int));
    cumsum[0] = 0;
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i - 1];
        if (s[i - 1] == 'A' && s[i] == 'C') {
            cumsum[i]++;
        }
    }

    // Iterate through each problem in the list 'problems' and print the difference between the cumulative sum at the end and start of the problem
    for (int i = 0; i < q; i++) {
        int l = problems[i][0];
        int r = problems[i][1];
        printf("%d\n", cumsum[r - 1] - cumsum[l - 1]);
    }

    // Free allocated memory
    free(s);
    for (int i = 0; i < q; i++) {
        free(problems[i]);
    }
    free(problems);
    free(cumsum);

    return 0;
}
