#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function is defined to run the program
int main() {
    char S[100000]; // Declare a character array to store the input string
    scanf("%s", S); // Read the input string
    int score = 0; // Initialize the score to 0
    for (int i = 0; i < strlen(S); i++) { // Iterate through each character in the string S
        char my = i % 2 == 0? 'g' : 'p'; // Determine the expected character based on the index
        char his = S[i]; // Get the character at the current index in S
        if (my!= his) { // Compare the expected character with the actual character and update the score
            score += my == 'p'? 1 : -1;
        }
    }
    printf("%d\n", score); // Print the final score
    return 0;
}

