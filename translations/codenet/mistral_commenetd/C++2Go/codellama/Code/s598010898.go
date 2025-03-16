
package main

import (
	"fmt"
)

func main() {
	var n int // Declare an integer variable 'n' to store the number of elements in arrays 'a' and 'b'
	fmt.Scan(&n) // Read the number of elements 'n' from the standard input

	a := make([]int, 100) // Declare an integer array 'a' of size 100
	b := make([]int, 100) // Declare an integer array 'b' of size 100
	sum := 0 // Declare an integer variable 'sum' and initialize it to zero

	for i := 0; i < n; i++ { // Iterate through the array 'a' and read its elements from the standard input
		fmt.Scan(&a[i])
	}

	for i := 0; i < n; i++ { // Iterate through the array 'b' and read its elements from the standard input
		fmt.Scan(&b[i])

		if a[i]-b[i] > 0 { // Check if the difference between 'a[i]' and 'b[i]' is positive
			sum += a[i] - b[i] // If it is, add the difference to the variable 'sum'
		}
	}

	fmt.Println(sum) // Output the value of the variable 'sum' to the standard output
}

