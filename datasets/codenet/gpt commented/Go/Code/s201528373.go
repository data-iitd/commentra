package main

import (
	"fmt"
)

func main() {
	// Declare variables for the number of elements (n), the threshold value (x), and a slice to hold the integers (l)
	var n int
	var x int
	var l []int
	
	// Read the number of elements (n) from standard input
	fmt.Scan(&n)
	// Read the threshold value (x) from standard input
	fmt.Scan(&x)
	
	// Loop to read n integers from standard input and append them to the slice l
	for i := 0; i < n; i++ {
		var tmpL int
		// Read each integer and store it in tmpL
		fmt.Scan(&tmpL)
		// Append the read integer to the slice l
		l = append(l, tmpL)
	}
	
	// Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
	var tmpSum int
	var rs int
	
	// Loop through the slice l to calculate the cumulative sum and determine the result
	for i, v := range l {
		// Add the current value to the cumulative sum
		tmpSum += v
		
		// Check if the index exceeds the number of elements
		if i >= n {
			rs = n // Set result to n if index exceeds n
			break
		}
		
		// If the cumulative sum is less than or equal to x, update the result
		if tmpSum <= x {
			rs = i + 2 // Update result to the current index + 2
		} else if tmpSum > x {
			break // Exit the loop if the cumulative sum exceeds x
		}
	}
	
	// Print the final result
	fmt.Println(rs)
}
