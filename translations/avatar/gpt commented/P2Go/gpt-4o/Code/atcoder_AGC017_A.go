package main

import (
	"fmt"
)

// Function to calculate combinations C(N, K)
func combi(N, K int) float64 {
	a := 1.0
	// Calculate the numerator of the combination formula
	for i := 0; i < K; i++ {
		a *= float64(N - i)
	}
	// Calculate the denominator of the combination formula
	for j := 1; j <= K; j++ {
		a /= float64(j)
	}
	return a
}

func main() {
	var N, P int
	// Read two integers N and P from input
	fmt.Scan(&N, &P)

	// Read a list of integers from input
	lis := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&lis[i])
	}

	// Create a slice to hold the parity (0 or 1) of each number
	ls := make([]int, N)
	for i, a := range lis {
		// Append the remainder when divided by 2 (0 for even, 1 for odd)
		ls[i] = a % 2
	}

	// Count the number of 1s (odd numbers) and 0s (even numbers) in the list
	one := 0
	zero := 0
	for _, v := range ls {
		if v == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize variables to count patterns
	patternA := 0.0
	patternB := 0.0

	// Calculate the total number of patterns for the even numbers
	for j := 0; j <= zero; j++ {
		patternB += combi(zero, j)
	}

	// Initialize a variable to track the number of odd numbers used
	time := 0

	// Loop through all possible counts of odd numbers used
	for time <= one {
		// Check if the current count of odd numbers is congruent to P modulo 2
		if time%2 == P {
			// If it is, add the number of combinations to patternA
			patternA += combi(one, time)
		}
		time++
	}

	// Print the final result, which is the product of patternA and patternB
	fmt.Println(int(patternA * patternB))
}

// <END-OF-CODE>
