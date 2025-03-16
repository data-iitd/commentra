
#include<stdio.h> // Include the standard input/output library for input and output

int main() {
    int x; // Declare an integer variable x to store user input
    scanf("%d", &x); // Read an integer value from the user and store it in x

    // Check if the input value x is greater than or equal to 1200
    if (x >= 1200) 
        printf("ARC\n"); // If true, output "ARC"
    else 
        printf("ABC\n"); // If false, output "ABC"
    
    return 0; // Return 0 to indicate successful completion of the program
}


