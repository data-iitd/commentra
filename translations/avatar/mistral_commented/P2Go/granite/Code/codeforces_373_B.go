
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to calculate the sum of digits in a number
func sum(k int) int {
	// Initialize the sum to zero
	ret := 0
	// Base value for power of ten
	pw := 10
	// Initialize the length of the number to 1
	len := 1

	// Continue the loop until the power of ten is less than or equal to the number
	for {
		// Calculate the current digit
		cur := min(pw-1, k)
		// Calculate the previous power of ten
		prev := pw / 10
		// Add the number of digits in the current power of ten to the sum
		ret += (cur - prev + 1) * len
		// If the power of ten is greater than the number, break the loop
		if pw-1 >= k {
			break
		}
		// Increment the length of the number
		len += 1
		// Multiply the power of ten by 10
		pw *= 10
	}

	// Return the sum of digits in the number
	return ret
}

// Function to find the minimum of two numbers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Initialize the input reader
	reader := bufio.NewReader(os.Stdin)

	// Take input of w, m, and k
	w, _ := strconv.Atoi(read(reader))
	m, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))

	// Initialize the lower bound to 0
	lo := 0
	// Initialize the upper bound to a very large number
	hi := int(1e18)

	// Binary search to find the middle value
	for hi-lo > 1 {
		// Calculate the middle value
		md := (lo + hi) / 2
		// Calculate the sum of digits in the range [m, m+md] and subtract the sum of digits in the range [m-1, m]
		c := sum(m+md-1) - sum(m-1)
		// If the product of the count and k is less than or equal to w, update the lower bound
		if c*k <= w {
			lo = md
		} else {
			// Otherwise, update the upper bound
			hi = md
		}
	}

	// Print the result
	fmt.Println(lo)
}

// Function to read a string from the input reader
func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

// 