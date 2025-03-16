#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to sort the cards based on the count of letters
void sortCards(c462b cards[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cards[i].left > cards[j].left) {
                c462b temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

// Function to perform k operations to maximize the score
void maximizeScore(c462b cards[], int n, int k) {
    int ans = 0; // Variable to store the final answer
    
    // Perform k operations to maximize the score
    for (int i = 0; i < k; i++) {
        sortCards(cards, n); // Sort the cards based on the count of letters
        
        // Determine the number of changes to make for the most frequent letter
        int change = (cards[n - 1].left < k - i)? cards[n - 1].left : k - i;
        ans += change * change; // Update the answer with the square of changes
        
        // Decrease the count of the most frequent letter by the number of changes made
        cards[n - 1].left -= change;
        i += change - 1; // Adjust the loop counter based on changes made
    }
    
    // Output the final result
    printf("%d\n", ans);
}

// Function to read the first line of input and tokenize it to extract n and k
void readInput(int *n, int *k) {
    scanf("%d %d", n, k);
}

// Function to read the string of cards and count the occurrences of each letter
void readCards(c462b cards[], int n) {
    char s[n + 1];
    scanf("%s", s);
    
    for (int i = 0; i < n; i++) {
        cards[s[i] - 'A'].left++; // Increment the count for the corresponding letter
    }
}

// Function to initialize each card
void initCards(c462b cards[], int n) {
    for (int i = 0; i < n; i++) {
        cards[i].left = 0;
    }
}

// Function to print the array of cards
void printCards(c462b cards[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", i + 'A', cards[i].left);
    }
}

// Main function
int main() {
    int n, k;
    readInput(&n, &k);
    
    c462b cards[26];
    initCards(cards, 26);
    readCards(cards, n);
    
    maximizeScore(cards, 26, k);
    
    return 0;
}

