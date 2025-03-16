package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the standard input
	arr := make([]int, n) // Creating an integer slice of size n
	sum := 0 // Initializing the sum variable to 0

	for i := 0; i < n; i++ { // Starting a for loop to read and store the elements in the array
		fmt.Scan(&arr[i]) // Reading an integer value from the standard input and storing it in the current index of the array
		sum += arr[i] // Adding the current element to the sum variable
	}

	c := 0 // Initializing the counter variable to 0
	var indices []string // Creating a slice to store the indices of the elements that satisfy the condition

	for i := 0; i < n; i++ { // Starting a for loop to check if an element satisfies the condition
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] { // Checking if the current element satisfies the condition
			c++ // Incrementing the counter variable if the condition is true
			indices = append(indices, fmt.Sprintf("%d", i+1)) // Appending the index of the current element to the slice
		}
	}

	fmt.Println(c) // Printing the number of elements that satisfy the condition
	fmt.Println(strings.Join(indices, " ")) // Printing the indices of the elements that satisfy the condition separated by a space
}
