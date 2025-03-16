#include <iostream>  // Including the iostream library for input and output
#include <vector>    // Including the vector library for dynamic array
#include <sstream>   // Including the sstream library for string stream
#include <string>    // Including the string library for string manipulation

using namespace std;  // Using the standard namespace

int main() {  // Main function definition
    vector<string> scList;  // Creating an empty vector to store the input lines
    string line;  // Variable to hold each line of input

    // The following loop reads input lines from the console and stores them in the vector
    while (getline(cin, line)) {  // Reading a line from the console
        scList.push_back(line);  // Adding the line to the vector
    }

    // The following line extracts the first line of the input (which contains the number of sheep and wolves)
    stringstream ss(scList[0]);  // Creating a string stream from the first line
    int Sheep, Wolve;  // Variables to hold the number of sheep and wolves

    // The following lines parse the first two integers from the string stream
    ss >> Sheep >> Wolve;

    // The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
    // If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
    if (Wolve >= Sheep) {
        cout << "unsafe" << endl;  // Printing the message "unsafe" to the console
    } else {
        cout << "safe" << endl;  // Printing the message "safe" to the console
    }

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
