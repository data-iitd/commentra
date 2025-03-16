package main

import (
	"fmt"
)

const (
	maxDataSize = 111111
	maxSeqSize  = 222222
)

// Declare global slices to store data and sequences
var data [maxDataSize]int // Slice to store the frequency of each number
var seq [maxSeqSize]int   // Slice to store sequences of consecutive numbers

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k, t, ret int

	// Loop to read input values and process them
	for {
		// Read values of n and k
		fmt.Scan(&n, &k)
		if n == 0 && k == 0 {
			break // Break the loop if both n and k are zero
		}

		// Initialize the data and seq slices to zero
		for i := range data {
			data[i] = 0
		}
		for i := range seq {
			seq[i] = 0
		}

		// Read k numbers and store their frequencies in data
		for i := 0; i < k; i++ {
			fmt.Scan(&t)
			data[t]++
		}

		// Construct the seq array based on the frequencies in data
		p := 0
		for i := 1; i <= n; i++ {
			if data[i] > 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++

		// Calculate the maximum value of ret based on the sequences in seq
		if data[0] > 0 {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i := 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		// Print the result
		fmt.Println(ret)
	}
}

// Function to return the maximum of two integers
// This function is already defined above.
