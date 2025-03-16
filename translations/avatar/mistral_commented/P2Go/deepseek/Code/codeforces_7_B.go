```go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	// Read input number of tests and memory size
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	t, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])

	// Initialize an array to represent the memory allocation status
	alocuente := make([]int, m)

	// Loop through each test case
	for i := 0; i < t; i++ {
		// Read the operation type and arguments
		op, _ := reader.ReadString('\n')
		opParts := strings.Split(strings.TrimSpace(op), " ")
		operation := opParts[0]

		// Allocate memory if the operation type is 'alloc'
		if operation == "alloc" {
			pos := 0 // Initialize position counter
			size, _ := strconv.Atoi(opParts[1])
			for j := 0; j < m; j++ {
				// Check if the position is available for allocation
				if alocuente[j] == 0 {
					pos++
					if pos == size {
						// Set the allocated memory blocks to the given index
						for k := j - size + 1; k <= j; k++ {
							alocuente[k] = j - k + 1
						}
						// Print the allocated index
						fmt.Println(j - size + 1)
						break
					}
				} else {
					pos = 0 // Reset the position counter for the next iteration
				}
			}
			if pos != size {
				// If no suitable position is found, print 'NULL'
				fmt.Println("NULL")
			}
		}

		// Erase memory if the operation type is 'erase'
		if operation == "erase" {
			index, _ := strconv.Atoi(opParts[1])
			// Check if the given index is valid and allocated
			if index < 0 || index >= m || alocuente[index] == 0 {
				// If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				// If the index is valid and allocated, free the memory block
				for j := 0; j < m; j++ {
					if alocuente[j] == index {
						alocuente[j] = 0
					}
				}
			}
		}

		// Defragment memory if the operation type is 'defragment'
		if operation == "defragment" {
			freeBlocks := 0
			// Count the number of free blocks
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					freeBlocks++
				}
			}
			// Create a new list with only allocated blocks
			nonZeroIndices := []int{}
			for j := 0; j < m; j++ {
				if alocuente[j] != 0 {
					nonZeroIndices = append(nonZeroIndices, alocuente[j])
				}
			}
			// Add free blocks at the end of the list
			for j := 0; j < freeBlocks; j++ {
				nonZeroIndices = append(nonZeroIndices, 0)
			}
			// Update the alocuente array
			copy(alocuente, nonZeroIndices)
		}
	}
}
