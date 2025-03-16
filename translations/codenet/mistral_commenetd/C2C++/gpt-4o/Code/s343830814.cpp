#include <iostream>
#include <cstring>

/* The main function is the entry point of the program */
int main(int argc, char *argv[])
{
    /* Declare a character array 'buf' of size 512 */
    char buf[512];

    /* Declare an integer variable 'len' to store the length of the string read */
    int len;

    /* Read a line from standard input using std::cin and store it in 'buf' */
    std::cin.getline(buf, sizeof(buf));

    /* Calculate the length of the string read and store it in 'len' */
    len = std::strlen(buf);

    /* Print the first character of the string, its length (minus 3), and the last character of the string */
    std::cout << buf[0] << (len - 3) << buf[len - 2] << std::endl;

    /* Return 0 to indicate successful execution of the program */
    return 0;
}

/* <END-OF-CODE> */
