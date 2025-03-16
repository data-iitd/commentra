<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare global arrays to store data and sequences
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
	var n, k, t, i, p, ret int

	// Loop to read input values and process them
	for {
		// Read values of n and k
		fmt.Scanf("%d %d", &n, &k)
		if n == 0 && k == 0 {
			break
		}

		// Initialize the data and seq arrays to zero
		for i = 0; i < len(data); i++ {
			data[i] = 0
		}
		for i = 0; i < len(seq); i++ {
			seq[i] = 0
		}

		// Read k numbers and store their frequencies in data
		for i = 0; i < k; i++ {
			fmt.Scanf("%d", &t)
			data[t]++
		}

		// Construct the seq array based on the frequencies in data
		p = 0
		for i = 1; i <= n; i++ {
			if data[i] > 0 {
				seq[p]++
			} else {
				p += 2
			}
		}
		p++

		// Calculate the maximum value of ret based on the sequences in seq
		if data[0] > 0 {
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i]+seq[i+2]+1)
			}
		} else {
			for i = 0; i < p; i++ {
				ret = max(ret, seq[i])
			}
		}

		// Print the result
		fmt.Printf("%d\n", ret)
	}
}

