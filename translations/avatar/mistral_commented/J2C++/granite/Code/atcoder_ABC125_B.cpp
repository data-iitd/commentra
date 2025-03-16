

#include <iostream> // Including the standard input/output stream objects iostream and ostream
#include <string> // Including the string class string
#include <map> // Including the map container from the standard template library
#include <sstream> // Including the string stream class stringstream

using namespace std ; // Using the standard namespace

int main ( ) { // Defining the main function that is executed when the program is run
    string line ; // Declaring a string variable line to store the input lines
    getline ( cin, line ) ; // Reading the first line of input which is an integer representing the number of elements in the arrays
    int n = stoi ( line ) ; // Converting the string representation of the number of elements to an integer using the stoi function

    getline ( cin, line ) ; // Reading the second line of input which is a string representing the values array
    stringstream ss ( line ) ; // Creating a string stream object ss to parse the string representation of the values array
    map<int, int> vList ; // Creating an empty map to store the key-value pairs of the values array
    int key = 0 ; // Initializing the key variable to 0
    int val ; // Declaring an integer variable val to store the value of each element in the values array

    while ( ss >> val ) { // Parsing the string representation of the values array using the >> operator and storing the values in the val variable
        vList[key] = val ; // Adding each value to the map as a key-value pair, where the key is an integer and the value is the integer value of the string
        key++ ; // Incrementing the key variable for the next iteration
    }

    getline ( cin, line ) ; // Reading the third line of input which is a string representing the costs array
    stringstream sc ( line ) ; // Creating a string stream object sc to parse the string representation of the costs array
    map<int, int> cList ; // Creating an empty map to store the key-value pairs of the costs array

    while ( sc >> val ) { // Parsing the string representation of the costs array using the >> operator and storing the values in the val variable
        cList[key] = val ; // Adding each value to the map as a key-value pair, where the key is an integer and the value is the integer value of the string
        key++ ; // Incrementing the key variable for the next iteration
    }

    int max = 0 ; // Initializing the variable max to 0

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each element in the arrays using a for loop
        int profit = vList[i] - cList[i] ; // Calculating the profit for the current element by subtracting the cost from the value
        if ( profit > 0 ) { // Checking if the profit is positive
            max += profit ; // If the profit is positive, adding it to the max variable
        }
    }

    cout << max << endl ; // Printing the maximum profit to the standard output stream

    return 0 ; // Returning 0 to indicate successful program execution
}



