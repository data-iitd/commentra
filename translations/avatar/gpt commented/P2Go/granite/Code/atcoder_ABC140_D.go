
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to parse input data
func parser() func() string {
	scanner := bufio.NewScanner(os.Stdin)
	return func() string {
		scanner.Scan()
		return scanner.Text()
	}
}

// Function to get the next value from the input parser as a string
func gw() string {
	return next()
}

// Function to get the next value from the input parser and convert it to an integer
func gi() int {
	result, err := strconv.Atoi(gw())
	if err!= nil {
		panic(err)
	}
	return result
}

// Define a constant for the modulo operation
const MOD = 100000007

// Import necessary libraries
import "math"

// Read the number of elements N and the integer K from input
var N int
var K int

// Read the string S from input
var S string

// Initialize a counter for segments
var seg_cnt int

// Count the number of segments in the string S
func init() {
	N = gi()
	K = gi()
	S = gw()
	for i := 0; i < N-1; i++ {
		if S[i]!= S[i+1] {
			seg_cnt++
		}
	}
}

// Calculate the current happiness based on the number of segments
var cur_happy int

// Determine the final answer based on the relationship between K and seg_cnt
var ans int

func main() {
	if 2*K >= seg_cnt {
		ans = N - 1 // If K is sufficient to cover all segments
	} else {
		cur_happy = N - 1 - seg_cnt // Otherwise, calculate based on current happiness and K
		ans = cur_happy + 2*K       // Calculate the final answer
	}
	fmt.Println(ans)
}

