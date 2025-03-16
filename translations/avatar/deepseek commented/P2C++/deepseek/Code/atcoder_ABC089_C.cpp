#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tuple>
#include <sstream>
#include <cstring>

using namespace std;

// Function to read a single line of input
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Function to convert input to an integer
int INT() {
    return stoi(input());
}

// Function to read a map of integers
vector<int> MAP() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Function to convert input to a list of integers
vector<int> LIST() {
    vector<int> result;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Function to create combinations from a list of tuples
template<typename T>
vector<vector<T>> combinations(const vector<T>& vec, int k) {
    vector<vector<T>> result;
    vector<T> current;
    function<void(int)> backtrack = [&](int start) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < vec.size(); ++i) {
            current.push_back(vec[i]);
            backtrack(i + 1);
            current.pop_back();
        }
    };
    backtrack(0);
    return result;
}

// Set recursion limit to prevent recursion errors
static const int RECURSION_LIMIT = 1000;
void set_recursion_limit() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Increase recursion limit for C++
    #ifdef _WIN32
        _setmaxrecursion(RECURSION_LIMIT);
    #else
        sysctl("kern.sys.maxrecursion", 0, &RECURSION_LIMIT, nullptr, nullptr);
    #endif
}

// Define constants
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

int main() {
    set_recursion_limit();

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
    for (const auto& s : S) {
        char first_char = toupper(s[0]);
        auto it = find(march.begin(), march.end(), first_char);
        if (it != march.end()) {
            march_lis[distance(march.begin(), it)]++;
        }
    }

    // Initialize the answer variable
    int ans = 0;

    // Calculate the number of combinations of three elements from march_lis
    auto comb = combinations(march_lis, 3);
    for (const auto& trio : comb) {
        ans += trio[0] * trio[1] * trio[2];
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
