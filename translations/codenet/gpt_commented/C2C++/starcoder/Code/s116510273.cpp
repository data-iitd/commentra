#include <iostream>
#include <string>

int main()
{
    // Declare a string object to hold the input string with a maximum length of 100 characters
    std::string mes;

    // Read a string from standard input and store it in the'mes' string object
    std::cin >> mes;

    // Print the first character of the string, the length of the string minus 2, and the last character of the string
    std::cout << mes[0] << mes.size() - 2 << mes[mes.size() - 1] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}
