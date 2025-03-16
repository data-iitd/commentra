
package main

import (
	"fmt"
)

func main() {
	var n, t int // Variables to store the number of test cases and the current test case
	st := make([]bool, 7) // A boolean array to store the current segment tree state

	for { // Reading the number of test cases and processing them while there are still test cases to be processed
		fmt.Scan(&n)
		if n == -1 {
			break
		}
		for i := 0; i < 7; i++ {
			st[i] = false // Initializing the segment tree state to all zeros
		}
		for i := 0; i < n; i++ { // Processing each test case
			fmt.Scan(&t) // Reading the current test case
			ans := make([]byte, 8) // Initializing an array to store the answer as a string of 0s and 1s
			for i := 0; i < 7; i++ { // Iterating through each bit position in the segment tree
				ans[i] = byte(st[i] ^ seg[t][i]) // Updating the answer based on the current segment tree state and the current test case
				st[i] = seg[t][i] // Updating the segment tree state for the current bit position
			}
			fmt.Println(string(ans)) // Printing the answer for the current test case
		}
	}
}

var seg = [13][7]bool{ // A 2D boolean array representing the segment tree
	{false, true, true, true, true, true, true},
	{false, false, false, false, true, true, false},
	{true, false, true, true, false, true, true},
	{true, false, false, true, true, true, true},
	{true, true, false, false, true, true, false},
	{true, true, false, true, true, false, true},
	{true, true, true, true, true, false, true},
	{false, true, false, false, true, true, true},
	{true, true, true, true, true, true, true},
	{true, true, false, true, true, true, true},
}

