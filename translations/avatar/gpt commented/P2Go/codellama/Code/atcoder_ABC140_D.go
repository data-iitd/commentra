
package main

import (
	"fmt"
	"strings"
)

// Function to get the next value from the input parser as a string
func gw() string {
	var data string
	fmt.Scan(&data)
	return data
}

// Function to get the next value from the input parser and convert it to an integer
func gi() int {
	data := gw()
	num, _ := strconv.Atoi(data)
	return num
}

// Define a constant for the modulo operation
const MOD = int(1e9 + 7)

// Import necessary libraries
import "strconv"

// Read the number of elements N and the integer K from input
var N = gi()
var K = gi()

// Read the string S from input
var S = gw()

// Initialize a counter for segments
var seg_cnt = 0

// Count the number of segments in the string S
for i := 0; i < N-1; i++ {
	if S[i] != S[i+1] {
		seg_cnt++
	}
}

// Calculate the current happiness based on the number of segments
var cur_happy = N - 1 - seg_cnt

// Determine the final answer based on the relationship between K and seg_cnt
var ans int
if 2*K >= seg_cnt {
	ans = N - 1 // If K is sufficient to cover all segments
} else {
	ans = cur_happy + 2*K // Otherwise, calculate based on current happiness and K
}

// Print the final answer
fmt.Println(ans)

