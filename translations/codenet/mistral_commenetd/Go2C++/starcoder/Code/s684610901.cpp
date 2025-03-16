
#include <bits/stdc++.h>

using namespace std;

// Define a custom type 'pair' for sorting
struct pair {
    int index; // Index for sorting
    int p1, p2; // Two elements to be compared
};

// Define a slice type 'pairs' for sorting 'pair' type
typedef pair* pairs;

// Implement sort.Interface methods for 'pairs' type
int pairs::Len() {
    return len(slice);
}

bool pairs::Less(int i, int j) {
    return slice[i].index < slice[j].index;
}

void pairs::Swap(int i, int j) {
    slice[i], slice[j] = slice[j], slice[i];
}

// Define a custom type 'Int64Slice' for sorting int64 slices
typedef int64_t* Int64Slice;

// Implement sort.Interface methods for 'Int64Slice' type
int Int64Slice::Len() {
    return len(slice);
}

bool Int64Slice::Less(int i, int j) {
    return slice[i] < slice[j];
}

void Int64Slice::Swap(int i, int j) {
    slice[i], slice[j] = slice[j], slice[i];
}

// Define some constants
const int64_t initialBufSize = 1e4; // Initial buffer size for bufio.NewScanner
const int64_t maxBufSize = 1e8; // Maximum buffer size for bufio.NewScanner
const int64_t INF = 1e8; // Infinite value for some calculations

// Initialize some global variables
int64_t A, B, C; // Input A, B, and C
int64_t di[] = {-1, 0, 1, 0}; // Direction vectors for 2D grid traversal
int64_t dj[] = {0, -1, 0, 1}; // Direction vectors for 2D grid traversal

// Main function
int main() {
    // Initialize the buffer with the given size
    char buf[initialBufSize];
    cin.rdbuf()->pubsetbuf(buf, maxBufSize);
    cin.sync_with_stdio(false);

    // Read input A, B, and C
    cin >> A >> B >> C;

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        cout << "Yes" << endl; // Print "Yes" if condition is true
    } else {
        cout << "No" << endl;  // Print "No" if condition is false
    }
}

// Helper functions for reading input
int64_t NextPermutation(int64_t x[], int64_t n) {
    // Implementation of next permutation algorithm for sorting
}

int64_t doubleAry(int64_t h, int64_t w, int64_t init) {
    // Function to initialize a 2D int64 array with given dimensions and initial value
}

bool aryEq(int64_t a[], int64_t b[], int64_t n) {
    // Function to check if two arrays are equal
}

int64_t clone(int64_t n[]) {
    // Function to clone a slice
}

void write(string s) {
    // Function to write a string to the output writer
}

void print() {
    // Function to flush the output writer
}

string readLine() {
    // Function to read a line from the input scanner
}

int64_t readInt() {
    // Function to read an integer from the input scanner
}

float readFloat() {
    // Function to read a float from the input scanner
}

int64_t readRunes() {
    // Function to read a rune slice from the input scanner
}

string readString() {
    // Function to read a string from the input scanner
}

string readStrings() {
    // Function to read a string slice from the input scanner
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

int64_t max(int64_t a[], int64_t n) {
    // Function to get the maximum value from a slice of integers
}

int64_t min(int64_t a[], int64_t n) {
    // Function to get the minimum value from a slice of integers
}

int64_t sum(int64_t i[], int64_t n) {
    // Function to get the sum of elements in a slice of integers
}

string split(string s) {
    // Function to split a string into a slice of strings using space as delimiter
}

int64_t strAry2intAry(string strs[], int64_t n) {
    // Function to convert a slice of strings to a slice of integers
}

int64_t intAry2strAry(int64_t nums[], int64_t n) {
    // Function to convert a slice of integers to a slice of strings
}

string ary2str(string strs[], int64_t n) {
    // Function to join a slice of strings into a single string using space as delimiter
}

int64_t reverse(int64_t res[], int64_t n) {
    // Function to reverse the order of elements in a slice
}

int64_t reverseStr(string res[], int64_t n) {
    // Function to reverse the order of elements in a slice of strings
}

void ini(int res[], int64_t n, int init) {
    // Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// void regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r("(\d+):(\d+)");
//     smatch m;
//     if (regex_search(str, m, r)) {
//         cout << m[1] << " " << m[2] << endl;
//     }
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// struct Country {
//     int gold;
//     int silver;
//     int bronze;
// };

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// Country stableSortExample(Country countries[], int n) {
//     // Your code here!
// }

