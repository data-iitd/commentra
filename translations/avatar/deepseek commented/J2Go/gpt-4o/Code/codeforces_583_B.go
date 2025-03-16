package main

import (
	"fmt"
)

func main() {
	var n int
	for {
		_, err := fmt.Scan(&n)
		if err != nil {
			break // Exit the loop if there's no more input
		}

		a := make([]int, n) // Initialize array a
		b := make([]int, n) // Initialize array b
		s := -1             // Initialize the counter s to -1

		// Read n integers into array a
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
			b[i] = 0 // Initialize array b to all zeros
		}

		tem := 1 // Initialize tem to 1
		q := 0   // Initialize q to 0

		// Enter a loop that continues until q equals n
		for q != n {
			s++ // Increment the counter s

			// If tem is 1, process elements from the start of a to the end
			if tem == 1 {
				for i := 0; i < n; i++ {
					if a[i] <= q && b[i] == 0 {
						b[i] = 1 // Mark the element as processed
						q++      // Increment the processed element counter
					}
				}
				tem = 0 // Toggle tem to 0
			} else { // If tem is 0, process elements from the end of a to the start
				for i := n - 1; i >= 0; i-- {
					if a[i] <= q && b[i] == 0 {
						b[i] = 1 // Mark the element as processed
						q++      // Increment the processed element counter
					}
				}
				tem = 1 // Toggle tem to 1
			}
		}

		// Print the value of s
		fmt.Println(s)
	}
}

// <END-OF-CODE>
