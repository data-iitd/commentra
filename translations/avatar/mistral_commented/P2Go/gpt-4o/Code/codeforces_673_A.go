package main

import (
	"fmt"
)

func main() {
	// Take the number of elements in the list as input
	var n int
	fmt.Scan(&n)

	// Initialize a slice 'arr' to store the input elements
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Check if the first element of the list is greater than 15
	if arr[0] > 15 {
		// If it is, print 15
		fmt.Println(15)
	} else {
		// Else, iterate through the slice starting from the second element
		for i := 1; i < len(arr); i++ {
			// Check if the difference between the current and previous elements is greater than 15
			if arr[i]-arr[i-1] > 15 {
				// If it is, print the previous element plus 15
				fmt.Println(arr[i-1] + 15)
				// Break the loop as we have found the answer
				return
			}
		}
		// Else, if we reach here, it means that no difference was greater than 15
		// Check if the last element of the slice is 90 or if adding 15 to it results in 90 or more
		if arr[len(arr)-1] == 90 || arr[len(arr)-1]+15 >= 90 {
			// If it is, print 90
			fmt.Println(90)
		} else {
			// Else, print the last element plus 15
			fmt.Println(arr[len(arr)-1] + 15)
		}
	}
}

// <END-OF-CODE>
