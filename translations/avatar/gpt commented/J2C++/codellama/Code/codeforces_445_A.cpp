#include <iostream> 
#include <string> 
#include <sstream> 

using namespace std; 

int main() { 
    // Create a stringstream to read input from the console
    stringstream buf; 
    
    // Read the first line of input and split it into an array of strings
    string inp; 
    getline(cin, inp); 
    stringstream ss(inp); 
    string temp; 
    vector<string> v; 
    while (ss >> temp) 
        v.push_back(temp); 
    
    // Parse the first two elements of the input array as integers n and m
    int n = stoi(v[0]); 
    int m = stoi(v[1]); 
    
    // Initialize an array to hold the resulting strings
    string ans[n]; 
    
    // Loop through each of the n lines of input
    for (int i = 0; i < n; i++) { 
        // Read the current line of input
        getline(cin, inp); 
        
        // Create a stringstream to construct the output for the current line
        stringstream temp; 
        
        // Loop through each character in the current line
        for (int j = 0; j < m; j++) 
            // Check if the character is a '-'
            if (inp[j] == '-') 
                // Append '-' to the stringstream if it is
                temp << "-"; 
            else { 
                // If the character is not '-', determine whether to append 'W' or 'B'
                if ((i + j) % 2 == 1) 
                    temp << "W"; // Append 'W' for odd indices
                else 
                    temp << "B"; // Append 'B' for even indices
            } 
        // Store the constructed string in the ans array
        ans[i] = temp.str(); 
    } 
    
    // Output the resulting strings line by line
    for (int i = 0; i < n; i++) { 
        cout << ans[i] << endl; 
    } 
    
    return 0; 
}

