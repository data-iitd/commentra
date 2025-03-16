#######
# Code
#######

// Read input number of tests and memory size
var t, m int
fmt.Scan(&t, &m)

// Initialize an array to represent the memory allocation status
alocuente := make([]int, m)

// Loop through each test case
for i := 0; i < t; i++ {
	// Read the operation type and arguments
	op := strings.Split(input(), " ")

	// Allocate memory if the operation type is 'alloc'
	if op[0] == "alloc" {
		pos := 0 // Initialize position counter
		for j := 0; j < m; j++ {
			// Check if the position is available for allocation
			if alocuente[j] == 0 {
				// If the position is available, allocate the memory block of the given size
				pos += 1
				if pos == int(op[1]) {
					// Set the allocated memory blocks to the given index
					alocuente[j-int(op[1])+1 : j+1] = []int{ind}
					// Print the allocated index
					fmt.Println(ind)
					// Increment the index for the next allocation
					ind += 1
					// Break the loop since we found the suitable position
					break
				} else {
					pos = 0 // Reset the position counter for the next iteration
				}
			}
		}
		if pos == 0 {
			// If no suitable position is found, print 'NULL'
			fmt.Println("NULL")
		}
	}

	// Erase memory if the operation type is 'erase'
	if op[0] == "erase" {
		pos := 0 // Initialize position counter
		// Check if the given index is valid and allocated
		if int(op[1]) >= m || alocuente[int(op[1])] == 0 {
			// If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
			fmt.Println("ILLEGAL_ERASE_ARGUMENT")
		} else {
			// If the index is valid and allocated, free the memory block
			for j := 0; j < m; j++ {
				if int(op[1]) > 0 && alocuente[j] == int(op[1]) {
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
		for j := 0; j < m; j++ {
			if alocuente[j] == 0 {
				cnt += 1
			}
		}
		// Create a new list with only allocated blocks
		alocuente = alocuente[:0]
		for j := 0; j < m; j++ {
			if alocuente[j] != 0 {
				alocuente = append(alocuente, alocuente[j])
			}
		}
		// Add free blocks at the end of the list
		for j := 0; j < cnt; j++ {
			alocuente = append(alocuente, 0)
		}
	}
}

// End of code
