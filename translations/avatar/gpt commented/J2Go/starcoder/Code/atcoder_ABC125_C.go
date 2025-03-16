package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Array to hold the input integers
var A []int

func main() {
	// Create a new Scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	// Initialize the array A with size N
	A = make([]int, N)

	// Read N integers from input and store them in array A
	for i := 0; i < N; i++ {
		scanner.Scan()
		A[i], _ = strconv.Atoi(scanner.Text())
	}

	// Arrays to hold the GCD values from the left and right
	M := make([]int, N) // Not used in the code, can be removed
	L := make([]int, N) // GCD values from the left
	R := make([]int, N) // GCD values from the right

	// Initialize the first element of L with the first element of A
	L[0] = A[0]

	// Calculate GCD from the left side
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}

	// Initialize the last element of R with the last element of A
	R[N-1] = A[N-1]

	// Calculate GCD from the right side
	for i := N-2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}

	// Calculate the maximum GCD excluding the last element
	answer := max(L[N-2], R[1])

	// Iterate through the array to find the maximum GCD excluding the current element
	for i := 1; i < N-1; i++ {
		answer = max(answer, gcd(L[i-1], R[i+1]))
	}

	// Print the final answer
	fmt.Println(answer)
}

// Method to calculate the GCD of two integers using the Euclidean algorithm
func gcd(a, b int) int {
	var tmp int

	// Ensure a is greater than or equal to b
	if b > a {
		tmp = a
		a = b
		b = tmp
	}

	// If b is zero, return a as the GCD
	if b == 0 {
		return a
	}

	// Calculate GCD using the Euclidean algorithm
	r := -1
	for r!= 0 {
		r = a % b
		a = b
		b = r
	}

	// Return the GCD
	return a
}

// Method to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

