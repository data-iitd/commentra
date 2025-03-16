package main

import (
	"fmt"
)

func main() {
	var t, m int
	fmt.Scan(&t) // Step 1: Read the number of test cases (t) from the input.
	fmt.Scan(&m) // Step 1: Read the size of memory (m) from the input.
	memory := make([]int, m) // Step 2: Initialize a slice to keep track of memory allocation.
	allocIdx := 0 // Initialize the allocation index.

	for j := 0; j < t; j++ { // Step 3: Loop through each test case.
		var command string
		fmt.Scan(&command) // Read the command and perform the corresponding action.

		switch command {
		case "alloc":
			var n int
			fmt.Scan(&n) // Step 5: Read the size of memory block to allocate.
			len := 0 // Initialize the length counter.
			canAlloc := false // Flag to check if allocation is possible.
			startIdx := 0 // To store the starting index of the block.

			for i := 0; i < m; i++ { // Iterate through memory to find a suitable block.
				if memory[i] == 0 {
					len++ // Increment length if current block is free.
				} else {
					len = 0 // Reset length if current block is allocated.
				}

				if len == n { // Check if a block of size n is found.
					canAlloc = true // Set flag to true.
					startIdx = i - n + 1 // Set the starting index of the block.
					break // Exit the loop as block is found.
				}
			}

			if canAlloc { // Step 5: If allocation is possible.
				allocIdx++ // Increment the allocation index.
				for i := startIdx; i < startIdx+n; i++ {
					memory[i] = allocIdx // Allocate the block.
				}
				fmt.Println(allocIdx) // Print the allocation index.
			} else {
				fmt.Println("NULL") // Step 5: If allocation is not possible, print "NULL".
			}
		case "erase":
			var x int
			fmt.Scan(&x) // Step 6: Read the index of the block to erase.
			if x <= 0 { // Check if the index is valid.
				fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Print error message if index is invalid.
				break
			}
			hasErased := false // Flag to check if any block is erased.

			for i := 0; i < m; i++ { // Iterate through memory to find the block to erase.
				if memory[i] == x { // Check if the block matches the index.
					memory[i] = 0 // Erase the block.
					hasErased = true // Set flag to true.
				}
			}

			if !hasErased {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Step 6: If no block is erased, print error message.
			}
		case "defragment":
			d := 0 // Initialize the defragmentation index.
			for i := 0; i < m; i++ { // Iterate through memory to defragment.
				if memory[i] == 0 {
					d++ // Increment defragmentation index if current block is free.
				} else {
					memory[i-d] = memory[i] // Shift the block to the left.
				}
			}
			for i := m - d; i < m; i++ {
				memory[i] = 0 // Fill the remaining space with zeros.
			}
		default:
			fmt.Println("h") // Step 8: If the command is unknown, print "h".
		}
	}
}
