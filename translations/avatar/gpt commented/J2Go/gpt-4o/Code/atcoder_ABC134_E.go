package main

import (
	"container/list"
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Create a map to store integers and their counts
	counts := make(map[int]int)

	// Process each integer input
	for n > 0 {
		var num int
		fmt.Scan(&num)
		n--

		// Check if there is no lower key in the map
		var lowerKey int
		var found bool
		for key := range counts {
			if key < num {
				if !found || key > lowerKey {
					lowerKey = key
					found = true
				}
			}
		}

		if !found {
			// If no lower key exists, increment the count for the current number
			counts[num]++
		} else {
			// If there is a lower key, get that key and its count
			val := counts[lowerKey]

			// If the count of the lower key is 1, remove it from the map
			if val == 1 {
				delete(counts, lowerKey)
			} else {
				// Otherwise, decrement the count of the lower key
				counts[lowerKey]--
			}

			// Increment the count for the current number
			counts[num]++
		}
	}

	// Initialize a variable to hold the final answer
	ans := 0

	// Sum up all the counts in the map
	for _, val := range counts {
		ans += val
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
