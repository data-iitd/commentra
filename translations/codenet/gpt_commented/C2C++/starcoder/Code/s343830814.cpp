#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // Declare a string to hold the input string
    std::string buf;

    // Read a line of input from standard input (stdin) into the string
    std::getline(std::cin, buf);

    // Print the first character, the length of the string minus 3, and the second to last character
    std::cout << buf[0] << buf.size() - 3 << buf[buf.size() - 2] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

