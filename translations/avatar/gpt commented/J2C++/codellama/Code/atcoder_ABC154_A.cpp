#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <cstdlib> 

using namespace std; 

int main() { 
    // Create a string to store the input
    string input; 
    
    // Read the input from the standard input stream
    getline(cin, input); 
    
    // Create a stringstream to read the input string
    stringstream ss(input); 
    
    // Create a vector to store the input as integers
    vector<int> v; 
    
    // Read the input from the stringstream and store it in the vector
    int temp; 
    while (ss >> temp) { 
        v.push_back(temp); 
    } 
    
    // Read another line of input from the standard input stream
    getline(cin, input); 
    
    // Create a stringstream to read the input string
    stringstream ss2(input); 
    
    // Read the input from the stringstream and store it in a string
    string u; 
    ss2 >> u; 
    
    // Compare the string 'u' with the first element of the vector 'v'
    // Print the result based on the comparison
    cout << (u.compare(to_string(v[0])) == 0 ? to_string(v[1] - 1) + " " + to_string(v[2]) : to_string(v[1]) + " " + to_string(v[2] - 1)) << endl; 
    
    return 0; 
} 

