#######
// Including necessary C++ libraries
#######
#include <iostream>
#include <string>
#include <sstream>

#######
// Main method is the entry point of the C++ application
#######
int main ( ) {

    // Creating a string object to read input from the console
    std::string str ;

    // Reading the first line of input as a string
    std::getline ( std::cin , str ) ;

    // Creating a stringstream object to read the second line of input as separate tokens
    std::stringstream st ;

    // Reading the second line of input as a string
    std::getline ( std::cin , str ) ;

    // Reading the second line of input as separate tokens
    st << str ;

    // Reading the first two integers as input
    int a , b ;
    st >> a >> b ;

    // Reading the third line of input as a string
    std::getline ( std::cin , str ) ;

    // Checking if the first string from the first line matches with the given string 'u'
    if ( str.compare ( 0 , str.size ( ) , str ) == 0 ) {

        // If the condition is true, then print the result as (a-1) and b
        std::cout << ( a - 1 ) << " " << b << std::endl ;

    } else {

        // If the condition is false, then print the result as a and (b-1)
        std::cout << a << " " << ( b - 1 ) << std::endl ;
    }

    // Ending the C++ code with comment "