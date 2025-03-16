#include <iostream> 
#include <string> 
#include <vector> 
#include <sstream> 

using namespace std; 

// Function to read a specified number of lines from input
vector<string> read(int len) { 
    vector<string> strList; 
    string line; 
    for (int i = 0; i < len; i++) { 
        getline(cin, line); 
        strList.push_back(line); 
    } 
    return strList; 
} 

// Function to close the BufferedReader
void close() { 
    // Close the BufferedReader if it is not null
    if (br != null) { 
        br.close(); 
    } 
} 

int main() { 
    // Read the first input as an integer
    int n = stoi(read(1)[0]); 
    
    // Check if the input is 1
    if (n == 1) { 
        // If the input is 1, print "Hello World"
        cout << "Hello World" << endl; 
    } else { 
        // If the input is not 1, read two more strings
        vector<string> strs = read(2); 
        // Parse the two strings as integers and print their sum
        cout << stoi(strs[0]) + stoi(strs[1]) << endl; 
    } 
    return 0; 
} 

