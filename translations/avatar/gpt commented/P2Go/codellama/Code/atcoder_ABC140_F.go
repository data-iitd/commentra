
package main

import (
	"fmt"
	"sort"
)

// Function to read a single integer from standard input
func I() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read a list of integers from standard input
func LI() []int {
	var n int
	fmt.Scan(&n)
	s := make([]int, n)
	for i := range s {
		fmt.Scan(&s[i])
	}
	return s
}

func main() {
	// Read the number of elements
	N := I()

	// Read the list of integers, sort it in descending order
	S := LI()
	sort.Sort(sort.Reverse(sort.IntSlice(S)))

	// Initialize a flag list to track which elements have been used
	flag := make([]bool, len(S))

	// Initialize the current list with the largest element
	cur := []int{S[0]}

	// Mark the first element as used
	flag[0] = false

	// Iterate N times to build the current list
	for i := 0; i < N; i++ {
		j := 0  // Index for the current list
		jM := len(cur)  // Length of the current list

		// Try to find the next largest unused element
		for k := range S {
			// Check if the current element is unused and smaller than the last added element
			if flag[k] && S[k] < cur[j] {
				cur = append(cur, S[k])  // Add the element to the current list
				j++                      // Move to the next index in the current list
				flag[k] = false          // Mark this element as used

				// If we have added enough elements, break out of the loop
				if j == jM {
					break
				}
			}
		}
		if j != jM {
			// If we couldn't find a suitable element, return "No"
			fmt.Println("No")
			return
		}

		// Sort the current list in descending order for the next iteration
		sort.Sort(sort.Reverse(sort.IntSlice(cur)))
	}

	// If we successfully built the list, return "Yes"
	fmt.Println("Yes")
}

// 