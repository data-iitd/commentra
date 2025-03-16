package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases
	var N int
	fmt.Scan(&N)

	// Read the array V of size N
	var V []int
	var input string
	fmt.Scan(&input)
	for _, s := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(s)
		V = append(V, num)
	}

	// Read the array C of size N
	var C []int
	fmt.Scan(&input)
	for _, s := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(s)
		C = append(C, num)
	}

	// Initialize an empty slice to store the differences between V and C
	var differences []int

	// Initialize variables to store the current difference and the sum of differences
	ans := 0
	X, Y := 0, 0

	// Iterate through each index i from 0 to N-1
	for i := 0; i < N; i++ {
		// If the difference between V[i] and C[i] is positive
		if V[i]-C[i] > 0 {
			// Update X and Y with the respective values from V and C at index i
			X = V[i]
			Y = C[i]
			// Append the difference X-Y to the differences slice
			differences = append(differences, X-Y)
			// Update the sum of differences
			ans += X - Y
		}
	}

	// Print the sum of all the elements in the differences slice
	sumDifferences := 0
	for _, diff := range differences {
		sumDifferences += diff
	}
	fmt.Println(sumDifferences)
	// Print the sum of all the differences between V and C
	fmt.Println(ans)
}

// <END-OF-CODE>
