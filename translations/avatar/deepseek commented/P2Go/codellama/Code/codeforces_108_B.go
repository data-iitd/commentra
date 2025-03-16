
package main

import "fmt"

func s() string {
	// Take input from the user
	fmt.Scanln()
	// Read the input, split it into a list of integers, and store it in 'a'
	var a []int
	fmt.Scanln(&a)
	// Sort the list 'a'
	sort.Ints(a)
	// Iterate through the sorted list starting from the second element
	for i := 1; i < len(a); i++ {
		// Check if the current element is not equal to the previous element
		// and if the current element is less than twice the previous element
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			// If the condition is met, return 'YES'
			return "YES"
		}
	}
	// If the loop completes without finding a match, return 'NO'
	return "NO"
}

// Print the result returned by the function 's()'
fmt.Println(s())

