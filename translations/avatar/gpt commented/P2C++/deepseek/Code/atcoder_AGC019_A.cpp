#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

// Function to read a line of input
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Function to compute the ceiling of a divided by b
int ceil(int a, int b = 1) {
    return (a + b - 1) / b;
}

// Function to round a number to the nearest integer
int round(double x) {
    return static_cast<int>((x * 2 + 1) / 2);
}

// Function to compute Fermat's little theorem for modular inverse
int fermat(int x, int y, int MOD) {
    return x * static_cast<long long>(pow(y, MOD - 2, MOD)) % MOD;
}

// Function to compute the least common multiple of two numbers
int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

// Function to compute the least common multiple of a list of numbers
int lcm_list(const vector<int>& nums) {
    int result = 1;
    for (int num : nums) {
        result = lcm(result, num);
    }
    return result;
}

// Function to read an integer from input
int INT() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
vector<int> MAP() {
    vector<int> nums;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }
    return nums;
}

// Function to read a list of integers into a vector
vector<int> LIST() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }
    return nums;
}

// Set the maximum recursion limit
const int RECURSION_LIMIT = 1000000;

// Define constants for infinity and modulo
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input values for costs of different types of drinks
    int q, h, s, d;
    cin >> q >> h >> s >> d;

    // Read the number of drinks to be purchased
    int n = INT();

    // Calculate the best price for 1 liter of drink
    int best1L = min({q * 4, h * 2, s});

    // Calculate the best price for 2 liters of drink
    int best2L = min(d, best1L * 2);

    // Calculate and print the total cost based on whether n is even or odd
    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;  // Total cost for even number of drinks
    } else {
        cout << best2L * (n / 2) + best1L << endl;  // Total cost for odd number of drinks
    }

    return 0;
}
