#include <iostream> // Including the iostream library for input and output
#include <sstream>  // Including the sstream library for string stream
#include <map>      // Including the map library for using maps
#include <vector>   // Including the vector library for using vectors
#include <string>   // Including the string library for using strings

using namespace std; // Using the standard namespace

map<int, int> str2List(const string& str) { // Defining the str2List function that converts a string representation of an array to a map
    map<int, int> ret; // Creating an empty map to store the key-value pairs
    stringstream ss(str); // Creating a string stream from the input string
    string val; // Variable to hold each value from the string stream
    int key = 0; // Initializing the key variable to 0

    while (ss >> val) { // Reading values from the string stream
        ret[key] = stoi(val); // Adding each value to the map as a key-value pair, where the key is an integer and the value is the integer value of the string
        key++; // Incrementing the key variable for the next iteration
    }

    return ret; // Returning the map
}

int main() { // Defining the main function
    int n; // Variable to hold the number of elements
    cin >> n; // Reading the first line of input which is an integer representing the number of elements in the arrays
    cin.ignore(); // Ignoring the newline character after the integer input

    string vStr; // Variable to hold the values string
    getline(cin, vStr); // Reading the second line of input which is a string representing the values array
    map<int, int> vList = str2List(vStr); // Converting the string representation of the values array to a map using the str2List function

    string cStr; // Variable to hold the costs string
    getline(cin, cStr); // Reading the third line of input which is a string representing the costs array
    map<int, int> cList = str2List(cStr); // Converting the string representation of the costs array to a map using the str2List function

    int max = 0; // Initializing the variable max to 0

    for (int i = 0; i < n; i++) { // Iterating through each element in the arrays using a for loop
        int profit = vList[i] - cList[i]; // Calculating the profit for the current element by subtracting the cost from the value
        if (profit > 0) { // Checking if the profit is positive
            max += profit; // If the profit is positive, adding it to the max variable
        }
    }

    cout << max << endl; // Printing the maximum profit to the standard output stream
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
