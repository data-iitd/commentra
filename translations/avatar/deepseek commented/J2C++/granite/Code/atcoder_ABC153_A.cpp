

#include <iostream> // Importingiostream for input and output operations
#include <string> // Importing string for string manipulation
#include <cstdlib> // Importing cstdlib for using atoi function

using namespace std;

int main() {
    string input; // Declaring a string variable to store input
    getline(cin, input); // Reading input from the user
    stringstream ss(input); // Creating a stringstream object to parse the input
    string str1, str2; // Declaring two string variables to store the parsed elements
    getline(ss, str1,''); // Parsing the first element from the input
    getline(ss, str2); // Parsing the second element from the input
    int h = atoi(str1.c_str()); // Converting the first element to an integer representing the height
    int a = atoi(str2.c_str()); // Converting the second element to an integer representing the amount to subtract
    int num = 0; // Initializing a counter to keep track of the number of subtractions

    // Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
    for (int i = 1; h > 0; i++) {
        h = h - a; // Subtracting 'a' from 'h'
        num++; // Incrementing the counter
    }

    cout << num << endl; // Printing the result, which is the number of subtractions

    return 0; // Returning 0 to indicate successful execution
}

