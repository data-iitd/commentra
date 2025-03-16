package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a variable to read input from the user
	var n int
	fmt.Scan(&n)

	// If there is only one integer, read it and print it
	if n == 1 {
		var singleInt int
		fmt.Scan(&singleInt)
		fmt.Println(singleInt)
		return
	}

	// Initialize a slice to store the integers
	a := make([]int, n)

	// Read n integers from input and add them to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the slice in ascending order
	sort.Ints(a)

	// If the largest number is 0, print 0 and exit
	if a[n-1] == 0 {
		fmt.Println(0)
		return
	}

	// Initialize the answer variable
	var ans int

	// Loop until the slice is reduced to one element
	for {
		// If only one element remains, set it as the answer and break the loop
		if len(a) == 1 {
			ans = a[0]
			break
		}
		// Call the function to process the slice and update it
		a = func(a []int) []int {
			// Initialize a variable to store the minimum value
			min := 0
			// Create a new slice to hold the modified values
			newSlice := []int{}

			// Iterate through the slice
			for _, value := range a {
				// If the current element is 0, skip it
				if value == 0 {
					continue
				}
				// If min is not zero, update the current element
				if min != 0 {
					value = value % min
					// If the updated element is 1, print 1 and exit
					if value == 1 {
						fmt.Println(1)
						return nil
					}
				} else {
					// Set min to the current element if min is still zero
					min = value
				}
				// Append the modified value to the new slice
				newSlice = append(newSlice, value)
			}

			// Sort the modified slice before returning
			sort.Ints(newSlice)
			return newSlice
		}(a)
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
