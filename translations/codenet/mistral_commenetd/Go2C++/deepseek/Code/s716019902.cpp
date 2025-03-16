#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
#include <iomanip>

using namespace std;

#define MOD 998244353
#define FAC_NUM 300001

// Main function
int main() {
    // Initialize a new scanner
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read an integer N from the standard input
    int N;
    cin >> N;

    // Initialize a variable sum to 0
    int sum = 0;

    // Loop through numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        // If the number is not divisible by 3 or 5, add it to the sum
        if (i % 3 != 0 && i % 5 != 0) {
            sum += i;
        }
    }

    // Print the result to the standard output
    cout << sum << '\n';

    return 0;
}
