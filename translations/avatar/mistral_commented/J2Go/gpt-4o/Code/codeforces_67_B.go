package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n) // Reading the number of elements in the array 'bb'
	fmt.Scan(&k) // Reading the value of 'k'

	bb := make([]int, n) // Creating an integer slice 'bb' of size 'n'
	for i := 0; i < n; i++ {
		fmt.Scan(&bb[i]) // Reading each element of the array 'bb'
	}

	aa := make([]int, n) // Creating an integer slice 'aa' of size 'n'
	m := 0               // Initializing an integer variable 'm' to keep track of the index of the last element added to 'aa'

	for a := n - 1; a >= 0; a-- { // Iterating through the array 'bb' from the last index to the first index
		j := 0
		for bb[a] > 0 { // While there are still elements in 'bb' at index 'a' to be processed
			if j < m && aa[j] >= a+k { // Checking if the current element in 'aa' is greater than or equal to the index 'a' plus 'k'
				bb[a]-- // If true, decrement the number of elements in 'bb' at index 'a'
			}
			j++ // Incrementing j
		}

		// Shifting elements in 'aa' to make space for the new element
		for j_ := m; j_ > j; j_-- {
			aa[j_] = aa[j_-1] // Swapping the elements at indices 'j_' and 'j_-1'
		}

		aa[j] = a // Adding the current index 'a' to the array 'aa' at index 'j'
		m++       // Incrementing m to reflect the new size of 'aa'
	}

	for i := 0; i < n; i++ { // Iterating through the array 'aa' and printing each element
		fmt.Print(aa[i] + 1, " ") // Printing the index + 1 to match the output format
	}

	fmt.Println() // Printing a newline character to the console
}

// <END-OF-CODE>
