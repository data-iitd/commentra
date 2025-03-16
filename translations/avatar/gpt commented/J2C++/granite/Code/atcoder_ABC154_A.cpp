
#include <iostream> 
#include <string> 
#include <vector> 
#include <sstream> 

using namespace std; 

int main() { 
    // Create a stringstream to read input from the standard input stream
    stringstream ss; 
    ss << R"(1 2
3 4
5)"; 
    
    // Read a line of input, split it by spaces, and store it in a vector of strings
    vector<string> str; 
    string line; 
    getline(ss, line); 
    stringstream ss2(line); 
    string word; 
    while (ss2 >> word) { 
        str.push_back(word); 
    } 
    
    // Read another line of input and store it in variable 'u'
    string u; 
    getline(ss, u); 
    
    // Compare the string 'u' with the first element of the vector'str'
    // Print the result based on the comparison
    if (u == str[0]) { 
        cout << (stoi(str[0]) - 1) << " " << stoi(str[1]) << endl; 
    } else { 
        cout << stoi(str[0]) << " " << (stoi(str[1]) - 1) << endl; 
    } 
    
    return 0; 
}

