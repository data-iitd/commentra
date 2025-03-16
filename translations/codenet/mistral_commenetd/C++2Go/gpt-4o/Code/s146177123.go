package main

import (
	"fmt"
)

var seg = [8][7]bool{
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

func main() {
	var n, t int
	st := make([]bool, 7) // A boolean array to store the current segment tree state

	for {
		_, err := fmt.Scan(&n)
		if err != nil || n < 0 { // Reading the number of test cases and processing them while there are still test cases to be processed
			break
		}
		for i := 0; i < 7; i++ {
			st[i] = false // Initializing the segment tree state to all false
		}
		for i := 0; i < n; i++ { // Processing each test case
			fmt.Scan(&t) // Reading the current test case
			ans := make([]byte, 7) // Initializing a slice to store the answer as a string of '0's and '1's
			for j := 0; j < 7; j++ { // Iterating through each bit position in the segment tree
				if st[j]^seg[t][j] {
					ans[j] = '1' // Updating the answer based on the current segment tree state and the current test case
				} else {
					ans[j] = '0'
				}
				st[j] = seg[t][j] // Updating the segment tree state for the current bit position
			}
			fmt.Println(string(ans)) // Printing the answer for the current test case
		}
	}
}

// <END-OF-CODE>
