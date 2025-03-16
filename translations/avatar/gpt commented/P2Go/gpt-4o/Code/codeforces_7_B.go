package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of operations (t) and the size of the array (m)
	var t, m int
	fmt.Scan(&t, &m)

	// Initialize an array to keep track of allocated memory blocks, initially all set to 0
	alocuente := make([]int, m)
	// Initialize an index to keep track of the next allocation identifier
	ind := 1

	// Process each operation
	for i := 0; i < t; i++ {
		var input string
		fmt.Scan(&input)
		op := strings.Fields(input)

		// Handle the 'alloc' operation
		if op[0] == "alloc" {
			pos := 0 // Position counter to find free blocks
			size, _ := strconv.Atoi(op[1])
			for j := 0; j < m; j++ {
				// Check if the current block is free (0)
				if alocuente[j] == 0 {
					pos++ // Increment the position counter
					// If we have found enough consecutive free blocks
					if pos == size {
						// Allocate the blocks and set them to the current identifier
						for k := j - size + 1; k <= j; k++ {
							alocuente[k] = ind
						}
						fmt.Println(ind) // Output the identifier of the allocated blocks
						ind++           // Increment the identifier for the next allocation
						break
					}
				} else {
					pos = 0 // Reset position counter if a block is occupied
				}
			}
			if pos < size {
				// If no sufficient space was found, output NULL
				fmt.Println("NULL")
			}
		}

		// Handle the 'erase' operation
		if op[0] == "erase" {
			id, _ := strconv.Atoi(op[1])
			posFound := false
			// Check if the identifier to erase is valid
			for j := 0; j < m; j++ {
				if alocuente[j] == id {
					alocuente[j] = 0 // Set the block to 0 to indicate it is free
					posFound = true
				}
			}
			if !posFound {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Output error for illegal erase
			}
		}

		// Handle the 'defragment' operation
		if op[0] == "defragment" {
			cnt := 0 // Counter for the number of free blocks
			for _, block := range alocuente {
				if block == 0 {
					cnt++ // Count how many blocks are free
				}
			}
			// Create a new slice with only the allocated blocks (non-zero)
			newAlocuente := make([]int, 0, m)
			for _, block := range alocuente {
				if block != 0 {
					newAlocuente = append(newAlocuente, block)
				}
			}
			// Append the free blocks (0) back to the end of the slice
			for j := 0; j < cnt; j++ {
				newAlocuente = append(newAlocuente, 0)
			}
			alocuente = newAlocuente
		}
	}
}

// <END-OF-CODE>
