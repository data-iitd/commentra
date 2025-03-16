package main

import (
	"fmt"
	"math"
)

// Function to calculate the number of combinations of choosing K items from a set of N items
func combi(N, K int) float64 {
	// Initialize the combination value to 1
	a := 1.0
	
	// Calculate the combination value by multiplying the number of choices from the set (N) to the current index (i)
	// and then dividing it by the current index (i+1) to account for the repetition of choices
	for i := 0; i < K; i++ {
		a *= float64(N - i)
		a /= float64(i + 1)
	}
	
	// Return the calculated combination value
	return a
}

func main() {
	// Read the input values N and P from the user
	var N, P int
	fmt.Scan(&N, &P)

	// Read the input values from the user and store them in a list
	var lis []int
	var a int
	for i := 0; i < N; i++ {
		fmt.Scan(&a)
		lis = append(lis, a)
	}

	// Initialize an empty list to store the remainder of each input value when divided by 2
	ls := []int{}

	// Iterate through each value in the list and append its remainder to the list
	for _, a := range lis {
		ls = append(ls, a % 2)
	}

	// Calculate the number of 1's and 0's in the list
	one := 0
	zero := 0
	for _, v := range ls {
		if v == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize two variables to store the pattern values
	var patternA float64 = 0
	var patternB float64 = 0

	// Calculate the value of pattern_b by summing up the combinations of choosing 0's from the list
	for j := 0; j <= zero; j++ {
		patternB += combi(zero, j)
	}

	// Calculate the value of pattern_a by summing up the combinations of choosing numbers from the list based on the value of P
	for time := 0; time <= one; time++ {
		// Check if the current index (time) is a multiple of P
		if time % P == 0 {
			// If yes, add the combination value to pattern_a
			patternA += combi(one, time)
		}
	}

	// Print the final answer as an integer
	fmt.Println(int(patternA * patternB))
}
