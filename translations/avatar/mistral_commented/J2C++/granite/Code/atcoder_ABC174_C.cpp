

#include <iostream> // Importing necessary C++ packages for input and output
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double PI = acos(-1.0);
const double eps = 1e-9;

int main() {
    // Main function to call the solve function and print the result
    cout << solve() << endl;
    return 0;
}

int solve() {
    // Function to find the answer
    int K; // Reading the input value of K
    cin >> K;

    // Checking if K is even or multiple of 5, returning -1 if true
    if (K % 2 == 0 || K % 5 == 0) return -1;

    // If K is multiple of 7, dividing it by 7 and multiplying it by 9
    if (K % 7 == 0) K /= 7;
    K *= 9;

    // Initializing the answer variable and the remainder variable
    int ans = 1, remainder = 10 % K;

    // Using a while loop to find the answer
    while (remainder!= 1) {
        ans++; // Incrementing the answer variable
        remainder = remainder * 10 % K; // Updating the remainder variable
    }

    // Returning the answer
    return ans;
}

These comments should help make the code more readable and understandable for anyone who reads it.