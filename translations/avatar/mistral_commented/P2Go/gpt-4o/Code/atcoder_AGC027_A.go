package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x) // Read n and x from input

	a := make([]int, n) // Create a slice of integers with length n
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read each integer into the slice
	}

	sort.Ints(a) // Sort the slice

	ans := 0 // Initialize ans to 0

	if a[0] > x { // Check if the first element is greater than x
		fmt.Println(0)
		return // Exit the program
	}

	for _, i := range a { // Iterate through each element in the sorted slice
		if i > x { // If the current element is greater than x
			x = 0 // Set x to 0 and break the loop
			break
		}
		x -= i // Subtract the current element from x
		ans++  // Increment ans by 1
	}

	if x != 0 { // If x is not equal to 0 after the loop
		ans-- // Decrement ans by 1
	}

	fmt.Println(ans) // Print the final value of ans
}

// <END-OF-CODE>
