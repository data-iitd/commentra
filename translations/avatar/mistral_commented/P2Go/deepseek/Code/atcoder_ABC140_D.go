package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to parse input line by line
func parser() func() string {
	// Continuously parse input lines
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return func() string {
		// Check if there is a next token
		if scanner.Scan() {
			// Return the next token
			return scanner.Text()
		}
		// If no more tokens, return an empty string
		return ""
	}
}

// Create a parser object
var inputParser = parser()

// Function to get the next token from the parser
func gw() string {
	// Get the next token from the parser
	return inputParser()
}

// Function to get the next integer from the parser
func gi() int {
	// Get the next token as a string
	data := gw()
	// Convert the token to an integer
	num, _ := strconv.Atoi(data)
	return num
}

// Global variables
const MOD = 1e9 + 7

// Import additional libraries for scientific computing
// (Note: Go does not have built-in support for scientific computing libraries like numpy and scipy)

// Define a slice for segment count
var segCnt []int

// Get the number of segments in the string
N := gi()

// Get the number of queries
K := gi()

// Get the string S
S := gw()

// Initialize segment count
segCnt = make([]int, 0)

// Iterate through the string and count the number of segments
for i := 0; i < N - 1; i++ {
	// Check if the current character is different from the next character
	if S[i] != S[i + 1] {
		// Add 1 to the segment count
		segCnt = append(segCnt, 1)
	}
}

// Calculate the current happiness
curHappy := N - 1 - len(segCnt)

// Check if the number of queries is greater than or equal to the number of segments
if 2 * K >= len(segCnt) {
	// If yes, then the answer is the total number of segments
	ans := N - 1
	// Otherwise, the answer is the current happiness plus twice the number of queries
} else {
	ans := curHappy + 2 * K
}

// Print the answer
fmt.Println(ans)

