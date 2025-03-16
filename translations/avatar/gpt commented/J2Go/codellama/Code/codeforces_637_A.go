package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object for input and PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)

	// Read the number of elements
	n, _ := strconv.Atoi(in.Text())

	// Initialize an array to store the elements
	ara := make([]int, n)

	// Create a map to count the frequency of each element
	map := make(map[int]int)

	// Read elements and populate the frequency map
	for i := 0; i < n; i++ {
		v, _ := strconv.Atoi(in.Text())
		ara[i] = v
		// If the element is not in the map, add it with a count of 1
		if _, ok := map[v]; !ok {
			map[v] = 1
		} else {
			// If it is already in the map, increment its count
			map[v]++
		}
	}

	// Find the maximum frequency among the elements
	max := 0
	for _, v := range map {
		if v > max {
			max = v
		}
	}

	// Create another map to track the order of elements while checking frequency
	mm := make(map[int]int)

	// Iterate through the original array to find the first element with maximum frequency
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]]; !ok {
			mm[ara[i]] = 1
			// Check if the current element's frequency matches the maximum frequency
			if mm[ara[i]] == max {
				fmt.Fprintln(pw, ara[i])
				break
			}
		} else {
			// Increment the count for the existing element
			mm[ara[i]]++
			// Check if the current element's frequency matches the maximum frequency
			if mm[ara[i]] == max {
				fmt.Fprintln(pw, ara[i])
				break
			}
		}
	}

	// Close the PrintWriter
	pw.Flush()
}

// Debugging method to print objects
func debug(obj ...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// END-OF-CODE
