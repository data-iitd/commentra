#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // Declare a buffer to hold the input string and an integer to store its length
    std::string buf;
    int len;

    // Read a line of input from standard input (stdin) into the buffer
    std::getline(std::cin, buf);

    // Calculate the length of the input string
    len = buf.length();

    // Print the first character, the length of the string minus 3, and the second to last character
    std::cout << buf[0] << len - 3 << buf[len - 2] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}
