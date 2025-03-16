package main

import (
	"fmt"
	"unsafe"
)

func main() {
	var n int
	var data []int

	// Read the number of elements from the user
	fmt.Print("Enter the number of elements: ")
	fmt.Scan(&n)

	// Allocate memory for the array of size 'n' using malloc()
	data = make([]int, n)

	// Read each element of the array from the user
	for i := 0; i < n; i++ {
		fmt.Printf("Enter element %d: ", i+1)
		fmt.Scan(&data[i])
	}

	max := 0
	var index int

	// Find the maximum element and its index
	for i := 0; i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i
		}
	}

	a := 0

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

	// Free the allocated memory
	data = nil

	// Return 0 to indicate successful execution of the program
}

