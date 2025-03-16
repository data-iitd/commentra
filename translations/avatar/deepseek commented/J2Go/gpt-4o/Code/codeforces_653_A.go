package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of integers
	a := make([]int, 0, n) // Create a slice to store the integers

	for i := 0; i < n; i++ {
		var value int
		fmt.Scan(&value) // Read each integer value
		a = append(a, value) // Add the value to the slice
	}

	// Remove duplicates
	uniqueMap := make(map[int]struct{})
	for _, value := range a {
		uniqueMap[value] = struct{}{}
	}

	// Convert map keys to slice
	uniqueSlice := make([]int, 0, len(uniqueMap))
	for key := range uniqueMap {
		uniqueSlice = append(uniqueSlice, key)
	}

	// Sort the slice
	sort.Ints(uniqueSlice)

	// Check for three consecutive integers
	found := false
	for i := 0; i < len(uniqueSlice)-2; i++ {
		if uniqueSlice[i]+1 == uniqueSlice[i+1] && uniqueSlice[i+1]+1 == uniqueSlice[i+2] {
			found = true // Set the flag if three consecutive integers are found
			break
		}
	}

	if found {
		fmt.Println("YES") // Print "YES" if consecutive integers are found
	} else {
		fmt.Println("NO") // Print "NO" otherwise
	}
}

// <END-OF-CODE>
