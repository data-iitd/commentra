
#include <iostream> 
#include <string> 
#include <sstream> 
#include <map> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the console
    string nStr; 
    getline(cin, nStr); 
    int n = stoi(nStr); 
    
    // Read the values (vStr) from the input and convert to a list
    string vStr; 
    getline(cin, vStr); 
    map<int, int> vList = str2List(vStr); 
    
    // Read the costs (cStr) from the input and convert to a list
    string cStr; 
    getline(cin, cStr); 
    map<int, int> cList = str2List(cStr); 
    
    // Initialize a variable to keep track of the maximum profit
    int max = 0; 
    
    // Calculate the profit for each item and sum up the positive profits
    for (int i = 0; i < n; i++) { 
        int profit = vList[i] - cList[i]; 
        // Only add to max if the profit is positive
        if (profit > 0) { 
            max += profit; 
        } 
    } 
    
    // Output the total maximum profit
    cout << max << endl; 
    return 0; 
} 

// Helper method to convert a space-separated string of integers into a Map
map<int, int> str2List(string str) { 
    // Split the input string into an array of strings
    stringstream ss(str); 
    string val; 
    map<int, int> ret; 
    int key = 0; 
    
    // Populate the Map with values from the array
    while (ss >> val) { 
        ret[key] = stoi(val); 
        key++; 
    } 
    
    // Return the populated Map
    return ret; 
} 

