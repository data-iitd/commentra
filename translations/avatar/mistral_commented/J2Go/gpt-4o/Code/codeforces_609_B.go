package main

import (
	"fmt"
)

func main() {
	// Reading the first integer input n from the user
	var n int
	fmt.Scan(&n)

	// Reading the second integer input m from the user
	var m int
	fmt.Scan(&m)

	// Creating a slice arr of size n to store the input integers
	arr := make([]int, n)

	// Creating a slice gen of size 11 to store the count of each integer occurrence
	gen := make([]int, 11)

	// Reading the input integers and storing them in the arr slice
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		// Incrementing the count of arr[i] in the gen slice
		gen[arr[i]]++
	}

	// Calculating the answer
	var ans int64 = 0
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			// Skipping the case when i and k are equal to avoid double counting
			if i != k {
				// Multiplying the count of i and k and adding it to the answer
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}

	// Printing the answer divided by 2
	fmt.Println(ans / 2)
}

// <END-OF-CODE>
