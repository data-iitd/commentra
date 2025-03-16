
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // Declare a string variable to hold the input string
    std::string buf;

    // Read a line of input from standard input (stdin) into the string variable
    std::getline(std::cin, buf);

    // Calculate the length of the input string
    int len = buf.length();

    // Print the first character, the length of the string minus 3, and the second to last character
    std::cout << buf[0] << len-3 << buf[len-2] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}
