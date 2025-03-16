#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Function to scan an array of integers from standard input
vector<int> scanArrayInt() {
    // Initialize an empty vector to hold the integers
    vector<int> ret;
    // Read a line from standard input
    string line;
    getline(cin, line);
    // Use a stringstream to split the input line into strings
    stringstream ss(line);
    string s;
    // Split the input line into strings and convert each to an integer
    while (ss >> s) {
        // Convert string to integer
        int i = stoi(s);
        ret.push_back(i); // Append the integer to the vector
    }
    // Return the vector of integers
    return ret;
}

int main() {
    // Read an array of integers from standard input
    vector<int> arr = scanArrayInt();
    // Assign the first two elements of the array to variables a and b
    int a = arr[0], b = arr[1];
    // Initialize the number of taps needed to 0
    int tap = 0;
    // Initialize the consent variable to 1 (the starting point)
    int consent = 1;
    
    // Loop until the consent value is less than b
    while (consent < b) {
        // Update consent by adding (a - 1) to it
        consent = consent + a - 1;
        // Increment the tap count
        tap++;
    }
    
    // Print the total number of taps needed
    cout << tap << endl;
    
    return 0;
}
