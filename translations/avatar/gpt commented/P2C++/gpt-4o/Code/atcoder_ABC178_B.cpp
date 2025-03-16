#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

// Define a large constant for infinity
const long long inf = 1e20;

// Define a modulus value commonly used in competitive programming
const int mod = 1e9 + 7;

// Function to read a line of input and return it as a vector of integers
vector<int> readLineAsIntVector() {
    string line;
    getline(cin, line);
    vector<int> result;
    int number;
    istringstream iss(line);
    while (iss >> number) {
        result.push_back(number);
    }
    return result;
}

// Function to read a single integer from input
int readInt() {
    int number;
    cin >> number;
    return number;
}

// Function to read a single float from input
float readFloat() {
    float number;
    cin >> number;
    return number;
}

// Function to read a line of input and return it as a vector of strings
vector<string> readLineAsStringVector() {
    string line;
    getline(cin, line);
    vector<string> result;
    istringstream iss(line);
    string word;
    while (iss >> word) {
        result.push_back(word);
    }
    return result;
}

// Function to read a single string from input
string readString() {
    string str;
    cin >> str;
    return str;
}

// Main function to execute the core logic of the program
int main() {
    // Read four integers from input
    vector<int> inputs = readLineAsIntVector();
    int a = inputs[0], b = inputs[1], c = inputs[2], d = inputs[3];
    
    // Calculate the maximum value from the products of the pairs and return it
    cout << max({a * c, b * d, a * d, b * c}) << endl;

    return 0;
}

// <END-OF-CODE>
