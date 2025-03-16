package main // Defining the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() { // Starting the main function
	var t, m int
	fmt.Scan(&t) // Reading the number of test cases
	fmt.Scan(&m) // Reading the size of the memory
	memory := make([]int, m) // Initializing a slice of integers of size m to represent the memory
	allocIdx := 0 // Initializing a counter for allocated memory blocks

	for j := 0; j < t; j++ { // Loop through each test case
		var command string
		fmt.Scan(&command) // Reading the command
		switch command { // Switch based on the command
		case "alloc": // Allocate command
			var n int
			fmt.Scan(&n) // Reading the size of the block to be allocated
			len := 0 // Initializing a counter for free memory blocks
			canAlloc := false // Flag to check if allocation is possible
			startIdx := -1 // Variable to store the start index of the block

			for i := 0; i < m; i++ { // Loop through the memory slice
				if memory[i] == 0 { // If the current block is free
					len++ // Increment the counter
					if len == n { // If the free memory blocks form a block of size n
						canAlloc = true // Set the flag
						startIdx = i - n + 1 // Calculate the start index of the block
						break // Exit the loop
					}
				} else { // If the current block is allocated
					len = 0 // Reset the counter
				}
			}

			if canAlloc { // If allocation is possible
				allocIdx++ // Increment the counter for allocated blocks
				for i := startIdx; i < startIdx+n; i++ { // Allocate the block in the memory
					memory[i] = allocIdx
				}
				fmt.Println(allocIdx) // Print the allocated block number
			} else { // If allocation is not possible
				fmt.Println("NULL") // Print NULL
			}
		case "erase": // Erase command
			var x int
			fmt.Scan(&x) // Reading the block number to be erased
			if x <= 0 { // If the block number is invalid
				fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Print an error message
				break
			}
			hasErased := false // Flag to check if the block has been erased
			for i := 0; i < m; i++ { // Loop through the memory slice
				if memory[i] == x { // If the current block matches the given block number
					memory[i] = 0 // Erase the block
					hasErased = true // Set the flag
				}
			}
			if !hasErased { // If the block was not found
				fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Print an error message
			}
		case "defragment": // Defragment command
			d := 0 // Initializing a counter for free memory blocks
			for i := 0; i < m; i++ { // Loop through the memory slice
				if memory[i] == 0 { // If the current block is free
					d++ // Increment the counter
				}
			}
			newSize := m - d // Calculate the new size of the memory slice
			newMemory := make([]int, newSize) // Create a new memory slice of the new size
			k := 0 // Initialize a counter for copying elements to the new slice
			for i := 0; i < m; i++ { // Loop through the old memory slice
				if memory[i] != 0 { // If the current block is allocated
					newMemory[k] = memory[i] // Copy the block to the new slice
					k++ // Increment the counter
				}
			}
			memory = newMemory // Update the memory slice with the new one
		default: // Invalid command
			fmt.Println("h") // Print an error message
		}
	}
} // Closing the main function
// <END-OF-CODE>
