
#include <stdio.h>

int main() {
    // Declare a string variable S to store the weather input
    char S[100];
    
    // Read a string input from the user and store it in S
    scanf("%s", S);
    
    // Use a switch statement to determine the weather based on the input
    switch (S) {
        case "Sunny":
            // If the input is "Sunny", print "Cloudy"
            printf("Cloudy\n");
            break;
        case "Cloudy":
            // If the input is "Cloudy", print "Rainy"
            printf("Rainy\n");
            break;
        case "Rainy":
            // If the input is "Rainy", print "Sunny"
            printf("Sunny\n");
            break;
    }
    
    return 0;
}

