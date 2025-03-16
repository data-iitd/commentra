
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

// Function to read a line of text from stdin and return it as a string
string NextLine() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read a line of text consisting of integers separated by spaces from stdin.
// It then converts these strings to integers and returns them as a vector of integers.
vector<int> NextIntsLine() {
    vector<int> ints;
    string intsStr = NextLine(); // Read the line of integers
    string tmp;
    size_t pos = 0;
    while ((pos = intsStr.find(" "))!= string::npos) {
        string integerStr = intsStr.substr(0, pos); // Extract the integer string
        intsStr.erase(0, pos + 1); // Remove the integer string from the original string
        int integer = stoi(integerStr); // Convert the integer string to an integer
        ints.push_back(integer); // Append the integer to the vector
    }
    ints.push_back(stoi(intsStr)); // Append the last integer to the vector
    return ints;
}

// Function to read a line of text consisting of strings separated by spaces from stdin.
// It returns these strings as a vector of strings.
vector<string> NextStringsLine() {
    vector<string> strs;
    string strsStr = NextLine(); // Read the line of strings
    string tmp;
    size_t pos = 0;
    while ((pos = strsStr.find(" "))!= string::npos) {
        string str = strsStr.substr(0, pos); // Extract the string
        strsStr.erase(0, pos + 1); // Remove the string from the original string
        strs.push_back(str); // Append the string to the vector
    }
    strs.push_back(strsStr); // Append the last string to the vector
    return strs;
}

// Function to read a line of text consisting of characters arranged continuously from stdin.
// It returns these characters as a vector of runes.
vector<rune> NextRunesLine() {
    string runesStr = NextLine(); // Read the line of characters
    vector<rune> runes(runesStr.begin(), runesStr.end()); // Convert the string to a vector of runes
    return runes;
}

// Function to find the maximum integer from a variable number of input integers.
// This function requires at least one argument, otherwise it will panic.
int Max(int a, int b) {
    return a > b? a : b; // Return the maximum of the two integers
}

// Function to find the minimum integer from a variable number of input integers.
// This function requires at least one argument, otherwise it will panic.
int Min(int a, int b) {
    return a < b? a : b; // Return the minimum of the two integers
}

// Function to calculate the power of an integer base raised to an integer exponent.
// It panics if either argument is negative.
int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        throw runtime_error("[argument error]: PowInt does not accept negative integers");
    }
    return pow(a, e); // Return the result of raising a to the power of e
}

// Function to calculate the absolute value of an integer.
int AbsInt(int a) {
    return abs(a); // Return the absolute value of a
}

// Function to remove an element at a specified index from a vector of integers.
// It returns a new vector with the element removed.
vector<int> DeleteElement(vector<int> s, int i) {
    if (i < 0 || i >= s.size()) {
        throw runtime_error("[index error]"); // Throw an exception if the index is out of bounds
    }
    vector<int> n(s.begin(), s.begin() + i); // Create a new vector with elements before the index
    n.insert(n.end(), s.begin() + i + 1, s.end()); // Append elements after the index
    return n; // Return the new vector
}

// Function to concatenate two vectors of runes and return a new vector.
vector<rune> Concat(vector<rune> s, vector<rune> t) {
    vector<rune> n(s.begin(), s.end()); // Create a new vector with elements from s
    n.insert(n.end(), t.begin(), t.end()); // Append elements from t
    return n; // Return the concatenated vector
}

int main() {
    vector<int> tmp = NextIntsLine(); // Read a line of integers
    int x = tmp[0]; // Store the first integer in variable x
    int i = 1; // Initialize counter
    int sum = 0; // Initialize sum
    while (sum < x) { // Check if sum has not reached x
        sum += i; // Incrementally add to sum
        i++; // Increment counter
    }
    cout << i << endl; // Print the result
    return 0;
}

