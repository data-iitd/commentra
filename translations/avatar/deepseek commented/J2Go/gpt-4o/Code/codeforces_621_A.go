package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	list := make([]int64, n) // Create a slice to store the elements

	for i := 0; i < n; i++ {
		fmt.Scan(&list[i]) // Read the elements and store them in the slice
	}

	odd := []int64{} // Slice to store odd numbers
	sum := int64(0)  // Initialize sum of numbers

	for _, i := range list { // Iterate through the slice
		if i%2 == 0 {
			sum += i // Add to sum if the number is even
		} else {
			odd = append(odd, i) // Add to odd slice if the number is odd
		}
	}

	sort.Slice(odd, func(i, j int) bool { return odd[i] < odd[j] }) // Sort the slice of odd numbers

	for _, i := range odd {
		sum += i // Add all odd numbers to the sum
	}

	if len(odd)%2 != 0 {
		sum -= odd[0] // Subtract the smallest odd number if the count of odd numbers is odd
	}

	fmt.Println(sum) // Print the final sum
}

// <END-OF-CODE>
