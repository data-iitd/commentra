package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int
	var a [1000]int
	d := 0

	// Read the number of elements in the array
	fmt.Scan(&n)

	// Read the elements of the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Bubble sort algorithm to sort the array in ascending order
	for i := 0; i < n; i++ {
		for j := n - 1; j >= i+1; j-- {
			if a[j] < a[j-1] {
				// Swap the elements if they are in the wrong order
				temp := a[j]
				a[j] = a[j-1]
				a[j-1] = temp
				// Increment the swap counter
				d++
			}
		}
	}

	// Print the sorted array
	fmt.Print(a[0])
	for i := 1; i < n; i++ {
		fmt.Printf(" %d", a[i])
	}
	fmt.Println()

	// Print the number of swaps made during the sorting process
	fmt.Println(d)
}

// <END-OF-CODE>
