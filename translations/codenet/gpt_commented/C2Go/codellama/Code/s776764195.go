
package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

// Macro to put a character into the output string and increment the pointer
func PutChar(c byte) {
	*p = c
	p++
}

// Define constants for maximum sizes
const (
	MAX_N    = 2000001 // Maximum number of elements
	MAX_Ai   = 10001   // Maximum value of elements
	STR_SIZE = 1000001 // Size of the output string
)

// Function prototypes
func getNum() int {
	var n int
	var err error
	// Read digits until a non-digit character is encountered
	for *p >= '0' && *p <= '9' {
		n = n*10 + int(*p-'0') // Build the number
		p++                    // Move to the next character
	}
	p++ // Skip the non-digit character (likely a space or newline)
	return n // Return the read number
}

func putNum(n int) {
	var d int
	// Handle single-digit numbers directly
	if n < 10 {
		PutChar('0' + byte(n)) // Convert to character and append
		return
	}
	// Recursively write the digits of the number
	d = n / 10 // Get the quotient
	if d != 0 {
		putNum(d) // Recursively call for the quotient
	}
	PutChar('0' + byte(n-d*10)) // Append the last digit
}

// Counting sort algorithm implementation
func CountingSort(A []int, B []int, k int, len int) {
	C := make([]int, MAX_Ai) // Count array initialized to zero
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

// Global arrays for input and output
var A = make([]int, MAX_N) // Array to hold input numbers
var B = make([]int, MAX_N) // Array to hold sorted numbers
var str = make([]byte, STR_SIZE) // Buffer for output string
var p = str // Pointer to the current position in the output string

func main() {
	var i int
	var n int
	var err error
	// Read the entire input into the string
	str, err = ioutil.ReadAll(os.Stdin)
	if err != nil {
		fmt.Println(err)
		return
	}
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
		PutChar(' ') // Append a space after each number
	}
	putNum(B[i]) // Append the last number without a trailing space
	PutChar('\0') // Null-terminate the output string
	// Output the final result
	fmt.Println(string(str))
}

