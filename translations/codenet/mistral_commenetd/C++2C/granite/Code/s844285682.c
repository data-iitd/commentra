

#include<stdio.h> // Include the stdio header file

int main(){
    int a; // Declare an integer variable named a
    
    printf("Enter the number of seconds: "); // Print a message to ask the user for the number of seconds
    scanf("%d", &a); // Read an integer value from the standard input stream and assign it to the variable a
    
    int hours = a / (60 * 60); // Extract the hours from the number of seconds
    int minutes = (a % (60 * 60)) / 60; // Extract the minutes from the remaining seconds
    int seconds = (a % (60 * 60)) % 60; // Extract the seconds from the remaining seconds
    
    printf("%d:%d:%d\n", hours, minutes, seconds); // Print the time representation of the number of seconds
    
    return 0; // Return 0 to indicate successful execution of the program
}

