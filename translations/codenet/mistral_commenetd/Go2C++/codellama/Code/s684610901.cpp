
// Package main is the entry point of the program
#include <bits/stdc++.h>

// Define a custom type 'pair' for sorting
struct pair {
    int64_t index; // Index for sorting
    int64_t p1, p2; // Two elements to be compared
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
// Input scanner
std::cin.tie(nullptr);
std::ios_base::sync_with_stdio(false);

// Output writer
std::cout.tie(nullptr);
std::ios_base::sync_with_stdio(false);

// Direction vectors for 2D grid traversal
int64_t di[] = {-1, 0, 1, 0};
int64_t dj[] = {0, -1, 0, 1};

// Main function
int main() {
    // Initialize the buffer with the given size
    std::cin.rdbuf()->pubsetbuf(initialBufSize);

    // Read input A, B, and C
    int64_t A, B, C;
    std::cin >> A >> B >> C;

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        std::cout << "Yes" << std::endl; // Print "Yes" if condition is true
    } else {
        std::cout << "No" << std::endl;  // Print "No" if condition is false
    }

    return 0;
}

// Helper functions for reading input
bool nextPermutation(std::vector<int64_t> &x) {
    // Implementation of next permutation algorithm for sorting
}

std::vector<std::vector<int64_t>> doubleAry(int64_t h, int64_t w, int64_t init) {
    // Function to initialize a 2D int64 array with given dimensions and initial value
}

bool aryEq(std::vector<int64_t> a, std::vector<int64_t> b) {
    // Function to check if two arrays are equal
}

std::vector<int64_t> clone(std::vector<int64_t> n) {
    // Function to clone a slice
}

void write(std::string s) {
    // Function to write a string to the output writer
}

void print() {
    // Function to flush the output writer
}

std::string readLine() {
    // Function to read a line from the input scanner
}

int64_t readInt() {
    // Function to read an integer from the input scanner
}

double readFloat() {
    // Function to read a float from the input scanner
}

std::vector<int64_t> readRunes() {
    // Function to read a rune slice from the input scanner
}

std::string readString() {
    // Function to read a string from the input scanner
}

std::vector<std::string> readStrings() {
    // Function to read a string slice from the input scanner
}

int64_t s2i(std::string s) {
    // Function to convert a string to an integer
}

std::string i2s(int64_t i) {
    // Function to convert an integer to a string
}

int64_t abs(int64_t i) {
    // Function to get the absolute value of an integer
}

int64_t max(std::vector<int64_t> a) {
    // Function to get the maximum value from a slice of integers
}

int64_t min(std::vector<int64_t> a) {
    // Function to get the minimum value from a slice of integers
}

int64_t sum(std::vector<int64_t> i) {
    // Function to get the sum of elements in a slice of integers
}

std::vector<std::string> split(std::string s) {
    // Function to split a string into a slice of strings using space as delimiter
}

std::vector<int64_t> strAry2intAry(std::vector<std::string> strs) {
    // Function to convert a slice of strings to a slice of integers
}

std::vector<std::string> intAry2strAry(std::vector<int64_t> nums) {
    // Function to convert a slice of integers to a slice of strings
}

std::string ary2str(std::vector<std::string> strs) {
    // Function to join a slice of strings into a single string using space as delimiter
}

std::vector<int64_t> reverse(std::vector<int64_t> res) {
    // Function to reverse the order of elements in a slice
}

std::vector<std::string> reverseStr(std::vector<std::string> res) {
    // Function to reverse the order of elements in a slice of strings
}

void ini(std::vector<int64_t> res, int64_t init) {
    // Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// void regexpExample() {
//     // Your code here!
//     std::string str = "13:20";
//     std::regex r("(\\d+):(\\d+)");
//     std::cout << std::regex_replace(str, r, "$1:$2") << std::endl;
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// struct Country {
//     int64_t gold;
//     int64_t silver;
//     int64_t blonze;
// };

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// std::vector<Country> stableSortExample() {
//     // Your code here!
// }

