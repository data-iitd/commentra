package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Loop until there is no more input
	for {
		// Read the number of elements
		fmt.Print("Enter the number of elements: ")
		input, _ := reader.ReadString('\n')
		n, _ := strconv.Atoi(strings.TrimSpace(input))

		// Initialize two arrays to store the input values and a status flag
		a := make([]int, n) // Array to store the input values
		b := make([]int, n) // Array to track which elements have been processed

		// Initialize a counter for the number of steps taken
		s := -1 // Start with -1 to account for the first increment

		// Read the input values into array 'a' and initialize array 'b' to 0
		for i := 0; i < n; i++ {
			fmt.Printf("Enter element %d: ", i+1)
			input, _ := reader.ReadString('\n')
			a[i], _ = strconv.Atoi(strings.TrimSpace(input))
			b[i] = 0 // Initialize the status array 'b' to 0 (not processed)
		}

		// Initialize variables for processing
		tem := 1 // Variable to alternate between forward and backward processing
		q := 0   // Counter for the number of processed elements

		// Loop until all elements have been processed
		for q!= n {
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
		fmt.Printf("Total number of steps taken: %d\n", s)

		// Check if there is more input
		fmt.Print("Do you have more input? (y/n): ")
		input, _ = reader.ReadString('\n')
		if strings.TrimSpace(input)!= "y" {
			break
		}
	}
}

