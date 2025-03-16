package main

import (
	"fmt"
	"math"
)

// Function to calculate the binomial coefficient
func combi(N, K int) float64 {
	a := 1.0
	// Calculate the product part of the binomial coefficient
	for i := 0; i < K; i++ {
		a *= float64(N - i)
	}
	// Calculate the division part of the binomial coefficient
	for j := 0; j < K; j++ {
		a /= float64(j + 1)
	}
	return a
}

func main() {
	var N, P int
	// Read the values of N and P from input
	fmt.Scan(&N, &P)

	// Read a list of integers from input
	var lis []int
	var a int
	for i := 0; i < N; i++ {
		fmt.Scan(&a)
		lis = append(lis, a)
	}

	// Create a new list where each element is the remainder when divided by 2
	ls := []int{}
	for _, a := range lis {
		ls = append(ls, a%2)
	}

	// Count the number of 1s and 0s in the list
	one := 0
	zero := 0
	for _, v := range ls {
		if v == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize variables to store the number of patterns
	var patternA float64 = 0
	var patternB float64 = 0

	// Calculate the number of patterns with `j` zeros using the combi function
	for j := 0; j <= zero; j++ {
		patternB += combi(zero, j)
	}

	// Initialize time to 0 for the while loop
	time := 0

	// Calculate the number of patterns with `time` ones, considering the parity with P
	for time <= one {
		if time%2 == P {
			patternA += combi(one, time)
		}
		time++
	}

	// Print the result as an integer by multiplying patternA and patternB
	fmt.Println(int(patternA * patternB))
}
