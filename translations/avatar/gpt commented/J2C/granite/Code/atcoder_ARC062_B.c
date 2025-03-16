
#include <stdio.h>
#include <string.h>

int main() {
    // Read the input string S
    char S[100001];
    fgets(S, 100001, stdin);
    
    int score = 0; // Initialize score to zero
    
    // Iterate through each character in the string S
    for (int i = 0; i < strlen(S); i++) {
        // Determine the character for'my' based on the index (even or odd)
        char my = i % 2 == 0? 'g' : 'p'; 
        
        // Get the character from the input string at the current index
        char his = S[i]; 
        
        // Compare'my' and 'his' characters to update the score
        if (my!= his) { 
            // Increment score if'my' is 'p', otherwise decrement
            score += my == 'p'? 1 : -1; 
        } 
    } 
    
    // Output the final score
    printf("%d\n", score);
    
    return 0;
}
