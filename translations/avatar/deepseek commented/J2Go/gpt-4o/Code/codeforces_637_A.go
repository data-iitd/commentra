package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	ara := make([]int, n) // Initialize slice to store elements
	countMap := make(map[int]int) // Map to count occurrences of each element

	// Populate the slice and the map with element counts
	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v)
		ara[i] = v
		countMap[v]++ // Increment count for the element
	}

	max := 0 // Initialize max to track the highest frequency
	// Find the maximum frequency in the map
	for _, count := range countMap {
		if count > max {
			max = count
		}
	}

	occurrenceMap := make(map[int]int) // Map to track occurrences as elements appear
	// Find the most frequent element
	for i := 0; i < n; i++ {
		if _, exists := occurrenceMap[ara[i]]; !exists {
			occurrenceMap[ara[i]] = 1 // Initialize count for new element
		} else {
			occurrenceMap[ara[i]]++ // Increment count for existing element
		}
		if occurrenceMap[ara[i]] == max {
			fmt.Println(ara[i]) // Print the most frequent element
			break // Exit the loop after finding the most frequent element
		}
	}
}

// <END-OF-CODE>
