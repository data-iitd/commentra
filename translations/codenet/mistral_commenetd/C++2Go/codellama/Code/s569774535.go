
package main

import (
	"fmt"
)

func main() {
	var n int // Initialize an integer variable 'n' to store the number of elements in the slice 'a'

	// Read the number of elements from the standard input
	fmt.Scan(&n)

	// Allocate memory for the slice 'a' of size 'n'
	a := make([]int, n)

	// Read 'n' integers from the standard input and store them in the slice 'a'
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read an integer from the standard input and store it in the 'i'-th position of the slice 'a'
	}

	ans := 0 // Initialize an integer variable 'ans' to store the answer
	ok := true // Initialize a boolean variable 'ok' to keep track of the loop condition

	// Main logic of the program starts here
	for ok {
		for i := 0; i < n; i++ { // Iterate through all the elements in the slice 'a'
			if a[i]%2 == 1 { // Check if the 'i'-th element of the slice 'a' is odd
				fmt.Println(ans) // If yes, print the answer and exit the program
				return
			} else { // If the 'i'-th element of the slice 'a' is even, divide it by 2
				a[i] /= 2
			}
		}
		ans++ // Increment the answer by 1 for each iteration of the outer loop
		ok = false // Set the loop condition to false to exit the loop if all elements in the slice 'a' become even
	}

	// Print the final answer if all elements in the slice 'a' become even
	fmt.Println(ans)
}

