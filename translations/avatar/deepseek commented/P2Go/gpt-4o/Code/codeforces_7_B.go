package main

import (
	"fmt"
	"strings"
)

func main() {
	var t, m int
	fmt.Scan(&t, &m)
	// Read the number of operations and the size of the memory

	alocuente := make([]int, m)
	// Initialize an array to keep track of memory allocation, all elements set to 0

	ind := 1
	// Initialize the ID counter for allocated memory blocks

	for i := 0; i < t; i++ {
		// Loop through each operation
		var op string
		fmt.Scan(&op)
		// Read the operation

		if op == "alloc" {
			// If the operation is to allocate memory
			var size int
			fmt.Scan(&size)
			pos := 0
			// Initialize a position counter
			for j := 0; j < m; j++ {
				// Loop through each memory block
				if alocuente[j] == 0 {
					// Check if the memory block is free
					pos++
					// Increment the position counter
					if pos == size {
						// If a contiguous block of the required size is found
						for k := j - size + 1; k <= j; k++ {
							alocuente[k] = ind
						}
						// Allocate the memory block with the current ID
						fmt.Println(ind)
						ind++
						break
					}
				} else {
					pos = 0
					// Reset the position counter if a free block is interrupted
				}
			}
			if pos < size {
				fmt.Println("NULL")
				// If no contiguous block is found, print "NULL"
			}
		} else if op == "erase" {
			// If the operation is to erase a memory block
			var id int
			fmt.Scan(&id)
			if id <= 0 || !contains(alocuente, id) {
				// Check if the specified memory block is allocated and not already free
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				// If not, print "ILLEGAL_ERASE_ARGUMENT"
			} else {
				for j := 0; j < m; j++ {
					if alocuente[j] == id {
						alocuente[j] = 0
						// Free the specified memory block
					}
				}
			}
		} else if op == "defragment" {
			// If the operation is to defragment the memory
			cnt := 0
			for _, v := range alocuente {
				if v == 0 {
					cnt++
				}
			}
			// Count the number of free memory blocks
			newAlocuente := make([]int, 0, m)
			for _, v := range alocuente {
				if v != 0 {
					newAlocuente = append(newAlocuente, v)
				}
			}
			// Remove free memory blocks from the array
			for j := 0; j < cnt; j++ {
				newAlocuente = append(newAlocuente, 0)
				// Append the free memory blocks at the end of the array
			}
			alocuente = newAlocuente
		}
	}
}

func contains(slice []int, item int) bool {
	for _, v := range slice {
		if v == item {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
