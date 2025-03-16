
package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var n int
	var x int
	var l []int

	// Read input values for n and x
	fmt.Println("Enter the number of arrays:")
	fmt.Scan(&n)
	fmt.Println("Enter the sum of elements in an array that should not exceed:")
	fmt.Scan(&x)

	// Initialize an empty slice l to store the arrays
	l = make([]int, 0)

	// Read input values for each array and append them to the slice l
	for i := 0; i < n; i++ {
		// Read the length of the current array
		var tmpL int
		fmt.Println("Enter the length of array number", i+1, ":")
		fmt.Scan(&tmpL)

		// Append the length of the current array to the slice l
		l = append(l, tmpL)
	}

	// Initialize variables for sum and result slice index
	var tmpSum int
	var rs int

	// Iterate through the slice l to find the index of the last array whose sum is less than or equal to x
	for i, v := range l {
		// Initialize a variable tmpSum to store the sum of elements in the current array
		tmpSum = 0

		// Calculate the sum of elements in the current array
		for j := 0; j < v; j++ {
			// Read the value of the current element and add it to the sum
			var tmp int
			fmt.Println("Enter the value of element number", j+1, "in array number", i+1, ":")
			fmt.Scan(&tmp)
			tmpSum += tmp
		}

		// Check if the sum of elements in the current array is greater than x
		if tmpSum > x {
			// If yes, break the loop as we don't need to check further arrays
			break
		}

		// If the sum of elements in the current array is less than or equal to x, update the result slice index
		rs = i + 1
	}

	// Print the result slice index
	fmt.Println("The last array index whose sum of elements is less than or equal to", x, "is:", rs)
}

