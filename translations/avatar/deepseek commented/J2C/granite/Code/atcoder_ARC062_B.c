
#include <stdio.h> // Include the necessary header files for input/output operations
#include <string.h> // Include the necessary header file for string manipulation

// Define the main function to run the program
int main() {
    char S[100001]; // Declare a character array to store the input string
    scanf("%s", S); // Read the input string from the standard input
    int score = 0; // Initialize the score to 0
    // Iterate through each character in the string S
    for (int i = 0; S[i]!= '\0'; i++) {
        char my = i % 2 == 0? 'g' : 'p'; // Determine the expected character based on the index
        char his = S[i]; // Get the character at the current index in S
        // Compare the expected character with the actual character and update the score
        if (my!= his) {
            score += my == 'p'? 1 : -1; // Update the score based on the expected character
        }
    }
    printf("%d\n", score); // Print the final score to the standard output
    return 0; // Return 0 to indicate successful program execution
}

// Translate the above C code to Python and end with comment "