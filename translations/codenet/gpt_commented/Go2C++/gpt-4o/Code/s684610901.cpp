#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// Utility functions
int64_t readInt() {
    int64_t value;
    cin >> value;
    return value;
}

bool isInRange(int64_t A, int64_t B, int64_t C) {
    return C >= A && C <= B;
}

int main() {
    // Read three integers A, B, C
    int64_t A = readInt();
    int64_t B = readInt();
    int64_t C = readInt();
    
    // Check if C is within the range [A, B] and print the result
    if (isInRange(A, B, C)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

/*==========================================
 *             Library Functions
 *==========================================*/

// NextPermutation generates the next lexicographical permutation of the given vector
bool NextPermutation(vector<int64_t>& x) {
    int n = x.size() - 1;
    if (n < 1) {
        return false;
    }
    int j = n - 1;
    // Find the rightmost ascent
    while (j >= 0 && x[j] >= x[j + 1]) {
        j--;
    }
    if (j < 0) {
        return false;
    }
    int l = n;
    // Find the rightmost successor to the pivot
    while (x[j] >= x[l]) {
        l--;
    }
    swap(x[j], x[l]); // Swap the pivot with its successor
    // Reverse the suffix
    reverse(x.begin() + j + 1, x.end());
    return true;
}

// Function to calculate the absolute value of an int64
int64_t abs(int64_t i) {
    return i < 0 ? -i : i;
}

// Function to calculate the maximum value from a list of int64
int64_t max(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

// Function to calculate the minimum value from a list of int64
int64_t min(int64_t a, int64_t b) {
    return (a < b) ? a : b;
}

// Function to calculate the sum of a vector of int64
int64_t sum(const vector<int64_t>& vec) {
    int64_t total = 0;
    for (const auto& val : vec) {
        total += val;
    }
    return total;
}

// Function to split a string into fields
vector<string> split(const string& s) {
    istringstream iss(s);
    return vector<string>(istream_iterator<string>(iss), istream_iterator<string>());
}

// Function to convert a vector of strings to a vector of int64
vector<int64_t> strAry2intAry(const vector<string>& strs) {
    vector<int64_t> ret;
    for (const auto& str : strs) {
        ret.push_back(stoi(str));
    }
    return ret;
}

// Function to convert a vector of int64 to a vector of strings
vector<string> intAry2strAry(const vector<int64_t>& nums) {
    vector<string> ret;
    for (const auto& num : nums) {
        ret.push_back(to_string(num));
    }
    return ret;
}

// Function to join a vector of strings into a single string
string ary2str(const vector<string>& strs) {
    string result;
    for (const auto& str : strs) {
        result += str + " ";
    }
    return result.substr(0, result.size() - 1); // Remove the trailing space
}

// Function to reverse a vector of int64
vector<int64_t> reverseVec(vector<int64_t> vec) {
    reverse(vec.begin(), vec.end());
    return vec;
}

// Function to reverse a vector of strings
vector<string> reverseStrVec(vector<string> vec) {
    reverse(vec.begin(), vec.end());
    return vec;
}

// Function to initialize the first element of a vector with a given value
void ini(vector<int>& vec, int init) {
    if (vec.empty()) {
        return;
    }
    vec[0] = init;
    for (size_t i = 0; i < vec.size(); i++) {
        copy(vec.begin(), vec.begin() + i, vec.begin() + i);
    }
}

// Uncomment the following function to see a regex example
// void regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r(R"((\d+):(\d+))");
//     smatch match;
//     if (regex_search(str, match, r)) {
//         cout << match[0] << endl;
//     }
// }

// Uncomment the following struct and function to see a stable sort example
// struct Country {
//     int gold;
//     int silver;
//     int bronze;
// };

// vector<Country> stableSortExample() {
//     vector<Country> countries = {
//         {1, 2, 3},
//         {1, 2, 3},
//         {1, 3, 2},
//         {1, 3, 3},
//     };
//     stable_sort(countries.begin(), countries.end(), [](const Country& a, const Country& b) { return a.bronze > b.bronze; });
//     stable_sort(countries.begin(), countries.end(), [](const Country& a, const Country& b) { return a.silver > b.silver; });
//     stable_sort(countries.begin(), countries.end(), [](const Country& a, const Country& b) { return a.gold > b.gold; });
//     return countries;
// }

