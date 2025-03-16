package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	var k int64
	fmt.Scan(&n, &k) // Step 2: Read input values

	arr := make([]int64, n) // Step 3: Read input values
	set := make(map[int64]struct{}) // Step 3: Read input values

	for i := 0; i < n; i++ { // Step 4: Read array elements
		fmt.Scan(&arr[i])
	}

	sort.Slice(arr, func(i, j int) bool { // Step 5: Sort the array
		return arr[i] < arr[j]
	})

	count := 0 // Step 6: Initialize count variable

	for i := 0; i < n; i++ { // Step 7: Iterate through the array
		if arr[i]%k != 0 { // Check if the element is not divisible by k
			count++ // Increment the count
			set[arr[i]] = struct{}{} // Add the element to the set
		} else if _, exists := set[arr[i]/k]; !exists { // Check if the quotient is not in the set
			count++ // Increment the count
			set[arr[i]] = struct{}{} // Add the element to the set
		}
	}

	fmt.Println(count) // Step 8: Print the result
}

// <END-OF-CODE>
