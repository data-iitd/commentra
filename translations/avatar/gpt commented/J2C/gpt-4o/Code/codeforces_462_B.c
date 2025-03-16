#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left; // Count of letters left
} c462b;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return ((c462b *)a)->left - ((c462b *)b)->left;
}

int main() {
    // Initialize variables
    int n, k;
    scanf("%d %d", &n, &k); // Read n and k

    // Create an array of c462b objects to count occurrences of each letter
    c462b cards[26] = {0}; // Initialize all counts to 0

    // Read the string of cards and count the occurrences of each letter
    char s[n + 1]; // +1 for null terminator
    scanf("%s", s);
    for (int t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++; // Increment the count for the corresponding letter
    }

    long ans = 0; // Variable to store the final answer

    // Perform k operations to maximize the score
    for (int i = 0; i < k; i++) {
        // Sort the cards based on the count of letters
        qsort(cards, 26, sizeof(c462b), compare);

        // Determine the number of changes to make for the most frequent letter
        long change = (cards[25].left < k - i) ? cards[25].left : (k - i);
        ans += change * change; // Update the answer with the square of changes

        // Decrease the count of the most frequent letter by the number of changes made
        cards[25].left -= change;
        i += change - 1; // Adjust the loop counter based on changes made
    }

    // Output the final result
    printf("%ld\n", ans); // Print the result

    return 0; // Return success
}

// <END-OF-CODE>
