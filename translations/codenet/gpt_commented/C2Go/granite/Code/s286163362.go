
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Global arrays to hold data and sequence counts
var data [111111]int
var seq [222222]int

// Function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	// Declare variables for input and results
	var n, k, t, i, p, ret int

	// Infinite loop to continuously read input until termination condition
	for {
		// Read values for n and k
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &k)

		// Break the loop if both n and k are zero
		if n == 0 && k == 0 {
			break
		}

		// Initialize data and seq arrays to zero
		for i = 0; i < 111111; i++ {
			data[i] = 0
		}
		for i = 0; i < 222222; i++ {
			seq[i] = 0
		}

		// Read k integers and count their occurrences in the data array
		for i = 0; i < k; i++ {
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &t)
			data[t-1]++
		}

		// Initialize pointer for the sequence array
		p = 0

		// Build the seq array based on the data array
		for i = 0; i < n; i++ {
			// If the current index has data, increment the sequence count
			if data[i] > 0 {
				seq[p]++
			} else {
				// If no data, move the pointer by 2
				p += 2
			}
		}
		// Increment pointer to account for the last sequence
		p++

		// Calculate the maximum sequence length based on the presence of data[0]
		if data[0] > 0 {
			// If data[0] exists, consider sequences with gaps
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			// If data[0] does not exist, consider sequences without gaps
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		// Print the maximum sequence length found
		fmt.Println(ret)
	}
}

// Translate the above Go code to C and end with comment "