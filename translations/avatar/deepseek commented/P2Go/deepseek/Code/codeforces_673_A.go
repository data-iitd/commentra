package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Take input for the number of elements in the array

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Take input for the array elements
	}

	// Check if the first element of the array is greater than 15
	if arr[0] > 15 {
		fmt.Println(15) // If true, print 15
	} else {
		// Iterate through the array starting from the second element
		for i := 1; i < len(arr); i++ {
			// Check if the difference between the current and previous element is greater than 15
			if arr[i] - arr[i - 1] > 15 {
				fmt.Println(arr[i - 1] + 15) // If true, print the previous element plus 15 and break the loop
				break
			}
		}
		if arr[len(arr)-1] == 90 || arr[len(arr)-1] + 15 >= 90 {
			fmt.Println(90) // If the last element is 90 or adding 15 to the last element is >= 90, print 90
		} else {
			fmt.Println(arr[len(arr)-1] + 15) // Otherwise, print the last element plus 15
		}
	}
}
