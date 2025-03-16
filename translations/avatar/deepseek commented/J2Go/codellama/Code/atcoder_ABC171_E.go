
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 0) // Create a slice 'sc' to store the input from the user
	var n int // Initialize a variable 'n' to store the number of elements
	var r int // Initialize a variable 'r' to store the result of XOR operation

	// Read the number of elements (n) from the user
	fmt.Scan(&n)

	// Read the elements of the array 'a' from the user and perform XOR operation on each element
	for i := 0; i < n; i++ {
		var a int // Initialize a variable 'a' to store the element
		fmt.Scan(&a)
		sc = append(sc, a)
		r ^= a
	}

	// Print the result of XOR operation for each element in the array 'a'
	for i := 0; i < n; i++ {
		if i != 0 {
			fmt.Print(" ") // Print a space before each element except the first one
		}
		fmt.Print(r ^ sc[i]) // Print the result of XOR operation for each element
	}
}

