
// Include necessary C++ libraries
#include <iostream> // For reading input
#include <vector> // For handling arrays

// Main function is the entry point of the program
int main ( ) {
    // Declare a vector to store the array of integers
    std::vector < int > a ;

    // Read the length of the array from the user input
    int len ;
    std::cin >> len ;

    // Read each integer from the user input and store it in the vector
    for ( int i = 0 ; i < len ; i ++ ) {
        int temp ;
        std::cin >> temp ;
        a.push_back ( temp ) ;
    }

    // Initialize variables for left and right indices and a flag
    int l = 0 ;
    int r = 0 ;
    bool flag = false ;

    // Start the loop to search for two non-consecutive numbers
    for ( int i = 0 ; i < len ; i ++ ) {

        // Check if the current number is not in its correct position
        if ( a [ i ]!= i + 1 &&! flag ) {
            // Update the left index
            l = i + 1 ;
            // Set the flag to true to indicate that we have found the first non-consecutive number
            flag = true ;
            // Continue to the next iteration of the loop
            continue ;
        }

        // Check if the current number is also not in its correct position and the flag is set
        if ( a [ i ]!= i + 1 && flag ) {
            // Update the right index
            r = i + 1 ;

            // Check if the difference between the previous number and the current number is greater than 1
            if ( ( a [ r - 1 ] - a [ r - 2 ] > 0 ) ) {
                // Set the isTrue flag to true if the condition is satisfied
                isTrue = true ;
                // Break out of the loop if the flag is set to true
                break ;
            }
        }
    }

    // Print the result based on the value of the isTrue flag
    std::cout << ( (! isTrue )? l + " " + r : "0" + " " + "0" ) << std::endl ;

    // End of the code
    return 0 ;
}
