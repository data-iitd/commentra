// Read the number of operations (t) and the size of the array (m)
t, m := 0, 0
fmt.Scan(&t, &m)
// Initialize an array to keep track of allocated memory blocks, initially all set to 0
alocuente := make([]int, m)
// Initialize an index to keep track of the next allocation identifier
ind := 1

// Process each operation
for i := 0; i < t; i++ {
	// Read the operation and its parameters
	op := make([]string, 0)
	fmt.Scan(&op)

	// Handle the 'alloc' operation
	if op[0] == "alloc" {
		pos := 0 // Position counter to find free blocks
		for j := 0; j < m; j++ {
			// Check if the current block is free (0)
			if alocuente[j] == 0 {
				pos++ // Increment the position counter
				// If we have found enough consecutive free blocks
				if pos == int(op[1]) {
					// Allocate the blocks and set them to the current identifier
					for k := j - int(op[1]) + 1; k <= j; k++ {
						alocuente[k] = ind
					}
					fmt.Println(ind) // Output the identifier of the allocated blocks
					ind++ // Increment the identifier for the next allocation
					break
				}
			} else {
				pos = 0 // Reset position counter if a block is occupied
			}
		}
		if pos == 0 {
			// If no sufficient space was found, output NULL
			fmt.Println("NULL")
		}
	}

	// Handle the 'erase' operation
	if op[0] == "erase" {
		pos := 0 // Position counter for finding the block to erase
		// Check if the identifier to erase is valid
		if int(op[1]) > m || int(op[1]) == 0 {
			fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Output error for illegal erase
		} else {
			// Iterate through the array to find and erase the specified block
			for j := 0; j < m; j++ {
				if int(op[1]) > 0 && alocuente[j] == int(op[1]) {
					alocuente[j] = 0 // Set the block to 0 to indicate it is free
				}
			}
		}
	}

	// Handle the 'defragment' operation
	if op[0] == "defragment" {
		cnt := 0 // Counter for the number of free blocks
		for j := 0; j < m; j++ {
			if alocuente[j] == 0 {
				cnt++ // Increment the counter for each free block
			}
		}
		// Create a new list with only the allocated blocks (non-zero)
		alocuente = alocuente[:0]
		for j := 0; j < m; j++ {
			if alocuente[j] != 0 {
				alocuente = append(alocuente, alocuente[j])
			}
		}
		// Append the free blocks (0) back to the end of the list
		for j := 0; j < cnt; j++ {
			alocuente = append(alocuente, 0)
		}
	}
}

