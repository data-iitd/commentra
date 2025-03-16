
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a line of input and strip whitespace
func readInput() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to read an integer from input
func readInt() int {
	input := readInput()
	value, _ := strconv.Atoi(input)
	return value
}

// Function to read a list of integers from input
func readInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = readInt()
	}
	return ints
}

func main() {
	// Read the number of elements
	n := readInt()

	// Read the list of integers
	a := readInts(n)

	// Remove consecutive duplicates from the list
	a = removeConsecutiveDuplicates(a)

	// Update N to the new length of A after removing duplicates
	n = len(a)

	// Initialize the index and answer counter
	i := 1
	ans := 0

	// Loop through the list to count the number of peaks and valleys
	for i < n - 1 {
		// Check if the current element is a peak or a valley
		if a[i - 1] < a[i] > a[i + 1] || a[i - 1] > a[i] < a[i + 1] {
			ans += 1  // Increment the answer for each peak/valley found
			i += 1    // Skip the next element to avoid double counting
		}
		i += 1  // Move to the next element

	}

	// Print the total count of peaks and valleys plus one
	fmt.Println(ans + 1)
}

// Function to remove consecutive duplicates from a list
func removeConsecutiveDuplicates(a []int) []int {
	b := []int{a[0]}
	for i := 1; i < len(a); i++ {
		if a[i]!= b[len(b) - 1] {
			b = append(b, a[i])
		}
	}
	return b
}

