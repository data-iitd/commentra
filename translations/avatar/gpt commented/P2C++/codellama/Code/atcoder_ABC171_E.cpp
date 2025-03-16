#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    // Read an integer input N (not used in further calculations)
    int N;
    cin >> N;

    // Read a list of integers from input and convert them to a list of integers
    vector<int> a;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int temp;
    while (ss >> temp) {
        a.push_back(temp);
    }

    // Calculate the total using the XOR operation across all elements in the list 'a'
    int total = 0;
    for (int i = 0; i < a.size(); i++) {
        total ^= a[i];
    }

    // For each element in the list 'a', compute the XOR with 'total' and print the results
    // The results are converted to strings and joined with a space for output
    for (int i = 0; i < a.size(); i++) {
        cout << (a[i] ^ total) << " ";
    }

    // End of code
    cout << "