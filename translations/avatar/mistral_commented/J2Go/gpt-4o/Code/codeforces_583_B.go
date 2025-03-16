package main

import (
	"fmt"
)

func main() {
	var n int
	for {
		_, err := fmt.Scan(&n) // Reading the number of elements in the arrays
		if err != nil {
			break // Exit the loop if there is no more input
		}
		a := make([]int, n) // Creating an integer slice 'a' of size 'n'
		b := make([]int, n) // Creating an integer slice 'b' of size 'n'
		s := -1             // Initializing the variable 's' to -1

		for i := 0; i < n; i++ { // Loop to read and initialize the arrays 'a' and 'b'
			fmt.Scan(&a[i]) // Reading an integer value and storing it in the 'i'th position of slice 'a'
			b[i] = 0        // Initializing all elements of slice 'b' to zero
		}

		tem := 1 // Initializing the variable 'tem' to 1
		q := 0   // Initializing the variable 'q' to 0

		for q != n { // Main loop to find the sequence length
			s++ // Incrementing the variable 's'
			if tem == 1 { // If 'tem' is 1, perform the first half of the loop
				for i := 0; i < n; i++ {
					if a[i] <= q && b[i] == 0 { // Check if the current element in slice 'a' is less than or equal to 'q' and its corresponding element in slice 'b' is 0
						b[i] = 1 // If so, set the corresponding element in slice 'b' to 1 and increment 'q'
						q++      // Increment 'q' when an element is found
					}
				}
				tem = 0 // Switching the value of 'tem' to 0
			} else { // If 'tem' is 0, perform the second half of the loop
				for i := n - 1; i >= 0; i-- {
					if a[i] <= q && b[i] == 0 { // Check if the current element in slice 'a' is less than or equal to 'q' and its corresponding element in slice 'b' is 0
						b[i] = 1 // If so, set the corresponding element in slice 'b' to 1 and increment 'q'
						q++      // Increment 'q' when an element is found
					}
				}
				tem = 1 // Switching the value of 'tem' to 1
			}
		}
		fmt.Println(s) // Printing the length of the sequence found
	}
}

// <END-OF-CODE>
