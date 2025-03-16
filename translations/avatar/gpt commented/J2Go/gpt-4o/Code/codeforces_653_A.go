package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	// Read the number of integers from input
	fmt.Scan(&n)

	// Initialize a map to store unique integers
	nums := make(map[int]struct{})

	// Read n integers from input and add them to the map
	for i := 0; i < n; i++ {
		var value int
		fmt.Scan(&value)
		nums[value] = struct{}{} // Use an empty struct to store unique values
	}

	// Convert the map keys to a slice
	uniqueNums := make([]int, 0, len(nums))
	for num := range nums {
		uniqueNums = append(uniqueNums, num)
	}

	// Sort the slice
	sort.Ints(uniqueNums)

	// Initialize a flag to check for consecutive triplets
	found := false

	// Check for three consecutive integers in the sorted slice
	for i := 0; i < len(uniqueNums)-2; i++ {
		if uniqueNums[i]+1 == uniqueNums[i+1] && uniqueNums[i+1]+1 == uniqueNums[i+2] {
			found = true // Set found to true if consecutive triplet is found
			break
		}
	}

	// Output "YES" if a triplet was found, otherwise output "NO"
	if found {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
