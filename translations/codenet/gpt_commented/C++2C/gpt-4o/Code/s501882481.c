#include <stdio.h>
#include <string.h>

// Function to print the next weather condition based on the current one
<<<<<<< HEAD
void print_next_weather(const char* current_weather) {
    if (strcmp(current_weather, "Sunny") == 0) {
        printf("Cloudy\n"); // If it's sunny, print "Cloudy"
    } else if (strcmp(current_weather, "Cloudy") == 0) {
=======
void print_next_weather(const char* weather) {
    if (strcmp(weather, "Sunny") == 0) {
        printf("Cloudy\n"); // If it's sunny, print "Cloudy"
    } else if (strcmp(weather, "Cloudy") == 0) {
>>>>>>> 98c87cb78a (data updated)
        printf("Rainy\n"); // If it's cloudy, print "Rainy"
    } else {
        printf("Sunny\n"); // If it's neither, it must be rainy, print "Sunny"
    }
}

// Main function where the program execution begins
int main() {
    char S[10]; // Variable to store the input weather condition
    scanf("%s", S); // Read the weather condition from standard input

    print_next_weather(S); // Determine and print the next weather condition

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
