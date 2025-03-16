
#include <stdio.h>  // Include the standard input/output library
#include <stdlib.h>  // Include the standard library for memory allocation and deallocation
#include <string.h>  // Include the standard library for string manipulation

int main ( void ) {  // Main function definition
    char line [ 1024 ] ;  // Declare a character array to store input lines
    char * token ;  // Declare a pointer to store tokens from the input lines
    int Sheep ;  // Declare an integer variable to store the number of sheep
    int Wolve ;  // Declare an integer variable to store the number of wolves

    // The following while loop reads input lines from the console and stores them in the line array
    while ( fgets ( line, sizeof ( line ), stdin )!= NULL ) {
        // The following line extracts the first token from the input line
        token = strtok ( line, " " ) ;

        // The following if statement checks if the token is not NULL
        if ( token!= NULL ) {
            // The following line converts the token to an integer and stores it in the Sheep variable
            Sheep = atoi ( token ) ;

            // The following line extracts the second token from the input line
            token = strtok ( NULL, " " ) ;

            // The following if statement checks if the token is not NULL
            if ( token!= NULL ) {
                // The following line converts the token to an integer and stores it in the Wolve variable
                Wolve = atoi ( token ) ;

                // The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
                // If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
                if ( Wolve >= Sheep ) {
                    printf ( "unsafe\n" ) ;  // Printing the message "unsafe" to the console
                } else {
                    printf ( "safe\n" ) ;  // Printing the message "safe" to the console
                }
            }
        }
    }

    return 0 ;  // Return 0 to indicate successful program execution
}
