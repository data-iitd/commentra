package main

import (
	"fmt"
	"os"
)

func main() {
	// Reading the number of elements 'n' in the list 'w'
	var n int
	fmt.Fscan(os.Stdin, &n)

	// Initializing a slice 'w' to store the elements
	w := make([]int, n)

	// Reading the elements into the slice 'w'
	for i := 0; i < n; i++ {
		fmt.Fscan(os.Stdin, &w[i])
	}

	// Initializing a slice 'd' to store the indices of the elements that satisfy the condition
	d := []int{}

	// Calculating the total sum of the elements in 'w'
	var total int
	for _, value := range w {
		total += value
	}

	// Iterating through each element 'i' in the list 'w'
	for i := 0; i < n; i++ {
		// Checking if the average of the remaining sum of elements after removing 'w[i]' is equal to 'w[i]'
		if (total - w[i])/(n-1) == w[i] {
			// If the condition is true, append the index 'i+1' to the slice 'd'
			d = append(d, i+1)
		}
	}

	// Printing the length of the slice 'd'
	fmt.Println(len(d))

	// Printing the elements of the slice 'd' separated by a space
	for i, index := range d {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(index)
	}
	fmt.Println()
}

// <END-OF-CODE>
