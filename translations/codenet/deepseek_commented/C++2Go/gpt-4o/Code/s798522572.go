package main

import (
	"fmt"
	"math"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T) // Reading the number of elements and a threshold value
	A := make([]int, N) // Declaring a slice to store the elements
	B := make([]int, N) // Declaring a slice to store the differences

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Reading the elements into the slice
	}

	// Initializing the minimum value with the first element of A
	m := A[0]
	// Calculating the difference between the second element and the initial minimum, and storing it in B[1]
	B[1] = A[1] - m
	// Updating the minimum value to be the minimum of its current value and the second element of A
	m = int(math.Min(float64(m), float64(A[1])))

	// For each subsequent element in A, calculate the difference, update the minimum, and store the difference in B
	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = int(math.Min(float64(m), float64(A[i])))
	}

	// Finding the maximum value in B
	maxValue := B[0]
	for _, value := range B {
		if value > maxValue {
			maxValue = value
		}
	}

	// Counting how many times the maximum value appears in B
	count := 0
	for _, value := range B {
		if value == maxValue {
			count++
		}
	}

	fmt.Println(count)
}

// <END-OF-CODE>
