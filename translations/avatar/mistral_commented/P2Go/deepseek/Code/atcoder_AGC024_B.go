package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of test cases N from the standard input.
	var N int
	fmt.Scan(&N)

	// Read N integers from the standard input and store them in a slice P.
	P := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&P[i])
	}

	// Call the editorial function with N and P as arguments.
	editorial(N, P)
}

// This function calculates the answer based on the given input.
func editorial(N int, P []int) {
	// Base case: if there is only one element in the list, the answer is 0.
	if N == 1 {
		fmt.Println(0)
		return
	}

	// Initialize an array a of size N+1 with all elements initialized to 0.
	a := make([]int, N+1)

	// Iterate through the list P and assign each element its index in the array a.
	for i, p := range P {
		a[p] = i
	}

	// Initialize two variables: tmp to keep track of the current streak,
	// and max_len to keep track of the maximum streak.
	tmp := 1
	max_len := 1

	// Iterate through the array a from the second element to the last.
	for i := 1; i < N; i++ {
		// If the current element has a smaller index than the previous one,
		// increment the streak and update max_len if necessary.
		if a[i] < a[i+1] {
			tmp++
			if tmp > max_len {
				max_len = tmp
			}
		} else {
			// Otherwise, reset the streak to 1.
			tmp = 1
		}
	}

	// Calculate the answer as the difference between the total number of elements
	// and the maximum streak.
	ans := N - max_len

	// Print the answer.
	fmt.Println(ans)
}

// This function is used for testing purposes and is not called in the main function.
func WA(N int, P []int) {
	// Initialize two variables: tmp to keep track of the current streak,
	// and ans to keep track of the maximum answer.
	tmp := 0
	ans := 0

	// Iterate through the list P and calculate the answer based on the current streak.
	for i := 0; i < N; i++ {
		// If the current element is the first one or its previous element plus one,
		// increment the streak and update ans if necessary.
		if i == 0 || P[i-1]+1 == P[i] {
			tmp++
			if tmp > ans {
				ans = tmp
			}
		} else {
			// Otherwise, reset the streak to 1.
			tmp = 1
		}
	}

	// Print the answer.
	fmt.Println(N - ans)
}
