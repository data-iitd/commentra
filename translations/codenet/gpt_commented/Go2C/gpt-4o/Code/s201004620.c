#include <stdio.h>
#include <string.h>

int main() {
    // Declare a variable to hold the weather condition input
    char S[10];
    
    // Read the weather condition from standard input
    scanf("%s", S);
    
    // Use a switch statement to determine the next weather condition based on the input
    if (strcmp(S, "Sunny") == 0) {
        // If the input is "Sunny", print "Cloudy" as the next condition
        printf("Cloudy\n");
    } else if (strcmp(S, "Cloudy") == 0) {
        // If the input is "Cloudy", print "Rainy" as the next condition
        printf("Rainy\n");
    } else if (strcmp(S, "Rainy") == 0) {
        // If the input is "Rainy", print "Sunny" as the next condition
        printf("Sunny\n");
    }
    
    return 0;
}

// <END-OF-CODE>
