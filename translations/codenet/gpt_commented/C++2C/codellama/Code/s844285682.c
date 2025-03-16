#include<stdio.h> // Include the iostream library for input and output operations

int main() {
    int a, b; // Declare two integer variables a and b
    
    // Read an integer input from the user, which represents time in seconds
    scanf("%d", &a);
    
    // Calculate and display the time in hours, minutes, and seconds
    // a/(60*60) calculates the number of hours
    // a%(60*60)/60 calculates the number of minutes
    // a%(60*60)%60 calculates the remaining seconds
    printf("%d:%d:%d\n", a/(60*60), a%(60*60)/60, a%(60*60)%60);
    
    return 0; // Return 0 to indicate that the program ended successfully
}

