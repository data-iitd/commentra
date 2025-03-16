#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure to represent each card
typedef struct { 
    int left; // Count of letters left
} c462b; 

// Function to sort the cards based on the count of letters
int compare(const void *a, const void *b) { 
    return ((c462b *) a)->left - ((c462b *) b)->left; 
} 

int main() { 
    // Initialize variables
    int n, k, t; 
    char s[100000]; 
    c462b cards[26]; 
    
    // Read the first line of input and tokenize it to extract n and k
    scanf("%d %d", &n, &k); 
    
    // Initialize the array of c462b objects to count occurrences of each letter
    for (int i = 0; i < 26; i++) { 
        cards[i].left = 0; // Initialize each card
    } 
    
    // Read the string of cards and count the occurrences of each letter
    scanf("%s", s); 
    for (t = 0; t < n; t++) { 
        cards[s[t] - 'A'].left++; // Increment the count for the corresponding letter
    } 
    
    long ans = 0; // Variable to store the final answer
    
    // Perform k operations to maximize the score
    for (int i = 0; i < k; i++) { 
        // Sort the cards based on the count of letters
        qsort(cards, 26, sizeof(c462b), compare); 
        
        // Determine the number of changes to make for the most frequent letter
        long change = (cards[25].left < k - i) ? cards[25].left : k - i; 
        ans += change * change; // Update the answer with the square of changes
        
        // Decrease the count of the most frequent letter by the number of changes made
        cards[25].left -= change; 
        i += change - 1; // Adjust the loop counter based on changes made
    } 
    
    // Output the final result
    printf("%ld\n", ans); 
    return 0; 
} 

