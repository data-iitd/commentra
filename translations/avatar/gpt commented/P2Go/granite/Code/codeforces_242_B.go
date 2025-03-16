
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Define a lambda function to read a list of integers from input
	I := func() []int {
		var res []int
		in := bufio.NewReader(os.Stdin)
		for {
			s, err := in.ReadString(' ')
			if err!= nil {
				break
			}
			s = s[:len(s)-1]
			num, err := strconv.Atoi(s)
			if err!= nil {
				break
			}
			res = append(res, num)
		}
		return res
	}

	// Define a lambda function to read a single line of input as a string
	IS := func() string {
		s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
		return s[:len(s)-1]
	}

	// Define a lambda function to read a single integer from input
	IN := func() int {
		res, _ := strconv.Atoi(IS())
		return res
	}

	// Define a lambda function to read a single float from input
	IF := func() float64 {
		res, _ := strconv.ParseFloat(IS(), 64)
		return res
	}

	// Read the number of intervals
	n := IN()

	// Initialize the index for the result
	id := 0

	// Read the first interval's bounds
	l, r := IN(), IN()

	// Iterate through the remaining intervals
	for i := 1; i < n; i++ {
		// Read the current interval's bounds
		li, ri := IN(), IN()

		// Check if the current interval completely contains the previous one
		if li <= l && r <= ri {
			id = i // Update the index to the current interval
		}
		// Check if the current interval overlaps with the previous one
		else if li < l || r < ri {
			id = n // Mark as overlapping by setting id to n
		}

		// Update the bounds of the union of intervals
		l = int(math.Min(float64(l), float64(li))) // Update the left bound
		r = int(math.Max(float64(r), float64(ri))) // Update the right bound
	}

	// Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
	fmt.Println(id)
}
