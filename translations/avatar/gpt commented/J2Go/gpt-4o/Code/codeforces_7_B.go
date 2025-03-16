package main

import (
	"fmt"
)

func main() {
	// Create a scanner to read input from the console
	var t, m int
	fmt.Scan(&t, &m)

	// Initialize the memory slice to keep track of allocated memory
	memory := make([]int, m)

	// Initialize the allocation index to track the allocation IDs
	allocIdx := 0

	// Process each operation based on the number of operations (t)
	for j := 0; j < t; j++ {
		var command string
		fmt.Scan(&command)

		switch command {
		case "alloc":
			// Read the size of memory to allocate
			var n int
			fmt.Scan(&n)
			len := 0
			canAlloc := false
			startIdx := 0

			// Check for a contiguous block of free memory of size n
			for i := 0; i < m; i++ {
				if memory[i] == 0 {
					len++ // Increase length if the current memory is free
				} else {
					len = 0 // Reset length if the current memory is allocated
				}

				// If a sufficient block is found, mark it as allocatable
				if len == n {
					canAlloc = true
					startIdx = i - n + 1 // Calculate the starting index for allocation
					break
				}
			}

			// If allocation is possible, allocate memory and print the allocation ID
			if canAlloc {
				allocIdx++
				for i := startIdx; i < startIdx+n; i++ {
					memory[i] = allocIdx // Mark the allocated memory with the allocation ID
				}
				fmt.Println(allocIdx) // Output the allocation ID
			} else {
				fmt.Println("NULL") // Output NULL if allocation failed
			}

		case "erase":
			// Read the allocation ID to erase
			var x int
			fmt.Scan(&x)

			// Check for illegal erase argument
			if x <= 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				break
			}

			hasErased := false

			// Erase the memory corresponding to the given allocation ID
			for i := 0; i < m; i++ {
				if memory[i] == x {
					memory[i] = 0 // Free the allocated memory
					hasErased = true
				}
			}

			// If no memory was erased, print an error message
			if !hasErased {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			}

		case "defragment":
			// Initialize a counter for the number of free blocks
			d := 0

			// Move allocated memory to the front of the array
			for i := 0; i < m; i++ {
				if memory[i] == 0 {
					d++ // Count free blocks
				} else {
					memory[i-d] = memory[i] // Shift allocated memory left
				}
			}

			// Clear the remaining memory at the end of the array
			for i := m - d; i < m; i++ {
				memory[i] = 0
			}

		default:
			// Handle any unrecognized command
			fmt.Println("h")
		}
	}
}

// <END-OF-CODE>
