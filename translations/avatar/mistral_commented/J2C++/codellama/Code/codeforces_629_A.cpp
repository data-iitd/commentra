// Including the necessary header files
#include <iostream>
#include <string>
#include <vector>

// Defining the main function
int main ( ) {

    // Declaring and initializing the variables 'num' and 'fine'
    int num = 0 ;
    int fine = 0 ;

    // Reading the number of strings 'num' from the user input
    std::cin >> num ;

    // Declaring and initializing an ArrayList of strings 'arr' with a size equal to 'num'
    std::vector < std::string > arr ( num ) ;

    // Reading each string 's' from the user input and adding it to the ArrayList 'arr'
    for ( int i = 0 ; i < num ; i ++ ) {
        std::string s ;
        std::cin >> s ;
        arr.push_back ( s ) ;
    }

    // Declaring and initializing two variables 'counter' and 'fine'
    int counter = 0 ;
    int fine = 0 ;

    // The first nested loop to iterate through each character in each string
    for ( int i = 0 ; i < num ; i ++ ) {
        for ( int k = 0 ; k < num ; k ++ ) {
            // Checking if the character at position (i,k) in the string at index 'i' is 'C'
            if ( arr.at ( i ).at ( k ) == 'C' ) {
                // Incrementing the counter variable
                counter ++ ;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += ( counter * ( counter - 1 ) ) / 2 ;
        // Resetting the counter variable for the next string
        counter = 0 ;
    }

    // The second nested loop to iterate through each character in each string again
    for ( int i = 0 ; i < num ; i ++ ) {
        for ( int k = 0 ; k < num ; k ++ ) {
            // Checking if the character at position (i,k) in the string at index 'k' is 'C'
            if ( arr.at ( k ).at ( i ) == 'C' ) {
                // Incrementing the counter variable
                counter ++ ;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += ( counter * ( counter - 1 ) ) / 2 ;
        // Resetting the counter variable for the next string
        counter = 0 ;
    }

    // Printing the final result 'fine'
    std::cout << fine << std::endl ;

    // Closing the main function
    return 0 ;

    // Closing the main class 'Main'
}

