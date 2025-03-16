package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constants for maximum sizes
const (
	MAX_N   = 2000001 // Maximum number of elements
	MAX_Ai  = 10001   // Maximum value of elements
	STR_SIZE = 10000010 // Size of the output string
)

// Function prototypes
func getNum(input *string) (int, *string) // Function to read an integer from the input string
func putNum(n int) string                  // Function to write an integer to a string
func CountingSort(A []int, B []int, k int, len int) // Counting sort algorithm

func main() {
	var n int // Number of elements to sort

	// Read the entire input into a string
	input, _ := os.ReadFile("/dev/stdin")
	inputStr := string(input)

	// Get the number of elements from the input
	n, inputStr = getNum(&inputStr)

	// Create arrays for input and output
	A := make([]int, MAX_N)
	B := make([]int, MAX_N)

	// Read each number into the array A
	for i := 1; i <= n; i++ {
		A[i], inputStr = getNum(&inputStr)
	}

	// Perform counting sort on the array A and store the result in B
	CountingSort(A, B, MAX_Ai, n)

	// Prepare the output string
	var output strings.Builder
	for i := 1; i < n; i++ {
		output.WriteString(putNum(B[i]))
		output.WriteString(" ") // Append a space after each number
	}
	output.WriteString(putNum(B[n])) // Append the last number without a trailing space

	// Output the final result
	fmt.Println(output.String())
}

// Function to read an integer from the input string
func getNum(input *string) (int, *string) {
	n := 0 // Variable to store the number
	for len(*input) > 0 && (*input)[0] >= '0' && (*input)[0] <= '9' {
		n = n*10 + int((*input)[0]-'0') // Build the number
		*input = (*input)[1:] // Move to the next character
	}
	if len(*input) > 0 {
		*input = (*input)[1:] // Skip the non-digit character (likely a space or newline)
	}
	return n, input // Return the read number and the remaining input
}

// Function to write an integer to a string
func putNum(n int) string {
	if n < 10 {
		return string('0' + byte(n)) // Convert to character and return
	}
	return putNum(n/10) + string('0'+byte(n%10)) // Recursively write the digits of the number
}

// Counting sort algorithm implementation
func CountingSort(A []int, B []int, k int, len int) {
	C := make([]int, MAX_Ai) // Count array initialized to zero

	// Count occurrences of each number in A
	for j := 1; j <= len; j++ {
		C[A[j]]++ // Increment count for each number
	}

	// Update count array to hold the position of each number
	for i := 1; i <= k; i++ {
		C[i] += C[i-1] // C[i] now contains the position
	}

	// Build the output array B using the count array
	for j := len; j > 0; j-- {
		B[C[A[j]]] = A[j] // Place the number in the correct position
		C[A[j]]-- // Decrement the count for the number
	}
}

// <END-OF-CODE>
