
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    string line;
    getline(cin, line);
    int n = stoi(line);

    getline(cin, line);
    string vStr = line;
    map<int, int> vList = str2List(vStr);

    getline(cin, line);
    string cStr = line;
    map<int, int> cList = str2List(cStr);

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
    vector<string> vArrStr;
    stringstream ss(str);
    string token;
    while (getline(ss, token,'')) {
        vArrStr.push_back(token);
    }

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

// END-OF-CODE