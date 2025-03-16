package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M) // Reading the first two integers from the input

	a := make([]int, N) // Creating a slice of size N to store integers

	// Reading the queries and updating the slice accordingly
	for i := 0; i < M; i++ {
		var k int
		fmt.Scan(&k) // Reading the number of elements to be updated

		for j := 0; j < k; j++ { // Iterating through the elements to be updated
			var s int
			fmt.Scan(&s) // Reading the index of the element to be updated
			s--           // Decreasing the index by 1 as the slice index starts from 0

			// Updating the value of the element at the given index
			a[s] |= (1 << i)
		}
	}

	p := 0 // Initializing a variable to store the XOR of all given integers

	// Reading the integers and computing their XOR
	for i := 0; i < M; i++ {
		var x int
		fmt.Scan(&x) // Reading an integer from the input
		p |= (x << i) // Computing the XOR of the current integer with the previous result
	}

	ans := 0 // Initializing a variable to store the count of valid answers

	// Iterating through all possible combinations of the slice elements
	for s := 0; s < (1 << N); s++ { // 1 << N represents 2^N
		t := 0 // Initializing a variable to store the XOR of the current combination with the slice elements

		// Computing the XOR of the current combination with the slice elements
		for i := 0; i < N; i++ {
			if (s>>i)&1 == 1 { // Checking if the i-th bit of the current combination is set
				t ^= a[i] // Updating the XOR of the current combination
			}
		}

		// Checking if the XOR of the current combination and the slice elements is equal to the given integers
		if p == t {
			ans++ // Incrementing the count of valid answers
		}
	}

	fmt.Println(ans) // Printing the count of valid answers
}
