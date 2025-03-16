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
	// Read the number of operations (t) and the size of the array (m)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	t, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	
	// Initialize an array to keep track of allocated memory blocks, initially all set to 0
	alocuente := make([]int, m)
	// Initialize an index to keep track of the next allocation identifier
	ind := 1
	
	// Process each operation
	for i := 0; i < t; i++ {
		// Read the operation and its parameters
		op, _ := reader.ReadString('\n')
		opParts := strings.Split(strings.TrimSpace(op), " ")
		
		// Handle the 'alloc' operation
		if opParts[0] == "alloc" {
			pos := 0  // Position counter to find free blocks
			size, _ := strconv.Atoi(opParts[1])
			for j := 0; j < m; j++ {
				// Check if the current block is free (0)
				if alocuente[j] == 0 {
					pos += 1  // Increment the position counter
					// If we have found enough consecutive free blocks
					if pos == size {
						// Allocate the blocks and set them to the current identifier
						for k := j - size + 1; k <= j; k++ {
							alocuente[k] = ind
						}
						fmt.Println(ind)  // Output the identifier of the allocated blocks
						ind += 1  // Increment the identifier for the next allocation
						break
					}
				} else {
					pos = 0  // Reset position counter if a block is occupied
				}
			}
			if pos != size {
				// If no sufficient space was found, output NULL
				fmt.Println("NULL")
			}
		}
		
		// Handle the 'erase' operation
		if opParts[0] == "erase" {
			id, _ := strconv.Atoi(opParts[1])
			// Check if the identifier to erase is valid
			if id == 0 || !contains(alocuente, id) {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")  // Output error for illegal erase
			} else {
				// Iterate through the array to find and erase the specified block
				for j := 0; j < m; j++ {
					if alocuente[j] == id {
						alocuente[j] = 0  // Set the block to 0 to indicate it is free
					}
				}
			}
		}
		
		// Handle the 'defragment' operation
		if opParts[0] == "defragment" {
			cnt := 0  // Counter for the number of free blocks
			for _, v := range alocuente {
				if v == 0 {
					cnt++
				}
			}
			// Create a new list with only the allocated blocks (non-zero)
			nonZero := []int{}
			for _, v := range alocuente {
				if v != 0 {
					nonZero = append(nonZero, v)
				}
			}
			// Append the free blocks (0) back to the end of the list
			for j := 0; j < cnt; j++ {
				nonZero = append(nonZero, 0)
			}
			alocuente = nonZero
		}
	}
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}
