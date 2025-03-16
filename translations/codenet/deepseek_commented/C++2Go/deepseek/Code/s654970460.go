package main

import (
	"fmt"
)

func main() {
	var n int
	var a [101]int
	var i int

	fmt.Scan(&n) // Input the number of elements for the array 'a'.
	for i = 0; i < n; i++ {
		fmt.Scan(&a[i]) // Take 'n' integer inputs and store them in the array 'a'.
	}
	fmt.Print(a[n-1]) // Output the last element of the array 'a'.
	for i = 1; i < n; i++ {
		fmt.Print(" ", a[n-i-1]) // Output the remaining elements of the array 'a' in reverse order.
	}
	fmt.Println() // End the line after outputting all the elements.
}

