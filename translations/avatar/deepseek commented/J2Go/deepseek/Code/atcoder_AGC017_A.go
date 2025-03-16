package main

import (
	"fmt"
	"math/big"
)

// Function to calculate combination (n choose m) using BigInt for large numbers
func C(n, m int) *big.Int {
	res := big.NewInt(1) // Initialize result to 1
	// Calculate product from m-n+1 to m
	for i := m - n + 1; i <= m; i++ {
		res.Mul(res, big.NewInt(int64(i)))
	}
	// Divide by product from 1 to n
	for i := 1; i <= n; i++ {
		res.Div(res, big.NewInt(int64(i)))
	}
	return res
}

func main() {
	var n, p int
	var k0, k1 int

	// Read number of items (n) and the value of p
	fmt.Scan(&n, &p)

	// Count even and odd numbers in the input
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		if x%2 == 1 {
			k1++
		} else {
			k0++
		}
	}

	// Initialize result for number of ways to arrange items
	ans := big.NewInt(1)

	// Calculate number of ways based on the value of p
	for i := 0; i < k0; i++ {
		ans.Mul(ans, big.NewInt(2)) // Multiply by 2 for each even number
	}

	if p == 0 {
		add := big.NewInt(0)
		// Sum combinations of odd numbers, taking 0, 2, 4, ... odd numbers
		for i := 0; i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add) // Multiply result by the sum
		fmt.Println(ans)  // Print final result
	} else {
		add := big.NewInt(0)
		// Sum combinations of odd numbers, taking 1, 3, 5, ... odd numbers
		for i := 1; i <= k1; i += 2 {
			add.Add(add, C(i, k1))
		}
		ans.Mul(ans, add) // Multiply result by the sum
		fmt.Println(ans)  // Print final result
	}
}

