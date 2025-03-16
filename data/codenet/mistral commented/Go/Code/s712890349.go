// Importing required packages
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a custom type 'Block'
type Block struct {
	Value string
	Len   int
}

// Main function starts the execution
func main() {
	// Initialize variables
	var N, K, ans int

	// Read input values for N and K from the standard input
	fmt.Scan(&N, &K)

	// Initialize a buffer scanner for reading input from the standard input
	var S string
	s := bufio.NewScanner(os.Stdin)

	// Allocate a byte slice of size 1,000,000 for reading input
	b := make([]byte, 1000000)

	// Set the buffer size for the buffer scanner
	s.Buffer(b, 1000000)

	// Read the input string S from the standard input
	s.Scan()

	// Assign the read string to the variable S
	S = s.Text()

	// Call the RunLength function to get the run-length encoded blocks
	blocks := RunLength(S)

	// Initialize variables sum, zero and length l
	sum, zero, l := 0, 0, 0

	// Loop through all the blocks in the blocks slice
	for r := 0; r < len(blocks); r++ {
		// Increment the sum by the length of the current block
		sum += blocks[r].Len

		// If the current block's value is '0', increment the zero counter
		if blocks[r].Value == "0" {
			zero++
		}

		// While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
		for K < zero {
			sum -= blocks[l].Len
			if blocks[l].Value == "0" {
				zero--
			}
			l++
		}

		// Update the answer with the maximum of the current answer and the sum
		ans = Max(ans, sum)
	}

	// Print the final answer
	fmt.Println(ans)
}

// RunLength function to get the run-length encoded blocks
func RunLength(s string) []Block {
	// If the length of the input string is zero, return an empty slice
	if len(s) == 0 {
		return []Block{}
	}

	// Initialize the first block with the first character and length one
	t := Block{Value: string(s[0]), Len: 1}

	// Initialize an empty slice to store the blocks
	var r []Block

	// Loop through all the characters in the input string starting from the second character
	for _, v := range s[1:] {
		// If the current character is the same as the previous character, increment the length of the current block
		if t.Value == string(v) {
			t.Len++
		} else {
			// Add the previous block to the result slice
			r = append(r, t)

			// Initialize a new block with the current character and length one
			t = Block{Value: string(v), Len: 1}
		}
	}

	// Add the last block to the result slice
	r = append(r, t)

	// Return the result slice
	return r
}

// Max function to find the maximum of two integers
func Max(a, b int) int {
	// If b is greater than a, return b, otherwise return a
	if b > a {
		return b
	}
	return a
}

// End of the code
