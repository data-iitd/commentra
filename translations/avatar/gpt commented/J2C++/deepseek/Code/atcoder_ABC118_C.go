package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the user
	var n int
	fmt.Scan(&n)
	
	// Initialize a slice to store the integers
	a := make([]int, n)
	
	// Read n integers from input and add them to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	
	// Sort the slice in ascending order
	sort.Ints(a)
	
	// If the largest number is 0, print 0 and exit
	if a[len(a)-1] == 0 {
		fmt.Println(0)
		return
	}
	
	// Loop until the slice is reduced to one element
	for {
		// If only one element remains, set it as the answer and break the loop
		if len(a) == 1 {
			fmt.Println(a[0])
			break
		}
		// Call the function to process the slice and update it
		a = func(A []int) []int {
			// Create a copy of the input slice
			a := append([]int{}, A...)
			
			// Initialize a variable to store the minimum value
			min := 0
			
			// Iterate through the slice
			for i := 0; i < len(a); i++ {
				// If the current element is 0, remove it from the list
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i-- // Adjust index after removal
				} else {
					// If min is not zero, update the current element
					if min != 0 {
						a[i] = a[i] % min
						// If the updated element is 1, print 1 and exit
						if a[i] == 1 {
							fmt.Println(1)
							return nil
						}
					} else {
						// Set min to the current element if min is still zero
						min = a[i]
					}
				}
			}
			
			// Sort the modified slice before returning
			sort.Ints(a)
			return a
		}(a)
	}
}
