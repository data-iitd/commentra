package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n) // Reading the first integer input 'n' from the user
	fmt.Scan(&k) // Reading the second integer input 'k' from the user

	arr := make([]int, n) // Creating an integer slice 'arr' of size 'n'

	// Initializing the array 'arr' with user input
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Reading an integer value from the user and storing it in the array at index 'i'
	}

	var res string // Creating a string to store the output
	o, e := 0, 0   // Initializing two integer variables 'o' and 'e' to 0

	// Counting the number of 1's and 0's in the array 'arr'
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++ // Incrementing the variable 'o' when the current element in the array is 1
		} else {
			e++ // Incrementing the variable 'e' when the current element in the array is 0
		}
	}

	// Processing the user queries
	for i := 0; i < k; i++ {
		var l, r int
		fmt.Scan(&l) // Reading the left index 'l' of the query from the user
		fmt.Scan(&r) // Reading the right index 'r' of the query from the user

		if (r-l+1)%2 == 1 { // Checking if the length of the query is odd
			res += "0\n" // If the length is odd, appending '0' to the output string followed by a newline character
		} else { // If the length is even
			if (r-l+1)/2 <= o { // Checking if half of the length is less than or equal to the number of 1's in the array
				res += "1\n" // If it is, appending '1' to the output string followed by a newline character
			} else { // Otherwise
				res += "0\n" // Appending '0' to the output string followed by a newline character
			}
		}
	}

	fmt.Print(res) // Printing the final output string
}
