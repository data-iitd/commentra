#include <stdio.h>

int main() {
    char S[100]; // Declare a character array to store the input string

    // Read a string input from the standard input using scanf
    scanf("%s", S);

    // Switch statement to check the value of the string S and print the corresponding weather condition
    switch (S[0]) {
    case 'S': // If the first character of the input string is 'S'
        if (S[1] == 'u' && S[2] == 'n' && S[3] == 'n' && S[4] == 'y') {
            printf("Cloudy\n"); // Print "Cloudy" as the output
        }
        break;
    case 'C': // If the first character of the input string is 'C'
        if (S[1] == 'l' && S[2] == 'o' && S[3] == 'u' && S[4] == 'd' && S[5] == 'y') {
            printf("Rainy\n"); // Print "Rainy" as the output
        }
        break;
    case 'R': // If the first character of the input string is 'R'
        if (S[1] == 'a' && S[2] == 'i' && S[3] == 'n' && S[4] == 'y') {
            printf("Sunny\n"); // Print "Sunny" as the output
        }
        break;
    }

    return 0;
}
