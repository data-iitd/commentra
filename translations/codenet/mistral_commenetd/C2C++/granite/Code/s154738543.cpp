

#include<iostream> // Including the standard input/output library

int main(void){ // Main function declaration and void keyword signifies no arguments

    int x, y; // Declaring two integer variables x and y

    std::cout << "Enter a number: "; // Printing a message to ask user for input
    std::cin >> x; // Reading an integer value from the user and storing it in variable x

    y = x * x * x; // Assigning the value of x cubed to variable y

    std::cout << "The cube of " << x << " is " << y << std::endl; // Printing the message with the input number and its cube

    return 0; // Indicating successful execution of the program
}

