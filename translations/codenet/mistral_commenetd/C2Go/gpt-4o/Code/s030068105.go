package main

import (
	"fmt"
)

func main() {
	var n int // Declare an integer variable 'n' to store the number of elements

	// Read the number of elements from the user
	fmt.Print("Enter the number of elements: ")
	fmt.Scan(&n)

	// Allocate memory for the array of size 'n'
	data := make([]int, n)

	// Read each element of the array from the user
	for i := 0; i < n; i++ {
		fmt.Printf("Enter element %d: ", i+1)
		fmt.Scan(&data[i])
	}

	max := 0 // Initialize 'max' variable to store the maximum element
	var index int // Initialize 'index' variable to store the index of the maximum element

	// Find the maximum element and its index
	for i := 0; i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i
		}
	}

	a := 0 // Initialize 'a' variable to store the sum of all elements except the maximum

	// Calculate the sum of all elements except the maximum
	for i := 0; i < n; i++ {
		if i != index {
			a += data[i]
		}
	}

	// Check if the sum of all elements except the maximum is greater than the maximum
	if a > max {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
