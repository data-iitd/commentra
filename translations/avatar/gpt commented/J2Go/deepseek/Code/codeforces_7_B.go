package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of operations (t) and the size of memory (m)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &t, &m)
	
	// Initialize the memory array to keep track of allocated memory
	memory := make([]int, m)
	
	// Initialize the allocation index to track the allocation IDs
	allocIdx := 0
	
	// Process each operation based on the number of operations (t)
	for j := 0; j < t; j++ {
		// Read the operation type (alloc, erase, defragment)
		scanner.Scan()
		operation := scanner.Text()
		
		switch operation {
			case "alloc":
				// Read the size of memory to allocate
				scanner.Scan()
				fmt.Sscan(scanner.Text(), &n)
				len := 0
				canAlloc := false
				
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
						len = i - n + 1 // Calculate the starting index for allocation
						break
					}
				}
				
				// If allocation is possible, allocate memory and print the allocation ID
				if canAlloc {
					allocIdx++
					for i := len; i < len + n; i++ {
						memory[i] = allocIdx // Mark the allocated memory with the allocation ID
					}
					fmt.Println(allocIdx) // Output the allocation ID
				} else {
					fmt.Println("NULL") // Output NULL if allocation failed
				}
				
			case "erase":
				// Read the allocation ID to erase
				scanner.Scan()
				fmt.Sscan(scanner.Text(), &x)
				
				// Check for illegal erase argument
				if x <= 0 {
					fmt.Println("ILLEGAL_ERASE_ARGUMENT")
					continue
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
						memory[i - d] = memory[i] // Shift allocated memory left
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
	
	// Close the scanner to free resources
	// Note: In Go, the scanner will be automatically closed when the function returns
}

