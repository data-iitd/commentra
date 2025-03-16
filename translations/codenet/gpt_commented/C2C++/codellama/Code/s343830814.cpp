#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // Declare a string to hold the input string and an integer to store its length
    std::string str;
    int len;

    // Read a line of input from standard input (stdin) into the string
    std::getline(std::cin, str);

    // Calculate the length of the input string
    len = str.length();

    // Print the first character, the length of the string minus 3, and the second to last character
    std::cout << str[0] << len-3 << str[len-2] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

