package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	n int
	A [MAX_N]int
	B [MAX_N]int
	str string
	p int
)

// Function prototypes
func getNum() int
func putNum(n int)
func CountingSort(A []int, B []int, k int, len int)

func main() {
	var (
		i, j int
	)

	// Read the entire input into the string
	str = readInput()

	// Get the number of elements from the input
	n = getNum()
	// Read each number into the array A
	for i = 1; i <= n; i++ {
		A[i] = getNum()
	}

	// Perform counting sort on the array A and store the result in B
	CountingSort(A, B, MAX_Ai, n)

	// Reset the pointer to the start of the output string
	p = 0
	n--
	// Write the sorted numbers to the output string
	for i = 1; i <= n; i++ {
		putNum(B[i]) // Convert number to string and append
		str += " " // Append a space after each number
	}
	putNum(B[i]) // Append the last number without a trailing space
	str += "\x00" // Null-terminate the output string

	// Output the final result
	fmt.Println(str)
}

// Function to read an integer from the input string
func getNum() int {
	var (
		n int
	)

	// Read digits until a non-digit character is encountered
	for (*p >= '0') && (*p <= '9') {
		n = n * 10 + int(*p - '0') // Build the number
		p++ // Move to the next character
	}
	p++ // Skip the non-digit character (likely a space or newline)
	return n // Return the read number
}

// Function to write an integer to the output string
func putNum(n int) {
	var (
		d int
	)

	// Handle single-digit numbers directly
	if n < 10 {
		str += string(byte('0') + byte(n)) // Convert to character and append
		return
	}

	// Recursively write the digits of the number
	d = n / 10 // Get the quotient
	if d {
		putNum(d) // Recursively call for the quotient
	}
	str += string(byte('0') + byte(n - (d * 10))) // Append the last digit
}

// Counting sort algorithm implementation
func CountingSort(A []int, B []int, k int, len int) {
	var (
		C [MAX_Ai]int
	)
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
		C[A[j]]-- // Decrement the count for the number
	}
}

// Function to read the entire input into the string
func readInput() string {
	var (
		input string
	)

	// Read the entire input into the string
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input = scanner.Text()

	return input
}

// Translate the above Go code to C and end with comment "