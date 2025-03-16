#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Constants for modulus
const int mod = 1e9 + 7;

// Function to read a string from input
string getString() {
    string s;
    cin >> s; // Read the string from standard input
    return s; // Return the string
}

// Function to compute the absolute value of an integer
int abs(int a) {
    return std::abs(a); // Use std::abs to get the absolute value
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
    return static_cast<int>(std::pow(p, q)); // Use std::pow for exponentiation
}

// Function to find the minimum value among given integers
int min(int a, int b) {
    return std::min(a, b); // Use std::min to find the minimum
}

// Function to find the maximum value among given integers
int max(int a, int b) {
    return std::max(a, b); // Use std::max to find the maximum
}

// Function to check if a string exists in a vector of strings
bool strSearch(const vector<string>& a, const string& b) {
    return std::find(a.begin(), a.end(), b) != a.end(); // Check if b is in a
}

// Function to print an array of integers
void printIntArray(const vector<int>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        cout << array[i];
        if (i < array.size() - 1) {
            cout << " "; // Print space between elements
        }
    }
    cout << endl; // Print newline at the end
}

// Function to calculate the modulus of x with respect to the defined mod
int calcMod(int x) {
    return x % mod; // Return the result of x modulo mod
}

int main() {
    // Array representing the days of the week
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    // Get the input day as a string
    string s = getString();
    int index = -1; // Initialize index to -1 to indicate not found

    // Search for the input day in the week array
    for (size_t i = 0; i < week.size(); ++i) {
        if (s == week[i]) {
            index = static_cast<int>(i); // Update index if the day is found
            break;
        }
    }

    // Calculate and print the number of days until the next Sunday
    cout << (7 - index) << endl;

    return 0; // Return success
}

// <END-OF-CODE>
