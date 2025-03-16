#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
} c462b;

int compare(const void *a, const void *b) {
    return ((c462b *)a)->left - ((c462b *)b)->left;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Reading the first line of input
    c462b cards[26]; // Initializing an array of c462b objects with 26 elements

    for (int i = 0; i < 26; i++) { // Looping through the array to initialize each element
        cards[i].left = 0; // Initializing each c462b object
    }

    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s); // Reading the string from the input

    for (int t = 0; t < n; t++) { // Looping through the string to count occurrences
        cards[s[t] - 'A'].left++; // Incrementing the left property of the corresponding c462b object
    }

    long long ans = 0; // Initializing the answer variable to zero
    for (int i = 0; i < k; i++) { // Looping k times to calculate the answer
        qsort(cards, 26, sizeof(c462b), compare); // Sorting the cards array
        long long change = (cards[25].left < k - i) ? cards[25].left : (k - i); // Calculating the minimum
        ans += change * change; // Adding the square of the calculated value to ans
        cards[25].left -= change; // Decrementing the left property of the largest element
        i += change - 1; // Adjusting the loop counter
    }

    printf("%lld\n", ans); // Printing the result
    return 0; // Closing the program
}

// <END-OF-CODE>
