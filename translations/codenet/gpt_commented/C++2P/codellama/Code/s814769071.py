#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;

// Define long long type for convenience
typedef long long ll;

// Macro for iterating from 0 to e
#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion

def main():
    # Read input values for n and k
    n, k = map(int, input().split())

    # Define MOD constant for modulo operations
    MOD = 1e9 + 7

    # Calculate the maximum possible value based on n and k
    mx = n * (n + 1) // 2 - (n - k) * (n - k + 1) // 2

    # Calculate the minimum possible value based on k
    mn = k * (k - 1) // 2

    # Initialize result variable
    res = 0

    # Loop through values from k to n+1 to compute the result
    for i in range(k, n + 1):
        # Update result based on current mx and mn values
        res += mx - mn + 1

        # Update mx and mn for the next iteration
        mx += n - i
        mn += i

        # Ensure result stays within the bounds of MOD
        res %= MOD

    # Output the final result
    print(res)

