
#include <stdio.h>
#include <string.h>

// Function definition for counting the number of 'AC' substrings in the given string's'
// The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
int count(int total, int i, char *s) {
    // Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
    return total + (s[i-1] == 'A' && s[i] == 'C');
}

int main() {
    // Taking input for number of strings 'n' and number of problems 'q'
    int n, q;
    scanf("%d %d", &n, &q);

    // Taking input for the string's'
    char s[n];
    scanf("%s", s);

    // List comprehension to create a list 'problems' of lists containing start and end indices of each problem
    int problems[q][2];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &problems[i][0], &problems[i][1]);
    }

    // Variable to store the cumulative sum of 'AC' substrings in the string's'
    int cumsum[n];
    cumsum[0] = 0;
    for (int i = 1; i < n; i++) {
        cumsum[i] = cumsum[i-1] + count(0, i, s);
    }

    // Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
    for (int i = 0; i < q; i++) {
        printf("%d\n", cumsum[problems[i][1]-1] - cumsum[problems[i][0]-1]);
    }

    return 0;
}
