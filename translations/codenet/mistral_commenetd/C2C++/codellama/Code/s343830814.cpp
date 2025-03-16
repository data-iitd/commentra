#include <iostream>
#include <string>

/* The main function is the entry point of the program */
int main()
{
    /* Declare a string variable 'str' to store the input string */
    std::string str;

    /* Read a line from standard input using getline() and store it in 'str' */
    getline(std::cin, str);

    /* Print the first character of the string, its length (minus 3), and the last character of the string */
    std::cout << str[0] << str.length()-3 << str[str.length()-2] << std::endl;

    /* Return 0 to indicate successful execution of the program */
    return 0;
}

