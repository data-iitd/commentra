#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 26

typedef struct {
    int left;
} Card;

int compare(const void *a, const void *b) {
    return ((Card *)b)->left - ((Card *)a)->left; // Sort in descending order
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Reading the number of cards and queries

    Card cards[MAX_CARDS]; // Creating an array of size 26 to store the cards
    for (int i = 0; i < MAX_CARDS; i++) { // Initializing the cards array with default values
        cards[i].left = 0;
    }

    char s[n + 1]; // Array to hold the sequence of cards
    scanf("%s", s); // Reading the sequence of cards

    for (int t = 0; t < n; t++) { // Iterating through each character in the sequence
        cards[s[t] - 'A'].left++; // Incrementing the left counter of the corresponding card
    }

    long long ans = 0; // Initializing the answer variable to zero
    for (int i = 0; i < k; i++) { // Iterating through each query
        qsort(cards, MAX_CARDS, sizeof(Card), compare); // Sorting the cards array in descending order of their left counters
        long long change = (cards[0].left < k - i) ? cards[0].left : (k - i); // Calculating the number of cards to be moved
        ans += change * change; // Adding the square of the number of cards moved to the answer
        cards[0].left -= change; // Decreasing the left counter of the highest card by the number of cards moved
        i += change - 1; // Skipping the next i-1 cards as they will have the same left counter
    }

    printf("%lld\n", ans); // Writing the answer to the standard output
    return 0; // Closing the program
}

// <END-OF-CODE>
