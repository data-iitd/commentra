package main

import (
	"fmt"
)

func main() {
	// Declare arrays and typedef for long long
	var a, tmpa, light [200000]int
	type ll int

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
		light[(r < 0 ? 0 : r)]++ // Increment the start of the influence range
		light[(l + 1 > n ? n + 1 : l + 1)]-- // Decrement the end of the influence range
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
			light[(r < 0 ? 0 : r)]-- // Decrement the start of the previous influence range
			light[(l + 1 > n ? n + 1 : l + 1)]++ // Increment the end of the previous influence range

			r = j - a[j] // Calculate the new left boundary
			l = j + a[j] // Calculate the new right boundary
			light[(r < 0 ? 0 : r)]++ // Increment the start of the new influence range
			light[(l + 1 > n ? n + 1 : l + 1)]-- // Decrement the end of the new influence range
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
		fmt.Printf("%d", a[j]) // Print each element of 'a'
		fmt.Print(j == n-1 ? "\n" : " ") // Print a newline after the last element
	}
}

