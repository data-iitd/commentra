#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function to read a specified number of long lines from standard input
vector<string> ReadLongLines(int times) {
    vector<string> result(times);
    string line;

    // Loop to read the specified number of lines
    for (int i = 0; i < times; i++) {
        if (getline(cin, line)) {
            result[i] = line; // Store the complete line in the result
        } else {
            break; // Break if EOF is reached
        }
    }
    return result; // Return the lines read
}

// Function to print a list of integers to the console
void PrintList(const vector<int>& list) {
    for (size_t i = 0; i < list.size(); i++) {
        if (i == 0) {
            cout << list[i]; // Print the first element without a leading space
        } else {
            cout << " " << list[i]; // Print subsequent elements with a leading space
        }
    }
    cout << endl; // Print a newline after the list
}

// Main function where the program execution begins
int main() {
    unordered_set<int> uniqueIntegers; // Create a set to track unique integers
    vector<string> lines = ReadLongLines(4); // Read 4 lines from input
    istringstream secondLineStream(lines[1]);
    string number;

    // Convert strings to integers and store them in the set
    while (secondLineStream >> number) {
        uniqueIntegers.insert(stoi(number)); // Convert string to integer and add to the set
    }

    vector<int> result; // Vector to hold the result integers
    istringstream fourthLineStream(lines[3]);

    // Process the integers from the fourth line
    while (fourthLineStream >> number) {
        int n = stoi(number); // Convert string to integer
        if (uniqueIntegers.count(n)) { // Check if the integer exists in the set
            uniqueIntegers.erase(n); // Remove it from the set if it exists
        } else {
            uniqueIntegers.insert(n); // Add it to the set if it does not exist
        }
    }

    // Collect remaining integers from the set into the result vector
    for (const int& k : uniqueIntegers) {
        result.push_back(k); // Append the key to the result vector
    }

    // Sort the result vector in ascending order
    sort(result.begin(), result.end());

    // Print the sorted result
    PrintList(result); // Print each integer in the result

    return 0; // End of the program
}

// <END-OF-CODE>
