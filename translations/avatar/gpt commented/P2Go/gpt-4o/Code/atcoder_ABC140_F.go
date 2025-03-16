package main

import (
	"fmt"
	"sort"
)

// Function to read a single integer from standard input
func I() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a list of integers from standard input
func LI() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

func main() {
	// Read the number of elements
	N := I()

	// Read the list of integers
	S := LI()

	// Sort the list in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(S)))

	// Initialize a flag slice to track which elements have been used
	flag := make([]bool, len(S))
	for i := range flag {
		flag[i] = true
	}

	// Initialize the current list with the largest element
	cur := []int{S[0]}
	flag[0] = false // Mark the first element as used

	// Iterate N times to build the current list
	for i := 0; i < N; i++ {
		j := 0 // Index for the current list
		jM := len(cur) // Length of the current list

		// Try to find the next largest unused element
		for k := 0; k < len(S); k++ {
			// Check if the current element is unused and smaller than the last added element
			if flag[k] && S[k] < cur[j] {
				cur = append(cur, S[k]) // Add the element to the current list
				j++ // Move to the next index in the current list
				flag[k] = false // Mark this element as used

				// If we have added enough elements, break out of the loop
				if j == jM {
					break
				}
			}
		}

		// If we couldn't find a suitable element, return "No"
		if j == jM {
			fmt.Println("No")
			return
		}

		// Sort the current list in descending order for the next iteration
		sort.Sort(sort.Reverse(sort.IntSlice(cur)))
	}

	// If we successfully built the list, return "Yes"
	fmt.Println("Yes")
}

// <END-OF-CODE>
