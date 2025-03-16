package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a Scanner object to read input from the console
	in := bufio.NewScanner(os.Stdin)

	// Loop to process multiple test cases until there is no more input
	for in.Scan() {
		// Read the number of elements
		n, _ := strconv.Atoi(in.Text())

		// Initialize two arrays to store the input values and a status flag
		a := make([]int, n) // Array to store the input values
		b := make([]int, n) // Array to track which elements have been processed

		// Initialize a counter for the number of steps taken
		s := -1 // Start with -1 to account for the first increment

		// Read the input values into array 'a' and initialize array 'b' to 0
		for i := 0; i < n; i++ {
			in.Scan()
			a[i], _ = strconv.Atoi(in.Text()) // Read each integer into array 'a'
			b[i] = 0                          // Initialize the status array 'b' to 0 (not processed)
		}

		// Initialize variables for processing
		tem := 1 // Variable to alternate between forward and backward processing
		q := 0   // Counter for the number of processed elements

		// Loop until all elements have been processed
		for q != n {
			s++ // Increment the step counter

			// Check the direction of processing based on 'tem'
			if tem == 1 {
				// Process elements from the start of the array
				for i := 0; i < n; i++ {
					// If the current element can be processed
					if a[i] <= q && b[i] == 0 {
						b[i] = 1 // Mark the element as processed
						q++      // Increment the processed counter
					}
				}
				tem = 0 // Switch to backward processing for the next iteration
			} else {
				// Process elements from the end of the array
				for i := n - 1; i >= 0; i-- {
					// If the current element can be processed
					if a[i] <= q && b[i] == 0 {
						b[i] = 1 // Mark the element as processed
						q++      // Increment the processed counter
					}
				}
				tem = 1 // Switch to forward processing for the next iteration
			}
		}

		// Output the total number of steps taken to process all elements
		fmt.Println(s)
	}
}

