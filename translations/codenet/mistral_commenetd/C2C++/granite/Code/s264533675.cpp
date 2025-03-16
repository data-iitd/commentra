
#include<iostream> // Include the standard input/output library

int main() // Declare the main function
{
    char str[30]; // Declare a character array str of size 30

    // Get a string input from the user using gets() function and store it in str array
    gets(str);

    // Assign a space character to the 6th index (index starts from 0) and 14th index of the string str
    str[5] =' ';
    str[13] =' ';

    // Print the modified string using cout statement
    std::cout << str << std::endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}
