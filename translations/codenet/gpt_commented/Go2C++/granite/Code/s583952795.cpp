
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Pair struct to hold two values of any type
struct Pair {
    int p1, p2;
};

// Constants for buffer sizes
const int initialBufSize = 1e4; // Initial buffer size for scanner
const int maxBufSize = 1e8; // Maximum buffer size for scanner

// Global variables for input and output
string buf(initialBufSize,''); // Buffer for scanner
string input; // Input string

// Function to convert a number from base 10 to base N
string TenToN(int number, int n) {
    stringstream ss; // Stringstream to hold the result
    int tmp = number; // Temporary variable to hold the current number
    while (tmp > 0) {
        ss << tmp % n; // Prepend the remainder of the division to the result string
        tmp /= n; // Divide the temporary number by the base
    }
    return ss.str(); // Return the converted string
}

int main() {
    // Allocate buffer for scanner and set its maximum size
    buf.resize(maxBufSize);
    cin.rdbuf()->pubsetbuf(&buf[0], maxBufSize);
    cin.tie(nullptr);

    // Read two integers N and K from input
    int N, K;
    cin >> N >> K;
    // Convert the number N from base 10 to base K
    string s = TenToN(N, K);
    // Print the length of the resulting string
    cout << s.length() << endl;
    return 0;
}

// Example function for regular expressions (commented out)
// void regexpExample() {
//     // Your code here!
//     string str = "13:20";
//     regex r("(\\d+):(\\d+)");
//     smatch m;
//     if (regex_search(str, m, r)) {
//         cout << m[1] << endl;
//         cout << m[2] << endl;
//     }
// }

// Struct to hold medal counts for a country (commented out)
// struct Country {
//     int gold;
//     int silver;
//     int blonze;
// };

// // Example function for stable sorting (commented out)
// vector<Country> stableSortExample() {
//     vector<Country> country = {
//         {1, 2, 3},
//         {1, 2, 3},
//         {1, 3, 2},
//         {1, 3, 3},
//     };
//     stable_sort(country.begin(), country.end(), [](const Country& c1, const Country& c2) { return c1.blonze > c2.blonze; });
//     stable_sort(country.begin(), country.end(), [](const Country& c1, const Country& c2) { return c1.silver > c2.silver; });
//     stable_sort(country.begin(), country.end(), [](const Country& c1, const Country& c2) { return c1.gold > c2.gold; });
//     return country;
// }

// Example function for reading a line of input (commented out)
// string readLine() {
//     getline(cin, input);
//     return input;
// }

// Example function for reading an integer from input (commented out)
// int readInt() {
//     int num;
//     cin >> num;
//     return num;
// }

// Example function for reading a float from input (commented out)
// float readFloat() {
//     float num;
//     cin >> num;
//     return num;
// }

// Example function for reading runes from input (commented out)
// string readRunes() {
//     string runes;
//     cin >> runes;
//     return runes;
// }

// Example function for reading a string from input (commented out)
// string readString() {
//     string str;
//     cin >> str;
//     return str;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for converting a string to an integer (commented out)
// int s2i(string str) {
//     int num;
//     stringstream ss(str);
//     ss >> num;
//     return num;
// }

// Example function for converting an integer to a string (commented out)
// string i2s(int num) {
//     string str;
//     stringstream ss;
//     ss << num;
//     ss >> str;
//     return str;
// }

// Example function for converting a string to a float (commented out)
// float s2f(string str) {
//     float num;
//     stringstream ss(str);
//     ss >> num;
//     return num;
// }

// Example function for calculating the sum of a slice of integers (commented out)
// int sum(vector<int> nums) {
//     int total = 0;
//     for (int num : nums) {
//         total += num;
//     }
//     return total;
// }

// Example function for splitting a string into a slice of strings (commented out)
// vector<string> split(string str) {
//     vector<string> tokens;
//     stringstream ss(str);
//     string token;
//     while (getline(ss, token,'')) {
//         tokens.push_back(token);
//     }
//     return tokens;
// }

// Example function for converting a slice of strings to a slice of integers (commented out)
// vector<int> strAry2intAry(vector<string> strs) {
//     vector<int> nums;
//     for (string str : strs) {
//         nums.push_back(s2i(str));
//     }
//     return nums;
// }

// Example function for converting a slice of integers to a slice of strings (commented out)
// vector<string> intAry2strAry(vector<int> nums) {
//     vector<string> strs;
//     for (int num : nums) {
//         strs.push_back(i2s(num));
//     }
//     return strs;
// }

// Example function for joining a slice of strings into a single string (commented out)
// string ary2str(vector<string> strs) {
//     string str;
//     for (string s : strs) {
//         str += s + " ";
//     }
//     return str;
// }

// Example function for reversing a slice of integers (commented out)
// vector<int> reverse(vector<int> nums) {
//     reverse(nums.begin(), nums.end());
//     return nums;
// }

// Example function for initializing a slice with a given value (commented out)
// void initialize(vector<int>& nums, int init) {
//     fill(nums.begin(), nums.end(), init);
// }

// Example function for reading a slice of integers from input (commented out)
// vector<int> readInts() {
//     vector<int> nums;
//     int num;
//     while (cin >> num) {
//         nums.push_back(num);
//     }
//     return nums;
// }

// Example function for reading a slice of floats from input (commented out)
// vector<float> readFloats() {
//     vector<float> nums;
//     float num;
//     while (cin >> num) {
//         nums.push_back(num);
//     }
//     return nums;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
//     }
//     return strs;
// }

// Example function for reading a slice of strings from input (commented out)
// vector<string> readStrings() {
//     vector<string> strs;
//     string str;
//     while (cin >> str) {
//         strs.push_back(str);
