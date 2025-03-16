
package main

import (
	"fmt"
	"strconv"
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
		op := strings.Split(readLine(0), " ")
		// Read the operation and split it into parts
		if op[0] == "alloc" {
			// If the operation is to allocate memory
			pos := 0
			// Initialize a position counter
			for j := 0; j < m; j++ {
				// Loop through each memory block
				if alocuente[j] == 0 {
					// Check if the memory block is free
					pos++
					// Increment the position counter
					if pos == toInt(op[1]) {
						// If a contiguous block of the required size is found
						for k := j - toInt(op[1]) + 1; k <= j; k++ {
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
			if pos == 0 {
				fmt.Println("NULL")
				// If no contiguous block is found, print "NULL"
			}
		}
		if op[0] == "erase" {
			// If the operation is to erase a memory block
			pos := 0
			if alocuente[toInt(op[1])-1] == 0 || toInt(op[1]) == 0 {
				// Check if the specified memory block is allocated and not already free
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				// If not, print "ILLEGAL_ERASE_ARGUMENT"
			} else {
				for j := 0; j < m; j++ {
					if toInt(op[1]) > 0 && alocuente[j] == toInt(op[1]) {
						alocuente[j] = 0
						// Free the specified memory block
					}
				}
			}
		}
		if op[0] == "defragment" {
			// If the operation is to defragment the memory
			cnt := 0
			for j := 0; j < m; j++ {
				if alocuente[j] == 0 {
					cnt++
				}
			}
			// Count the number of free memory blocks
			alocuente = alocuente[:len(alocuente)-cnt]
			// Remove free memory blocks from the array
			for j := 0; j < cnt; j++ {
				alocuente = append(alocuente, 0)
				// Append the free memory blocks at the end of the array
			}
		}
	}
}

func readLine(reader int) string {
	var str string
	fmt.Scan(&str)
	return str
}

func toInt(num string) int {
	result, _ := strconv.Atoi(num)
	return result
}

// 