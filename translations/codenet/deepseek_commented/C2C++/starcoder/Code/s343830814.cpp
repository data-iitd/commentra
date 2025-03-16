#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string buf; // Define a string to store the input
    int len;          // Define an integer to store the length of the input

    // Step 3: Read input from stdin
    std::getline(std::cin, buf);

    // Step 4: Calculate the length of the input
    len = buf.length();

    // Step 5: Print the first character, the length minus 3, and the second last character of the input
    std::cout << buf[0] << len-3 << buf[len-2] << std::endl;

    // Step 6: Return 0 to indicate successful execution
    return 0;
}

