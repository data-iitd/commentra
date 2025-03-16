#include<iostream> // Include the standard input-output library

int main() // Main function where program execution begins
{
    int x; // Declare an integer variable x

    // Prompt the user for input and read an integer value into x
    std::cin >> x;

    // Calculate the cube of x and print the result
    std::cout << x * x * x << std::endl;

    return 0; // Return 0 to indicate successful execution
}

