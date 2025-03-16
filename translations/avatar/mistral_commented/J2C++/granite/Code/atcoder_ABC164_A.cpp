
#include <iostream>  // Importing the C++ standard input/output stream objects
#include <vector>  // Importing the C++ standard vector container
#include <string>  // Importing the C++ standard string container

using namespace std;  // Declaring the standard namespace as the current namespace

int main ( ) {  // Main function definition
    vector < string > scList;  // Creating an empty vector to store the input lines
    string line;  // Creating a string variable to store the input line

    // The following while loop reads input lines from the console and stores them in the vector
    while ( getline ( cin, line ) ) {
        scList.push_back ( line ) ;  // Reading the next line from the console and adding it to the vector
    }

    // The following line extracts the first line of the input (which contains the number of sheep and wolves)
    string numlist = scList [ 0 ] ;

    // The following two lines parse the first two elements of the numlist string as integers representing the number of sheep and wolves
    int Sheep = stoi ( numlist.substr ( 0, numlist.find ( " " ) ) ;
    int Wolve = stoi ( numlist.substr ( numlist.find ( " " ) + 1 ) ) ;

    // The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
    // If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
    if ( Wolve >= Sheep ) {
        cout << "unsafe" << endl ;  // Printing the message "unsafe" to the console
    } else {
        cout << "safe" << endl ;  // Printing the message "safe" to the console
    }

    return 0;  // Returning 0 to indicate successful program execution
}

