package main

import (
	"fmt"
	"sort"
)

func main() {
	// Creating a variable to read input from the console
	var n int
	// Reading the number of elements to be processed
	fmt.Scan(&n)

	// Initializing a slice to store the input numbers
	list := make([]int64, n)

	// Reading n long integers from input and adding them to the list
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}

	// Initializing a slice to store odd numbers and a variable to hold the sum
	odd := []int64{}
	sum := int64(0)

	// Iterating through the list to separate even and odd numbers
	for _, i := range list {
		if i%2 == 0 {
			// If the number is even, add it to the sum
			sum += i
		} else {
			// If the number is odd, add it to the odd slice
			odd = append(odd, i)
		}
	}

	// Sorting the slice of odd numbers in ascending order
	sort.Slice(odd, func(i, j int) bool {
		return odd[i] < odd[j]
	})

	// Adding all odd numbers to the sum
	for _, i := range odd {
		sum += i
	}

	// If the count of odd numbers is odd, subtract the smallest odd number from the sum
	if len(odd)%2 != 0 {
		sum -= odd[0]
	}

	// Printing the final calculated sum
	fmt.Println(sum)
}

// <END-OF-CODE>
