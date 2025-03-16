#include <stdio.h> // Include the stdio.h library for input and output operations

int main() {
<<<<<<< HEAD
    int a; // Declare an integer variable a
=======
    int a, b; // Declare two integer variables a and b
>>>>>>> 98c87cb78a (data updated)
    
    // Read an integer input from the user, which represents time in seconds
    scanf("%d", &a);
    
    // Calculate and display the time in hours, minutes, and seconds
    // a/(60*60) calculates the number of hours
    // a%(60*60)/60 calculates the number of minutes
    // a%(60*60)%60 calculates the remaining seconds
    printf("%d:%d:%d\n", a/(60*60), (a%(60*60))/60, (a%(60*60))%60);
    
    return 0; // Return 0 to indicate that the program ended successfully
}

// <END-OF-CODE>
