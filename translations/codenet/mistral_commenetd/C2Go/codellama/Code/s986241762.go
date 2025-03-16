
package main

import "fmt"

func main() {
	var n int // Declare and initialize an integer variable 'n'
	var sum int64 = 0 // Declare and initialize a long integer variable 'sum' with zero value

	// Read the number of elements in the array from the user
	fmt.Print("Enter the number of elements in the array: ")
	fmt.Scan(&n)

	// Declare an integer array 'a' of size 'n'
	a := make([]int, n)

	// Read the elements of the array from the user
	fmt.Println("Enter", n, "integers:")
	for i := 0; i < n; i++ {
		fmt.Print("Enter element number", i+1, ": ")
		fmt.Scan(&a[i]) // Read an integer value and store it in the array 'a'
	}

	// Calculate the sum of the differences between adjacent elements in the array
	for i := 1; i < n; i++ {
		// Check if the previous element is greater than the current element
		if a[i-1] > a[i] {
			// If true, add the difference to the sum
			sum += int64(a[i-1] - a[i])
			// Swap the elements to maintain the array in non-decreasing order
			a[i] = a[i-1]
		}
	}

	// Print the sum of the differences
	fmt.Println("The sum of the differences is:", sum)
}

