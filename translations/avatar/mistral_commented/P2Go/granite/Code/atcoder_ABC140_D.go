
###
# Code
###

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Function to parse input line by line
func parser() <-chan string {
	// Continuously parse input lines
	out := make(chan string)
	go func() {
		in := bufio.NewReader(os.Stdin)
		line, _ := in.ReadString('\n')
		for line!= "" {
			out <- line
			line, _ = in.ReadString('\n')
		}
		close(out)
	}()
	return out
}

// Function to get the next token from the parser
func gw() string {
	// Get the next token from the parser
	data, more := <-input_parser
	if more {
		return data
	}
	panic("No more token.")
}

// Function to get the next integer from the parser
func gi() int {
	// Get the next token as a string
	data := gw()
	// Convert the token to an integer
	result, err := strconv.Atoi(data)
	if err!= nil {
		panic("Invalid integer.")
	}
	return result
}

// Global variables
const MOD = int(1e9 + 7)

// Define a deque for segment count
var seg_cnt = make([]int, 0)

// Get the number of segments in the string
func main() {
	// Get the number of segments
	N := gi()
	// Get the number of queries
	K := gi()
	// Get the string S
	S := gw()
	// Initialize segment count
	seg_cnt = seg_cnt[:0]
	// Iterate through the string and count the number of segments
	for i := 0; i < N-1; i++ {
		// Check if the current character is different from the next character
		if S[i]!= S[i+1] {
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
	} else {
		// Otherwise, the answer is the current happiness plus twice the number of queries
		ans = cur_happy + 2*K
	}
	// Print the answer
	fmt.Println(ans)
}

