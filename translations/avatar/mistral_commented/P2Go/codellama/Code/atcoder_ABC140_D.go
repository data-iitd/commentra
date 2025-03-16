#######
# Code
#######

// Import necessary libraries
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to parse input line by line
func parser() {
	// Continuously parse input lines
	for {
		data := make([]string, 0)
		// Get the next line of input
		input, err := bufio.NewReader(os.Stdin).ReadString('\n')
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
		// Split the input line into tokens
		tokens := make([]string, 0)
		for _, token := range ([]rune(input)) {
			if token != ' ' {
				tokens = append(tokens, string(token))
			}
		}
		// Process each token in the input line
		for _, number := range tokens {
			// Check if the token is empty or not
			if len(number) > 0 {
				// Yield the token as a result of the function
				data = append(data, number)
			}
		}
		// Check if the input line is empty
		if len(data) == 0 {
			// If yes, then break the loop
			break
		}
		// Yield the data as a result of the function
		yield(data)
	}
}

// Create a parser object
input_parser := parser()

// Function to get the next token from the parser
func gw() string {
	// Get the next token from the parser
	data := <-input_parser
	// Return the next token
	return data[0]
}

// Function to get the next integer from the parser
func gi() int {
	// Get the next token as a string
	data := gw()
	// Convert the token to an integer
	number, err := strconv.Atoi(data)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	// Return the integer
	return number
}

// Global variables
MOD := int(1e9 + 7)

// Import additional libraries for scientific computing
import "github.com/gonum/matrix/mat64"

// Define a deque for segment count
var seg_cnt []int

// Get the number of segments in the string
N := gi()

// Get the number of queries
K := gi()

// Get the string S
S := gw()

// Initialize segment count
seg_cnt = make([]int, 0)

// Iterate through the string and count the number of segments
for i := 0; i < N-1; i++ {
	// Check if the current character is different from the next character
	if S[i] != S[i+1] {
		// Add 1 to the segment count
		seg_cnt = append(seg_cnt, 1)
	}
}

// Calculate the current happiness
cur_happy := N - 1 - len(seg_cnt)

// Check if the number of queries is greater than or equal to the number of segments
if 2*K >= len(seg_cnt) {
	// If yes, then the answer is the total number of segments
	ans := N - 1
	// Otherwise, the answer is the current happiness plus twice the number of queries
} else {
	ans := cur_happy + 2*K
}

// Print the answer
fmt.Println(ans)


