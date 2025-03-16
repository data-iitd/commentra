package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to calculate the GCD of two numbers
func gcd(a, b int) int {
	if b > a { // Ensure a is greater than b
		a, b = b, a
	}
	if b == 0 { // Base case for GCD
		return a
	}
	r := -1
	for {
		r = a % b
		a = b
		b = r
		if r == 0 {
			break
		}
	}
	return a
}

func main() {
	// Read the number of elements
	N, _ := strconv.Atoi(readLine())

	// Initialize the array A with size N
	A := make([]int, N)

	// Read the elements of A from the input
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(readLine())
	}

	// Arrays to store the prefix and suffix GCDs
	L := make([]int, N)
	R := make([]int, N)

	// Calculate the prefix GCD array L
	L[0] = A[0]
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}

	// Calculate the suffix GCD array R
	R[N-1] = A[N-1]
	for i := N-2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}

	// Initialize the answer with the maximum of the GCD of the first and last elements of L and R
	answer := max(L[N-2], R[1])

	// Iterate through the array to find the maximum GCD
	for i := 1; i < N-1; i++ {
		answer = max(answer, gcd(L[i-1], R[i+1]))
	}

	// Print the final answer
	fmt.Println(answer)
}

// Function to read a line from stdin
func readLine() string {
	r := bufio.NewReader(os.Stdin)
	line, _ := r.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to find the maximum of two numbers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

