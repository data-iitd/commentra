
#include <iostream>
#include <string>

/* The main function is the entry point of the program */
int main(int argc, char *argv[])
{
    /* Declare a string variable 'buf' to store the input string */
    std::string buf;

    /* Read a line from standard input using std::getline() and store it in 'buf' */
    std::getline(std::cin, buf);

    /* Calculate the length of the string read and store it in 'len' */
    int len = buf.length();

    /* Print the first character of the string, its length (minus 3), and the last character of the string */
    std::cout << buf[0] << len-3 << buf[len-2] << std::endl;

    /* Return 0 to indicate successful execution of the program */
    return 0;
}


