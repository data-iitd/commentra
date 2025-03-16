package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N int
	fmt.Scan(&N) // Take an integer input N, representing the number of elements in the list A.
	A := make([]*big.Int, N) // Create a slice of pointers to big.Int to store the elements of the list A.
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x) // Take a space-separated string of integers, convert them into a list of integers, and assign it to the variable A.
		A[i] = big.NewInt(int64(x)) // Convert the integer x to a big.Int and assign it to the slice A at index i.
	}
	gcd := A[0] // Initialize gcd with the first element of the list A.
	for _, value := range A[1:] { // Iterate over the rest of the elements in the list A.
		gcd.GCD(nil, nil, gcd, value) // Compute the GCD of the current gcd and the current value using the GCD method of big.Int.
	}
	fmt.Println(gcd) // Print the computed GCD.
}
