//#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
//#include <vector>
//#include <unordered_map>
//#include <string>

package main

import (
	"fmt"
)

// Define long long type as LL for convenience
type LL int64

// Define a constant for modulo operation
const MOD = 1000000007

// Function to compute (x^n) % MOD using modular exponentiation
func mod_pow(x, n LL) LL {
	ans := 1 // Initialize result
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd
			ans = ans * x % MOD // Multiply ans by x and take modulo
		}
		x = x * x % MOD // Square x and take modulo
		n >>= 1 // Divide n by 2
	}
	return ans // Return the result
}

// Function to compute combination C(n, r) % MOD using modular arithmetic
func comb_s(n, r LL) LL {
	tmp_n := 1 // Temporary variable for numerator
	tmp_d := 1 // Temporary variable for denominator
	ans := 0 // Variable to store the final answer
	for i := 1; i <= r; i++ { // Loop to calculate numerator and denominator
		tmp_n = (tmp_n * (n + 1 - i)) % MOD // Calculate numerator
		tmp_d = (tmp_d * i) % MOD // Calculate denominator
		ans = tmp_n * mod_pow(tmp_d, MOD-2) // Calculate combination using modular inverse
	}

	return ans // Return the combination result
}

func main() {
	var n, n_tmp, a, b LL
	ans := 1 // Initialize answer variable

	// Input the values of n, a, and b
	fmt.Scan(&n, &a, &b)

	// Calculate 2^n - 1 (total subsets excluding the empty set)
	ans = mod_pow(2, n)
	ans--

	tmp_nd := 0 // Temporary variable to store combinations

	// Calculate C(n, a) and subtract from ans
	tmp_nd = comb_s(n, a)
	ans = (ans - tmp_nd) % MOD // Subtract combinations of size a
	for ans < 0 { // Ensure ans is non-negative
		ans += MOD
	}
	//fmt.Println(ans, tmp_ans) // Uncomment for debugging

	// Calculate C(n, b) and subtract from ans
	tmp_nd = comb_s(n, b)
	ans = (ans - tmp_nd) % MOD // Subtract combinations of size b
	//fmt.Println(ans, tmp_ans) // Uncomment for debugging
	for ans < 0 { // Ensure ans is non-negative
		ans += MOD
	}

	// Output the final result
	fmt.Println(ans)
}

