
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

// Function to compute (x^n) % MOD using modular exponentiation
func mod_pow(x, n int64) int64 {
	ans := int64(1) // Initialize result
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
func comb_s(n, r int64) int64 {
	tmp_n := int64(1) // Temporary variable for numerator
	tmp_d := int64(1) // Temporary variable for denominator
	ans := int64(1) // Variable to store the final answer
	for i := int64(1); i <= r; i++ { // Loop to calculate numerator and denominator
		tmp_n = (tmp_n * (n + 1 - i)) % MOD // Calculate numerator
		tmp_d = (tmp_d * i) % MOD // Calculate denominator
		ans = tmp_n * mod_pow(tmp_d, MOD-2) % MOD // Calculate combination using modular inverse
	}

	return ans // Return the combination result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n, n_tmp, a, b int64
	scanner.Scan()
	n = readInt(scanner.Bytes(), 0, 64)
	scanner.Scan()
	n_tmp = readInt(scanner.Bytes(), 0, 64)
	scanner.Scan()
	a = readInt(scanner.Bytes(), 0, 64)
	scanner.Scan()
	b = readInt(scanner.Bytes(), 0, 64)
	ans := int64(1) // Initialize answer variable

	// Calculate 2^n - 1 (total subsets excluding the empty set)
	ans = mod_pow(2, n)
	ans--

	tmp_nd := int64(0) // Temporary variable to store combinations

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

func readInt(bytes []byte, from int, val *int64) int {
	i := from
	sign := 1
	if bytes[i] == '-' { // If first character is '-', set sign to -1 and increment i
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' { // Loop to read the number
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = int64(tmp) * int64(sign) // Convert the number to int64 and store in val
	return i // Return the index after reading the number
}

