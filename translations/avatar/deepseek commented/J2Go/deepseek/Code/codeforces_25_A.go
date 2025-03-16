package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array
	array := make([]int, n+1) // Initializing an array of size n+1

	// Populating the array with integers from the user input
	for i := 1; i <= n; i++ {
		fmt.Scan(&array[i])
	}

	odd, even := 0, 0
	var odd_ind, even_ind int

	// Counting the number of odd and even numbers and recording their indices
	for i := 1; i <= n; i++ {
		if array[i] % 2 == 0 {
			even++
			even_ind = i
		} else {
			odd++
			odd_ind = i
		}
	}

	// Comparing the counts of odd and even numbers and printing the index of the majority
	if odd > even {
		fmt.Println(even_ind)
	} else {
		fmt.Println(odd_ind)
	}
}
