package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables for the number of elements (N) and a threshold (T)
	var N, T int
	
	// Read the number of elements and the threshold from input
	fmt.Scan(&N, &T)
	
	// Initialize an array A to hold the input values
	A := make([]int, N)
	
	// Initialize a slice B to hold the transformed values
	B := make([]int, N)
	
	// Read N integers into the array A
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Split(scanner.Text(), " ")
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(inputs[i])
	}
	
	// Initialize m with the first element of A
	m := A[0]
	
	// Calculate the first element of B based on the first element of A and update m
	B[1] = A[1] - m
	m = min(m, A[1])
	
	// Loop through the remaining elements of A to fill B and update m
	for i := 2; i < N; i++ {
		// Fill B[i] with the difference between A[i] and the minimum value found so far (m)
		B[i] = A[i] - m
		
		// Update m to be the minimum of the current m and A[i]
		m = min(m, A[i])
	}
	
	// Count and output the number of times the maximum element in B appears
	maxB := max(B)
	count := 0
	for _, value := range B {
		if value == maxB {
			count++
		}
	}
	fmt.Println(count)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(slice []int) int {
	max := slice[0]
	for _, value := range slice {
		if value > max {
			max = value
		}
	}
	return max
}

