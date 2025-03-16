#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;
using ll=long long int;

// Include necessary headers: These headers provide essential functionalities
// such as input/output operations, containers like vectors and deques,
// and algorithms.

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    int r;
    while ((r = a%b) > 0) {
        a = b;
        b = r;
    }
    return b;
}

// Define gcd function: This function computes the greatest common divisor
// of two integers using the Euclidean algorithm.

int main() {
    int n;
    cin >> n;

    // Read the number of integers.

    int ans;
    cin >> ans;

    // Read the first integer and initialize the answer.

    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        ans = gcd(ans, a);
    }

    // Read the remaining integers, compute their GCD with the current answer,
    // and update the answer accordingly.

    cout << ans << endl;

    // Print the final result, which is the GCD of all the input integers.

    return 0;
}