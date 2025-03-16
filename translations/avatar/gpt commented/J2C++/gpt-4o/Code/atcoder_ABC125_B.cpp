#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

// Helper function to convert a space-separated string of integers into a map
map<int, int> str2List(const string& str) {
    map<int, int> ret;
    istringstream iss(str);
    string val;
    int key = 0;

    while (iss >> val) {
        ret[key] = stoi(val);
        key++;
    }

    return ret;
}

int main() {
    // Create a variable to read the number of items (n) from the input
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character after the integer input

    // Read the values (vStr) from the input and convert to a map
    string vStr;
    getline(cin, vStr);
    map<int, int> vList = str2List(vStr);

    // Read the costs (cStr) from the input and convert to a map
    string cStr;
    getline(cin, cStr);
    map<int, int> cList = str2List(cStr);

    // Initialize a variable to keep track of the maximum profit
    int maxProfit = 0;

    // Calculate the profit for each item and sum up the positive profits
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        // Only add to maxProfit if the profit is positive
        if (profit > 0) {
            maxProfit += profit;
        }
    }

    // Output the total maximum profit
    cout << maxProfit << endl;

    return 0;
}

// <END-OF-CODE>
