#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    // Read the number of items (n) from the input
    int n;
    cin >> n;
    
    // Read the values (vStr) from the input and convert to a list
    string vStr;
    cin >> vStr;
    map<int, int> vList = str2List(vStr);
    
    // Read the costs (cStr) from the input and convert to a list
    string cStr;
    cin >> cStr;
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
}

// Helper method to convert a space-separated string of integers into a Map
map<int, int> str2List(string str) {
    // Split the input string into an array of strings
    vector<string> vArrStr = split(str);
    
    // Create a Map to hold the integer values with their corresponding indices
    map<int, int> ret;
    int key = 0;
    
    // Populate the Map with values from the array
    for (string val : vArrStr) {
        ret[key] = stoi(val);
        key++;
    }
    
    // Return the populated Map
    return ret;
}

// Helper method to split a string into a vector of strings
vector<string> split(string str) {
    vector<string> ret;
    int start = 0;
    int end = 0;
    while (end < str.length()) {
        while (end < str.length() && str[end]!='') {
            end++;
        }
        ret.push_back(str.substr(start, end - start));
        start = end + 1;
        end = start;
    }
    return ret;
}

