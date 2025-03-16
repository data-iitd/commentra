package main

import (
	"fmt"
)

func main() {
	// Declare arrays and variables
	const maxN = 200000
	var a [maxN]int
	var tmpa [maxN]int
	var light [maxN + 10]int

	// Read the number of elements (n) and the number of iterations (k)
	var n, k int
	fmt.Scan(&n, &k)

	// Input the initial values into the array 'a'
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Calculate the influence range for each element in 'a'
	for i := 0; i < n; i++ {
		r := i - a[i] // Calculate the left boundary
		l := i + a[i] // Calculate the right boundary
		if r < 0 {
			r = 0
		}
		light[r]++ // Increment the start of the influence range
		if l+1 > n {
			l = n + 1
		}
		light[l+1]-- // Decrement the end of the influence range
	}

	// Perform k iterations to update the array 'a'
	for i := 0; i < k; i++ {
		sum := 0

		// Update 'a' based on the current influence ranges
		for j := 0; j < n; j++ {
			tmpa[j] = a[j] // Store the current state of 'a' in 'tmpa'
			sum += light[j] // Accumulate the influence
			a[j] = sum // Update 'a' with the accumulated influence
		}

		// Update the influence ranges based on the new values in 'a'
		for j := 0; j < n; j++ {
			r := j - tmpa[j] // Calculate the left boundary for the previous state
			l := j + tmpa[j] // Calculate the right boundary for the previous state
			if r < 0 {
				r = 0
			}
			light[r]-- // Decrement the start of the previous influence range
			if l+1 > n {
				l = n + 1
			}
			light[l+1]++ // Increment the end of the previous influence range

			r = j - a[j] // Calculate the new left boundary
			l = j + a[j] // Calculate the new right boundary
			if r < 0 {
				r = 0
			}
			light[r]++ // Increment the start of the new influence range
			if l+1 > n {
				l = n + 1
			}
			light[l+1]-- // Decrement the end of the new influence range
		}

		// Check if all elements in 'a' are the same and equal to n
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j] != a[j+1] {
				isSame = false // Set flag to false if any elements differ
				break
			}
		}
		// If all elements are the same and equal to n, exit the loop
		if isSame && a[0] == n {
			break
		}
	}

	// Output the final state of the array 'a'
	for j := 0; j < n; j++ {
		fmt.Print(a[j]) // Print each element of 'a'
		if j == n-1 {
			fmt.Println() // Print a newline after the last element
		} else {
			fmt.Print(" ") // Print space between elements
		}
	}
}

// <END-OF-CODE>
