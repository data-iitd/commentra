#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> str2List(const string& str) {
    unordered_map<int, int> ret;
    stringstream ss(str);
    string val;
    int key = 0;
    while (ss >> val) {
        ret[key++] = stoi(val);
    }
    return ret;
}

int main() {
    // Step 1: Read the input value `n` which represents the number of elements.
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    // Step 2: Read the values of `v` (values) and store them in a map `vList`.
    string vStr;
    getline(cin, vStr);
    unordered_map<int, int> vList = str2List(vStr);

    // Step 3: Read the values of `c` (costs) and store them in a map `cList`.
    string cStr;
    getline(cin, cStr);
    unordered_map<int, int> cList = str2List(cStr);

    // Step 4: Initialize a variable `max` to keep track of the maximum profit.
    int maxProfit = 0;

    // Step 5: Iterate through the elements, calculate the profit for each element, and update `max` if the profit is positive.
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            maxProfit += profit;
        }
    }

    // Step 6: Print the maximum profit.
    cout << maxProfit << endl;

    return 0;
}

// <END-OF-CODE>
