

package main

import "fmt"

func main() {
	var v [10]int
	var sum int = 0
	var i int

	// Read 10 integers from the user and store them in the array 'v'.
	for i = 0; i < 10; i++ {
		fmt.Printf("Enter the value for index %d: ", i)
		fmt.Scan(&v[i])
		// Read an integer value from the user and store it in the current index of the array 'v'.
	}

	// Calculate the sum of all elements in the array 'v'.
	for i = 0; i < 10; i++ {
		sum += v[i]
		// Add the value of the current element in the array 'v' to the variable'sum'.
	}

	// Print the sum of all elements in the array 'v'.
	fmt.Printf("%d\n", sum)
	// Display the sum of all elements in the array 'v'.

	// 