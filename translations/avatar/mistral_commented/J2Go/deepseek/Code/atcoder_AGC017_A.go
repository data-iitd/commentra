package main

import (
	"fmt"
	"math/big"
)

// Function to calculate the binomial coefficient C(n, m) using big.Int
func C(n, m int) *big.Int {
	res := new(big.Int).SetInt64(1) // Initialize result as 1

	// Calculate the binomial coefficient for n choose m
	for i := m - n + 1; i <= m; i++ {
		res.Mul(res, big.NewInt(int64(i))) // Multiply with current term
	}

	for i := 1; i <= n; i++ {
		res.Div(res, big.NewInt(int64(i))) // Divide with denominator
	}

	return res // Return the calculated binomial coefficient
}

func main() {
	var n, p int
	var k0, k1 int

	// Read the value of n from standard input
	fmt.Scan(&n)
	// Read the value of p from standard input
	fmt.Scan(&p)

	// Read the values of n elements and count the number of odd and even elements
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)

		if x%2 == 1 {
			k1++ // Increment the counter k1 if the current element is odd
		} else {
			k0++ // Increment the counter k0 if the current element is even
		}
	}

	ans := new(big.Int).SetInt64(1) // Initialize answer as 1

	// Calculate the answer based on the given conditions
	for i := 0; i < k0; i++ {
		ans.Mul(ans, big.NewInt(2)) // Multiply answer with 2 raised to the power of counter i
	}

	if p == 0 { // If p is 0, calculate the answer using the given formula
		add := new(big.Int).SetInt64(0)

		for i := 0; i <= k1; i += 2 {
			add.Add(add, C(i, k1)) // Calculate the sum of C(i, k1) for i from 0 to k1 with a step of 2
		}

		ans.Mul(ans, add) // Multiply the answer with the calculated sum

		fmt.Println(ans) // Print the final answer
	} else { // If p is not 0, calculate the answer using a similar formula
		add := new(big.Int).SetInt64(0)

		for i := 1; i <= k1; i += 2 {
			add.Add(add, C(i, k1)) // Calculate the sum of C(i, k1) for i from 1 to k1 with a step of 2
		}

		ans.Mul(ans, add) // Multiply the answer with the calculated sum

		fmt.Println(ans) // Print the final answer
	}
}

