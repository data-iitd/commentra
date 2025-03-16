package main

import (
	"fmt"
)

// Function to calculate the number of combinations of choosing K items from a set of N items
func combi(N, K int) float64 {
	a := 1.0
	for i := 0; i < K; i++ {
		a *= float64(N - i)
		a /= float64(i + 1)
	}
	return a
}

func main() {
	// Read the input values N and P from the user
	var N, P int
	fmt.Scan(&N, &P)

	// Initialize the answer variable to 0
	ans := 0.0

	// Read the input values from the user and store them in a slice
	lis := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&lis[i])
	}

	// Initialize a slice to store the remainder of each input value when divided by 2
	ls := make([]int, N)

	// Iterate through each value in the list and append its remainder to the list
	for i, a := range lis {
		ls[i] = a % 2
	}

	// Calculate the number of 1's and 0's in the list
	one, zero := 0, 0
	for _, val := range ls {
		if val == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize two variables to store the pattern values
	patternA, patternB := 0.0, 0.0

	// Calculate the value of patternB by summing up the combinations of choosing 0's from the list
	for j := 0; j <= zero; j++ {
		patternB += combi(zero, j)
	}

	// Calculate the value of patternA by summing up the combinations of choosing numbers from the list based on the value of P
	for time := 0; time <= one; time++ {
		// Check if the current index (time) is a multiple of P
		if time%P == 0 {
			// If yes, add the combination value to patternA
			patternA += combi(one, time)
		}
	}

	// Print the final answer as an integer
	fmt.Println(int(patternA * patternB))
}

// <END-OF-CODE>
