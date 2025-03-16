package main

import (
	"fmt"
)

func main() {
	// Step 3: Create a Scanner object to read input from the user
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	// Step 5: Create two slices to store the lists of integers
	list1 := make([]int, 0, a)
	list2 := make([]int, 0, b)

	// Step 6: Read the elements of list1 and list2 from the user
	for i := 0; i < a; i++ {
		var num int
		fmt.Scan(&num)
		list1 = append(list1, num)
	}
	for i := 0; i < b; i++ {
		var num int
		fmt.Scan(&num)
		list2 = append(list2, num)
	}

	// Step 7: Iterate through the range from 1 to n and print the appropriate list number
	for i := 1; i <= n; i++ {
		if contains(list1, i) {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

// Helper function to check if a slice contains a specific integer
func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
