package main

import (
	"fmt"
	"math/big"
)

func main() {
	const mod = 1000000007
	// Define the modulo value as 10^9 + 7

	var n int
	fmt.Scan(&n)
	// Read the integer input `n`

	var c []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		c = append(c, x)
	}
	// Read the list of integers `c` and convert them to a slice

	// Sort the slice `c` in descending order
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if c[i] < c[j] {
				c[i], c[j] = c[j], c[i]
			}
		}
	}

	b := new(big.Int).Exp(big.NewInt(2), big.NewInt(2*int64(n)-2), big.NewInt(mod))
	// Calculate `b` using the big.Int.Exp function with base 2, exponent \(2 * n - 2\), and modulo `mod`

	a := new(big.Int).Mul(big.NewInt(2), b)
	a.Mod(a, big.NewInt(mod))
	// Calculate `a` as twice `b` modulo `mod`

	var ans big.Int
	ans.SetInt64(0)
	// Initialize `ans` to 0

	for i := 0; i < n; i++ {
		// Loop through each element in the range `n`
		temp := new(big.Int).Add(a, new(big.Int).Mul(big.NewInt(int64(i)), b))
		temp.Mul(temp, big.NewInt(int64(c[i])))
		ans.Add(&ans, temp)
		ans.Mod(&ans, big.NewInt(mod))
		// Update `ans` with the sum of the product of `c[i]` and `(a + i * b)`
		// Take modulo `mod` at each step to prevent overflow
	}

	fmt.Println(ans.String())
	// Print the final result `ans`
}
