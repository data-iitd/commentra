package main

import (
	"fmt"
)

func max(a, b int) int { // Define a function 'max' that returns the maximum of two integers.
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k, t, i, p, ret int // Declare variables 'n' and 'k' for the number of elements and the size of the sequence, 't' as a temporary variable, 'i' as a loop counter, 'p' as a pointer, and 'ret' as the result.

	for {
		fmt.Scan(&n, &k) // Read the number of elements 'n' and the size of the sequence 'k' from the standard input.
		if n == 0 && k == 0 {
			break // If both 'n' and 'k' are zero, break the loop.
		}

		data := make([]int, 111112) // Initialize a slice 'data' of size 111112 for storing the frequency of each number.
		seq := make([]int, 222222)   // Initialize a slice 'seq' of size 222222 for storing the sequence numbers.

		for i = 0; i < k; i++ { // Loop through each number in the sequence.
			fmt.Scan(&t) // Read a number 't' from the standard input.
			data[t]++    // Increment the frequency of the number 't' in the 'data' slice.
		}

		p = 0 // Initialize a pointer 'p' to the first element of the 'seq' slice.
		for i = 1; i <= n; i++ { // Loop through each number from 1 to 'n'.
			if data[i] > 0 { // If the frequency of the number 'i' is not zero, increment the corresponding element in the 'seq' slice.
				seq[p]++
			} else { // If the frequency of the number 'i' is zero, move the pointer 'p' to the next even index.
				p += 2
			}
		}
		p++ // Increment the pointer 'p' to the next index.

		if data[0] > 0 { // If the frequency of the number 0 is not zero, calculate the maximum sum of consecutive sequences in the 'seq' slice.
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1) // Calculate the sum of the current and next sequence and update the maximum sum if necessary.
			}
		} else { // If the frequency of the number 0 is zero, calculate the maximum sum of sequences in the 'seq' slice.
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i]) // Calculate the sum of the current sequence and update the maximum sum if necessary.
			}
		}

		fmt.Println(ret) // Print the maximum sum of sequences to the standard output.
	}
}
