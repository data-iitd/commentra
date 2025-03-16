#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>
#include <cmath>
#include <limits>
#include <tuple>

using namespace std;

// Function to read a single line of input
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to convert input to an integer
int INT() {
    return stoi(input());
}

// Function to read a list of integers
vector<int> LIST() {
    vector<int> result;
    string line = input();
    size_t pos = 0;
    while ((pos = line.find(' ')) != string::npos) {
        result.push_back(stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    result.push_back(stoi(line)); // Add the last number
    return result;
}

// Define constants
const int INF = numeric_limits<int>::max();
const int mod = 1e9 + 7;

int main() {
    // Read the number of strings
    int N = INT();

    // Read the list of strings
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        S[i] = input();
    }

    // List of characters that can be selected
    vector<char> march = {'M', 'A', 'R', 'C', 'H'};

    // Initialize a vector to count occurrences of each character in 'march'
    vector<int> march_lis(5, 0);

    // Count the occurrences of characters in 'march' in the list of strings
    for (const string& s : S) {
        char first_char = toupper(s[0]);
        auto it = find(march.begin(), march.end(), first_char);
        if (it != march.end()) {
            march_lis[it - march.begin()]++;
        }
    }

    // Initialize the answer variable
    long long ans = 0;

    // Calculate the number of combinations of three elements from march_lis
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += static_cast<long long>(march_lis[i]) * march_lis[j] * march_lis[k];
            }
        }
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
