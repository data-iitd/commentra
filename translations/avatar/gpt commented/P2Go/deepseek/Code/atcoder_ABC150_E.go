package main

import (
	"fmt"
	"math/big"
)

func main() {
	// Define the modulo constant
	const mod = 1000000007

	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the list of integers and convert them to a slice of integers
	var c []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		c = append(c, x)
	}

	// Sort the slice in descending order
	sort.Slice(c, func(i, j int) bool {
		return c[i] > c[j]
	})

	// Calculate the value of b as 2^(2*n - 2) modulo mod
	b := new(big.Int).Exp(big.NewInt(2), big.NewInt(int64(2*n-2)), big.NewInt(mod))

	// Calculate the value of a as 2 * b modulo mod
	a := new(big.Int).Mul(big.NewInt(2), b)
	a.Mod(a, big.NewInt(mod))

	// Initialize the answer variable
	var ans big.Int

	// Iterate through the sorted slice and calculate the answer
	for i := 0; i < n; i++ {
		// Create big.Int variables for the multiplication
		bigA := big.NewInt(int64(a.Int64()))
		bigB := big.NewInt(int64(b.Int64()))
		bigI := big.NewInt(int64(i))
		bigC := big.NewInt(int64(c[i]))

		// Update the answer by adding the product of the current element and (a + i * b)
		temp := new(big.Int).Add(bigA, new(big.Int).Mul(bigI, bigB))
		temp.Mul(temp, bigC)
		ans.Add(&ans, temp)
		ans.Mod(&ans, big.NewInt(mod))
	}

	// Print the final result
	fmt.Println(ans.String())
}
