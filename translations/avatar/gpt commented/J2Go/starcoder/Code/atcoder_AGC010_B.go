package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Read and parse the input from stdin
	fmt.Print("Enter the number of elements in the array: ")
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	// Initialize an array A to hold N integers
	A := make([]int, N)

	// Populate the array A with N integers from user input
	for i := 0; i < N; i++ {
		fmt.Printf("Enter the %d element: ", i + 1)
		scanner.Scan()
		A[i], _ = strconv.Atoi(scanner.Text())
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
	NS := (N * (N + 1)) / 2

	// Check if the total sum is divisible by NS; if not, return false
	if sum % NS!= 0 {
		return false
	}

	// Calculate the value of K which is the target average
	K := sum / NS

	// Verify the condition for each element in the array
	for i := 0; i < N; i++ {
		// Determine the previous index in a circular manner
		j := i == 0? N - 1 : i - 1

		// Calculate the difference d needed to satisfy the condition
		d := K - (A[i] - A[j])

		// If d is negative or not divisible by N, return false
		if d < 0 || d % N!= 0 {
			return false
		}
	}

	// If all conditions are satisfied, return true
	return true
}

