
#include <iostream> // Including the necessary libraries for input/output operations
#include <string> // Including the necessary library for string manipulation
#include <sstream> // Including the necessary library for string stream operations
#include <iomanip> // Including the necessary library for formatting output
#include <ctime> // Including the necessary library for working with time

using namespace std; // Using the standard namespace for the code

int main() { // Main function
    string s, t; // Declaring two string variables to store the input time strings
    getline(cin, s); // Reading the first time input from the console
    getline(cin, t); // Reading the second time input from the console
    
    // Creating time_t objects from the input strings for the first and second time
    time_t x = chrono::system_clock::to_time_t(chrono::system_clock::now()); // Getting the current system time
    stringstream ss(s); // Creating a stringstream object to parse the input string for the first time
    tm timeStruct = {}; // Creating a tm object to store the parsed time components
    ss >> get_time(&timeStruct, "%H:%M"); // Parsing the input string for the first time and storing the components in the tm object
    x = mktime(&timeStruct); // Converting the tm object to a time_t object for the first time
    
    stringstream tt(t); // Creating a stringstream object to parse the input string for the second time
    tm timeStruct2 = {}; // Creating a tm object to store the parsed time components
    tt >> get_time(&timeStruct2, "%H:%M"); // Parsing the input string for the second time and storing the components in the tm object
    time_t y = mktime(&timeStruct2); // Converting the tm object to a time_t object for the second time
    
    // Calculating the difference between the two times and printing the result
    cout << fixed << setprecision(0) << difftime(x, y) / 60 << endl; // Calculating the difference in minutes and printing the result
    
    return 0; // Returning 0 to indicate successful execution of the program
}

