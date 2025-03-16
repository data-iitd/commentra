package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := new(Scanner)

	// Read the number of integers to be processed
	var n int
	fmt.Scan(&n)

	// Initialize an ArrayList to store the integers
	a := make([]int, 0)

	// If there is only one integer, print it and exit
	if n == 1 {
		var x int
		fmt.Scan(&x)
		fmt.Println(x)
		return
	}

	// Read n integers from input and add them to the ArrayList
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		a = append(a, x)
	}

	// Sort the ArrayList in ascending order
	sort.Ints(a)

	// If the largest number is 0, print 0 and exit
	if a[len(a)-1] == 0 {
		fmt.Println(0)
		return
	}

	// Initialize the answer variable
	var ans int

	// Loop until the ArrayList is reduced to one element
	for {
		// If only one element remains, set it as the answer and break the loop
		if len(a) == 1 {
			ans = a[0]
			break
		}
		// Call the function to process the ArrayList and update it
		a = func(a)
	}

	// Print the final answer
	fmt.Println(ans)
}

// Function to process the ArrayList and return a modified version
func func(a []int) []int {
	// Create a copy of the input ArrayList
	b := make([]int, len(a))
	copy(b, a)

	// Initialize a variable to store the minimum value
	var min int

	// Iterate through the ArrayList
	for i := 0; i < len(b); i++ {
		// If the current element is 0, remove it from the list
		if b[i] == 0 {
			b = append(b[:i], b[i+1:]...)
			i--
		} else {
			// If min is not zero, update the current element
			if min != 0 {
				b[i] = b[i] % min
				// If the updated element is 1, print 1 and exit
				if b[i] == 1 {
					fmt.Println(1)
					return nil
				}
			} else {
				// Set min to the current element if min is still zero
				min = b[i]
			}
		}
	}

	// Sort the modified ArrayList before returning
	sort.Ints(b)
	return b
}

// END-OF-CODE
