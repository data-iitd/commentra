package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the integer n
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read n integers into the slice a
	}

	ans := 0 // Initialize ans to 0
	ok := true // Initialize ok to true
	for ok { // Start the main loop
		for i := 0; i < n; i++ { // Iterate over each element in the slice a
			if a[i]%2 == 1 { // Check if the element is odd
				fmt.Println(ans) // Print the current value of ans and exit
				return
			} else { // If the element is even
				a[i] /= 2 // Divide the element by 2
			}
		}
		ans++ // Increment ans after processing all elements
	}

	fmt.Println(ans) // Print the final value of ans
}

// <END-OF-CODE>
