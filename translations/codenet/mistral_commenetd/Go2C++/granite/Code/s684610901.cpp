
#include <bits/stdc++.h>
using namespace std;

// Define a custom type 'pair' for sorting
struct pair {
    int64_t index;
    int64_t p1, p2;
};

// Define a slice type 'pairs' for sorting 'pair' type
typedef vector<pair> pairs;

// Implement sort.Interface methods for 'pairs' type
bool operator<(const pair &a, const pair &b) {
    return a.index < b.index;
}

// Define a custom type 'Int64Slice' for sorting int64 slices
typedef vector<int64_t> Int64Slice;

// Implement sort.Interface methods for 'Int64Slice' type
bool operator<(const Int64Slice &a, const Int64Slice &b) {
    return a[0] < b[0];
}

// Define some constants
const int64_t initialBufSize = 1e4; // Initial buffer size for bufio.NewScanner
const int64_t maxBufSize = 1e8; // Maximum buffer size for bufio.NewScanner
const int64_t INF = 1e8; // Infinite value for some calculations

// Initialize some global variables
vector<int64_t> di = {-1, 0, 1, 0}; // Direction vectors for 2D grid traversal
vector<int64_t> dj = {0, -1, 0, 1}; // Direction vectors for 2D grid traversal

// Main function
int main() {
    // Initialize the buffer with the given size
    char buf[initialBufSize];
    scanf("%s", buf);
    string input(buf);
    stringstream ss(input);

    // Read input A, B, and C
    int64_t A, B, C;
    ss >> A >> B >> C;

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        cout << "Yes" << endl; // Print "Yes" if condition is true
    } else {
        cout << "No" << endl;  // Print "No" if condition is false
    }
}

// Helper functions for reading input
bool NextPermutation(vector<int64_t>& x) {
    // Implementation of next permutation algorithm for sorting
}

vector<vector<int64_t>> doubleAry(int64_t h, int64_t w, int64_t init) {
    // Function to initialize a 2D int64 array with given dimensions and initial value
}

bool aryEq(vector<int64_t>& a, vector<int64_t>& b) {
    // Function to check if two arrays are equal
}

vector<int64_t> clone(vector<int64_t>& n) {
    // Function to clone a vector
}

void write(string s) {
    // Function to write a string to the output
}

void print() {
    // Function to flush the output
}

string readLine() {
    // Function to read a line from the input
}

int64_t readInt() {
    // Function to read an integer from the input
}

float readFloat() {
    // Function to read a float from the input
}

vector<rune> readRunes() {
    // Function to read a rune slice from the input
}

string readString() {
    // Function to read a string from the input
}

vector<string> readStrings() {
    // Function to read a string slice from the input
}

int64_t s2i(string s) {
    // Function to convert a string to an integer
}

string i2s(int64_t i) {
    // Function to convert an integer to a string
}

int64_t abs(int64_t i) {
    // Function to get the absolute value of an integer
}

int64_t max(vector<int64_t>& i) {
    // Function to get the maximum value from a vector of integers
}

int64_t min(vector<int64_t>& i) {
    // Function to get the minimum value from a vector of integers
}

int64_t sum(vector<int64_t>& i) {
    // Function to get the sum of elements in a vector of integers
}

vector<string> split(string s) {
    // Function to split a string into a vector of strings using space as delimiter
}

vector<int64_t> strAry2intAry(vector<string>& strs) {
    // Function to convert a vector of strings to a vector of integers
}

vector<string> intAry2strAry(vector<int64_t>& nums) {
    // Function to convert a vector of integers to a vector of strings
}

string ary2str(vector<string>& strs) {
    // Function to join a vector of strings into a single string using space as delimiter
}

vector<int64_t> reverse(vector<int64_t>& res) {
    // Function to reverse the order of elements in a vector
}

vector<string> reverseStr(vector<string>& res) {
    // Function to reverse the order of elements in a vector of strings
}

void ini(vector<int>& res, int init) {
    // Function to initialize the first element of a vector with a given value
}

// Uncomment the following code if you want to use regexp package
// void regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r("(\\d+):(\\d+)");
//     smatch m;
//     regex_search(str, m, r);
//     cout << m[1] << endl;
//     cout << m[2] << endl;
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// struct Country {
//     int64_t gold;
//     int64_t silver;
//     int64_t blonze;
// };

// Function to sort a vector of 'Country' based on bronze, silver, and gold fields in that order
// vector<Country> stableSortExample() {
//     // Your code here!
// }
