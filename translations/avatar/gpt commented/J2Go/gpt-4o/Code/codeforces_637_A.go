package main

import (
	"fmt"
)

func main() {
	// Create a scanner for input
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the elements
	ara := make([]int, n)

	// Create a map to count the frequency of each element
	frequencyMap := make(map[int]int)

	// Read elements and populate the frequency map
	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v)
		ara[i] = v
		frequencyMap[v]++
	}

	// Find the maximum frequency among the elements
	max := 0
	for _, count := range frequencyMap {
		if count > max {
			max = count
		}
	}

	// Create another map to track the order of elements while checking frequency
	orderMap := make(map[int]int)

	// Iterate through the original array to find the first element with maximum frequency
	for i := 0; i < n; i++ {
		if _, exists := orderMap[ara[i]]; !exists {
			orderMap[ara[i]] = 1
			// Check if the current element's frequency matches the maximum frequency
			if frequencyMap[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		} else {
			orderMap[ara[i]]++
			// Check if the current element's frequency matches the maximum frequency
			if frequencyMap[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		}
	}
}

// <END-OF-CODE>
