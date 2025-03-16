#include <stdio.h>
#include <string.h>

public class Main {
    public static void main(String[] args) {
        // Declare a buffer to hold the input string and an integer to store its length
        char buf[512];
        int len;

        // Read a line of input from standard input (stdin) into the buffer
        fgets(buf, sizeof(buf), stdin);

        // Calculate the length of the input string
        len = strlen(buf);

        // Print the first character, the length of the string minus 3, and the second to last character
        System.out.println(buf[0] + len - 3 + buf[len - 2]);

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}

