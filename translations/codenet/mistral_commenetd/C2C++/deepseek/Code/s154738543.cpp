#include <iostream> // Including the iostream library for input/output operations

int main() { // Main function declaration

    int x, y; // Declaring two integer variables x and y

    std::cout << "Enter a number: "; // Printing a message to ask user for input
    std::cin >> x; // Reading an integer value from the user and storing it in variable x

    y = x * x * x; // Assigning the value of x cubed to variable y

    std::cout << "The cube of " << x << " is " << y << std::endl; // Printing the message with the input number and its cube

    return 0; // Indicating successful execution of the program
}

