#include <iostream> // Including the iostream library for input and output

int main() // Starting the main function
{
    int n; // Declaring an integer variable `n` to store the user input

    std::cout << "Enter a number: "; // Printing a message to ask the user to enter a number
    std::cin >> n; // Reading an integer value from the standard input and storing it in the variable `n`

    if (n % 1000 == 0) // Checking if the remainder of `n` when divided by 1000 is equal to 0
    {
        std::cout << 0 << std::endl; // If the condition is true, we print the value 0 to the standard output
    }
    else
    {
        std::cout << (n / 1000 + 1) * 1000 - n << std::endl; // If the condition is false, we calculate the number that is one thousand greater than the quotient of `n` when divided by 1000 and print that value to the standard output
    }

    return 0; // Ending the main function with a return value of 0
}

// <END-OF-CODE>
