
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

const (
	MAX_N     = 2000001
	MAX_Ai    = 10001
	STR_SIZE  = 10000010
)

var (
	str = make([]byte, STR_SIZE)
	p   = str
)

func main() {
	var (
		i, n int
		A     = make([]int, MAX_N)
		B     = make([]int, MAX_N)
	)

	// Read the entire input into the string
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(str, STR_SIZE)
	scanner.Scan()

	// Get the number of elements from the input
	n = getNum()
	// Read each number into the array A
	for i = 1; i <= n; i++ {
		A[i] = getNum()
	}

	// Perform counting sort on the array A and store the result in B
	CountingSort(A, B, MAX_Ai, n)

	// Reset the pointer to the start of the output string
	p = str
	n-- // Adjust n for zero-based indexing
	// Write the sorted numbers to the output string
	for i = 1; i <= n; i++ {
		putNum(B[i]) // Convert number to string and append
		*p =''      // Append a space after each number
		p++
	}
	putNum(B[i]) // Append the last number without a trailing space
	*p = '\0'    // Null-terminate the output string

	// Output the final result
	fmt.Println(string(str))
}

// Function to read an integer from the input string
func getNum() int {
	var (
		n int
		d int
	)
	// Read digits until a non-digit character is encountered
	for *p >= '0' && *p <= '9' {
		n = n*10 + int(*p-'0') // Build the number
		p++                      // Move to the next character
	}
	p++ // Skip the non-digit character (likely a space or newline)
	return n // Return the read number
}

// Function to write an integer to the output string
func putNum(n int) {
	var d int
	// Handle single-digit numbers directly
	if n < 10 {
		*p = byte('0' + n) // Convert to character and append
		p++
		return
	}
	// Recursively write the digits of the number
	d = n / 10
	if d > 0 {
		putNum(d) // Recursively call for the quotient
	}
	*p = byte('0' + (n - (d * 10))) // Append the last digit
	p++
}

// Counting sort algorithm implementation
func CountingSort(A, B []int, k, len int) {
	C := make([]int, MAX_Ai)
	var i, j int
	// Count occurrences of each number in A
	for j = 1; j <= len; j++ {
		C[A[j]]++ // Increment count for each number
	}
	// Update count array to hold the position of each number
	for i = 1; i <= k; i++ {
		C[i] += C[i-1] // C[i] now contains the position
	}
	// Build the output array B using the count array
	for j = len; j > 0; j-- {
		B[C[A[j]]] = A[j] // Place the number in the correct position
		C[A[j]]--          // Decrement the count for the number
	}
}

// Translate the above C code to Go and end with comment "