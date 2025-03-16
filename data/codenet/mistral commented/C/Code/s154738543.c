
#include<stdio.h> // Including the standard input/output library

int main(void){ // Main function declaration and void keyword signifies no arguments

    int x, y; // Declaring two integer variables x and y

    printf("Enter a number: "); // Printing a message to ask user for input
    scanf("%d",&x); // Reading an integer value from the user and storing it in variable x

    y = x * x * x; // Assigning the value of x cubed to variable y

    printf("The cube of %d is %d\n", x, y); // Printing the message with the input number and its cube

    return 0; // Indicating successful execution of the program
}