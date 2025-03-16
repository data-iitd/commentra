package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the list

	// Create a map to store unique elements
	uniqueElements := make(map[int]struct{})

	// Read the input elements and store them in the map for uniqueness
	for i := 0; i < n; i++ {
		var value int
		fmt.Scan(&value)
		uniqueElements[value] = struct{}{} // Use an empty struct to represent the presence of the key
	}

	// Create a slice to store the unique elements
	var a []int
	for key := range uniqueElements {
		a = append(a, key) // Append unique keys to the slice
	}

	// Sort the slice
	sort.Ints(a)

	// Check if there exists a sequence of three consecutive elements with a difference of 1
	found := false
	for i := 0; i < len(a)-2; i++ { // Iterate through the slice
		if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] { // Check if the difference is 1
			found = true // Set the found flag if a sequence is found
			break        // Exit the loop if a sequence is found
		}
	}

	// Write the output to the console
	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
