
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

// Function to calculate x^n % MOD using bitwise operations
func mod_pow(x, n int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 { // Check if the least significant bit is 1
			ans = ans * x % MOD // Update ans if the bit is set
		}
		x = x * x % MOD // Square x and take modulo MOD
		n >>= 1 // Shift n right by 1 bit (divide by 2)
	}
	return ans
}

// Function to calculate combination C(n, r) % MOD
func comb_s(n, r int64) int64 {
	tmp_n := int64(1)
	tmp_d := int64(1)
	ans := int64(0)
	for i := int64(1); i <= r; i++ {
		tmp_n = (tmp_n * (n + 1 - i)) % MOD // Compute the numerator
		tmp_d = (tmp_d * i) % MOD // Compute the denominator
		ans = (tmp_n * mod_pow(tmp_d, MOD-2)) % MOD // Compute the combination
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int64
	scanner.Scan()
	n, _ = fmt.Sscanf(scanner.Text(), "%d")
	var a int64
	scanner.Scan()
	a, _ = fmt.Sscanf(scanner.Text(), "%d")
	var b int64
	scanner.Scan()
	b, _ = fmt.Sscanf(scanner.Text(), "%d")
	ans := mod_pow(2, n) // Calculate 2^n % MOD
	ans-- // Subtract 1 from ans
	tmp_nd := comb_s(n, a) // Calculate C(n, a) % MOD
	ans = (ans - tmp_nd) % MOD // Subtract the combination from ans
	for ans < 0 { // Handle negative results
		ans += MOD
	}
	tmp_nd = comb_s(n, b) // Calculate C(n, b) % MOD
	ans = (ans - tmp_nd) % MOD // Subtract the combination from ans
	for ans < 0 { // Handle negative results
		ans += MOD
	}
	fmt.Println(ans) // Output the final result
}

