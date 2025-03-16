#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Create a vector to store the input
    vector<string> input_array;
    
    // Read a line of input, split it into an array of strings based on spaces
    string line;
    getline(cin, line);
    input_array = split(line, " ");
    
    // Initialize a counter to keep track of the number of non-zero inputs
    int result = 0;
    
    // Iterate through each string in the input array
    for (string str : input_array) {
        // Increment the counter for each input
        result += 1;
        
        // If the input is "0", break out of the loop
        if ("0" == str) break;
    }
    
    // Print the result, which is the count of non-zero inputs before the first "0"
    cout << result << endl;
    
    return 0;
}

