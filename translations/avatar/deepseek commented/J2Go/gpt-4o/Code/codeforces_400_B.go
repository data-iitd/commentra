package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m) // Read the first integer input (number of strings) and the second integer input

	arrs := make([]string, n) // Declare and initialize slice to store strings
	for i := 0; i < n; i++ {
		fmt.Scan(&arrs[i]) // Read each string and store it in the slice
	}

	length := make([]int, n) // Declare and initialize slice to store differences
	index := 0                // Initialize index for the length slice
	returnDex := 0            // Initialize returnDex to store the result

	for _, tmp := range arrs { // Loop through each string in the slice
		dexG := strings.Index(tmp, "G") // Find the index of 'G' in the string
		dexS := strings.Index(tmp, "S") // Find the index of 'S' in the string
		if dexG > dexS {                // Check if 'G' comes after 'S'
			returnDex = -1 // Set returnDex to -1 if 'G' is after 'S'
		}
		length[index] = dexS - dexG // Calculate and store the difference in length slice
		index++
	}

	set := make(map[int]struct{}) // Initialize map to store unique differences
	for _, len := range length {   // Loop through each difference in the length slice
		set[len] = struct{}{} // Add the difference to the map
	}

	if returnDex == -1 { // Check if returnDex is -1
		fmt.Println(returnDex) // Print -1 if 'G' comes after 'S'
	} else {
		fmt.Println(len(set)) // Print the size of the map if 'G' does not come after 'S'
	}
}

// <END-OF-CODE>
