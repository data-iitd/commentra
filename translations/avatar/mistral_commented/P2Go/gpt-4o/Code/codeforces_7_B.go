package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read input number of tests and memory size
	var t, m int
	fmt.Scan(&t, &m)

	// Initialize a slice to represent the memory allocation status
	alocuente := make([]int, m)
	ind := 1 // Initialize index for allocation

	// Loop through each test case
	for i := 0; i < t; i++ {
		var input string
		fmt.Scan(&input)
		op := strings.Fields(input)

		// Allocate memory if the operation type is 'alloc'
		if op[0] == "alloc" {
			size, _ := strconv.Atoi(op[1])
			pos := 0 // Initialize position counter
			for j := 0; j < m; j++ {
				// Check if the position is available for allocation
				if alocuente[j] == 0 {
					pos++
					if pos == size {
						// Set the allocated memory blocks to the given index
						for k := j - size + 1; k <= j; k++ {
							alocuente[k] = ind
						}
						// Print the allocated index
						fmt.Println(ind)
						// Increment the index for the next allocation
						ind++
						// Break the loop since we found the suitable position
						break
					}
				} else {
					pos = 0 // Reset the position counter for the next iteration
				}
			}
			if pos < size {
				// If no suitable position is found, print 'NULL'
				fmt.Println("NULL")
			}
		}

		// Erase memory if the operation type is 'erase'
		if op[0] == "erase" {
			index, _ := strconv.Atoi(op[1])
			// Check if the given index is valid and allocated
			if index <= 0 || !contains(alocuente, index) {
				// If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			} else {
				// If the index is valid and allocated, free the memory block
				for j := 0; j < m; j++ {
					if alocuente[j] == index {
						// Set the memory block to 0 to indicate it is freed
						alocuente[j] = 0
					}
				}
			}
		}

		// Defragment memory if the operation type is 'defragment'
		if op[0] == "defragment" {
			cnt := 0 // Initialize free block counter
			// Count the number of free blocks
			for _, v := range alocuente {
				if v == 0 {
					cnt++
				}
			}
			// Create a new slice with only allocated blocks
			newAlocuente := make([]int, 0, m)
			for _, v := range alocuente {
				if v != 0 {
					newAlocuente = append(newAlocuente, v)
				}
			}
			// Add free blocks at the end of the slice
			for j := 0; j < cnt; j++ {
				newAlocuente = append(newAlocuente, 0)
			}
			alocuente = newAlocuente
		}
	}
}

// Helper function to check if a slice contains a specific value
func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
