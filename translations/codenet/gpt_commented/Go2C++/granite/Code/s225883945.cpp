
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <climits>
#include <cfloat>
#include <cctype>
#include <list>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <random>
#include <valarray>

using namespace std;

int main() {
    // Set the cin to sync with the standard input
    cin.sync_with_stdio(false);
    // Set the cin to read from the standard input
    cin.tie(0);

    // Read two integers from input: n (number of elements) and k (some parameter)
    int n, k;
    cin >> n >> k;

    // Read 'n' integers into vector 'a'
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Avoid unused variable error by assigning a value to the first element of 'a'
    a[0] = 0;

    // Initialize sum with the value of k and set ans to 1
    int sum = k;
    int ans = 1;

    // Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
    while (sum < n) {
        sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
        ans++; // Increment the answer counter
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

