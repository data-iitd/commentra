#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

// Define constants
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const vector<pair<int, int>> dd = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const vector<pair<int, int>> ddn = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// Function to read an integer list from standard input
vector<int> LI() {
    string line;
    getline(cin, line);
    vector<int> result;
    string num;
    for (char ch : line) {
        if (ch == ' ') {
            result.push_back(stoi(num));
            num.clear();
        } else {
            num += ch;
        }
    }
    if (!num.empty()) {
        result.push_back(stoi(num));
    }
    return result;
}

// Function to read an integer from standard input
int I() {
    string line;
    getline(cin, line);
    return stoi(line);
}

// Function to read a float from standard input
double F() {
    string line;
    getline(cin, line);
    return stod(line);
}

// Function to read a list from standard input, split by space
vector<string> LS() {
    string line;
    getline(cin, line);
    vector<string> result;
    string word;
    for (char ch : line) {
        if (ch == ' ') {
            result.push_back(word);
            word.clear();
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        result.push_back(word);
    }
    return result;
}

// Function to read a string from standard input
string S() {
    string line;
    getline(cin, line);
    return line;
}

// Main function
void main() {
    // Read input values
    vector<int> values = LI();
    int a = values[0], b = values[1], c = values[2], d = values[3];

    // Calculate the maximum product of pairs of numbers
    int result = max({a * c, b * d, a * d, b * c});

    // Print the result
    cout << result << endl;
}

// Call the main function
int main() {
    main();
    return 0;
}
