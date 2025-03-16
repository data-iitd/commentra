package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements N
	var N int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &N)

	// Initialize an array A to hold N integers
	A := make([]int, N)

	// Populate the array A with N integers from user input
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &A[i])
	}

	// Check if it is possible to achieve the desired condition with the array A
	if possible(N, A) {
		// If possible, print "YES"
		fmt.Println("YES")
	} else {
		// If not possible, print "NO"
		fmt.Println("NO")
	}
}

// Method to determine if the condition can be satisfied
func possible(N int, A []int) bool {
	// Calculate the sum of all elements in the array A
	sum := 0
	for i := 0; i < N; i++ {
		sum += A[i]
	}

	// Calculate the expected sum NS based on the formula for the sum of the first N natural numbers
	NS := (float64(N) * (float64(N) + 1)) / 2

	// Check if the total sum is divisible by NS; if not, return false
	if sum%int(NS) != 0 {
		return false
	}

	// Calculate the value of K which is the target average
	K := sum / int(NS)

	// Verify the condition for each element in the array
	for i := 0; i < N; i++ {
		// Determine the previous index in a circular manner
		j := i - 1
		if j < 0 {
			j = N - 1
		}

		// Calculate the difference d needed to satisfy the condition
		d := K - (A[i] - A[j])

		// If d is negative or not divisible by N, return false
		if d < 0 || d%N != 0 {
			return false
		}
	}

	// If all conditions are satisfied, return true
	return true
}

// 