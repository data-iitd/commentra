#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <limits>

using namespace std;

/*==========================================
 *             Custom Sorting Types
 *==========================================*/
// Pair struct holds two values and an index for sorting.
struct Pair {
    int64_t index;
    int64_t p1, p2;
};

// Function to compare two pairs based on their index.
bool comparePairs(const Pair &a, const Pair &b) {
    return a.index < b.index;
}

// Int64Slice is a type alias for sorting slices of int64.
using Int64Slice = vector<int64_t>;

// Function to check if a slice of int64 is sorted.
bool isSorted(const Int64Slice &a) {
    return is_sorted(a.begin(), a.end());
}

/*==========================================
 *             Constants and Variables
 *==========================================*/
const int64_t INF = 1e8;

// Function to read an integer from standard input.
int64_t readInt() {
    int64_t read;
    cin >> read;
    return read;
}

/*==========================================
 *             Main Function
 *==========================================*/
int main() {
    int64_t A = readInt();
    int64_t B = readInt();
    int64_t C = readInt();
    
    if (C >= A && C <= B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

/*==========================================
 *             Library
 *==========================================*/
// Function to find the next permutation of a vector.
bool nextPermutation(vector<int64_t> &x) {
    int n = x.size() - 1;
    if (n < 1) return false;
    int j = n - 1;
    while (j >= 0 && x[j] >= x[j + 1]) {
        j--;
    }
    if (j < 0) return false;
    int l = n;
    while (x[j] >= x[l]) {
        l--;
    }
    swap(x[j], x[l]);
    reverse(x.begin() + j + 1, x.end());
    return true;
}

// Function to create a 2D vector initialized with a given value.
vector<vector<int64_t>> doubleAry(int64_t h, int64_t w, int64_t init) {
    return vector<vector<int64_t>>(h, vector<int64_t>(w, init));
}

// Function to check if two vectors are equal.
bool aryEq(const Int64Slice &a, const Int64Slice &b) {
    return a == b;
}

// Function to clone a vector.
Int64Slice clone(const Int64Slice &n) {
    return n;
}

// Function to write a string to the output.
void write(const string &s) {
    cout << s;
}

// Function to read a line of text from standard input.
string readLine() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read a float from standard input.
double readFloat() {
    double read;
    cin >> read;
    return read;
}

// Function to convert a string to an integer.
int64_t s2i(const string &s) {
    return stoll(s);
}

// Function to convert an integer to a string.
string i2s(int64_t i) {
    return to_string(i);
}

// Function to return the absolute value of an integer.
int64_t abs(int64_t i) {
    return std::abs(i);
}

// Function to return the maximum value in a list of integers.
int64_t max(int64_t a, int64_t b) {
    return std::max(a, b);
}

// Function to return the minimum value in a list of integers.
int64_t min(int64_t a, int64_t b) {
    return std::min(a, b);
}

// Function to return the sum of a vector of integers.
int64_t sum(const Int64Slice &i) {
    return accumulate(i.begin(), i.end(), int64_t(0));
}

// Function to split a string into a vector of strings.
vector<string> split(const string &s) {
    istringstream iss(s);
    return vector<string>(istream_iterator<string>{iss}, istream_iterator<string>{});
}

// Function to convert a vector of strings to a vector of integers.
Int64Slice strAry2intAry(const vector<string> &strs) {
    Int64Slice ret;
    for (const auto &str : strs) {
        ret.push_back(s2i(str));
    }
    return ret;
}

// Function to convert a vector of integers to a vector of strings.
vector<string> intAry2strAry(const Int64Slice &nums) {
    vector<string> ret;
    for (const auto &num : nums) {
        ret.push_back(i2s(num));
    }
    return ret;
}

// Function to join a vector of strings into a single string.
string ary2str(const vector<string> &strs) {
    return accumulate(strs.begin(), strs.end(), string(), [](const string &a, const string &b) {
        return a.empty() ? b : a + " " + b;
    });
}

// Function to reverse a vector of integers.
Int64Slice reverse(Int64Slice res) {
    std::reverse(res.begin(), res.end());
    return res;
}

// Function to reverse a vector of strings.
vector<string> reverseStr(vector<string> res) {
    std::reverse(res.begin(), res.end());
    return res;
}

// Function to initialize a vector with a specific value.
void ini(vector<int> &res, int init) {
    if (res.empty()) return;
    fill(res.begin(), res.end(), init);
}

