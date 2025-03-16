// Read the number of operations (t) and the size of the array (m)
t, m := 0, 0
fmt.Scanf("%d %d", &t, &m)
// Initialize an array to keep track of allocated memory blocks, initially all set to 0
alocuente := make([]int, m)
// Initialize an index to keep track of the next allocation identifier
ind := 1

// Process each operation
for i := 0; i < t; i++ {
    // Read the operation and its parameters
    op := make([]string, 0)
    fmt.Scanf("%s", &op)
    
    // Handle the 'alloc' operation
    if op[0] == "alloc" {
        pos := 0  // Position counter to find free blocks
        for j := 0; j < m; j++ {
            // Check if the current block is free (0)
            if alocuente[j] == 0 {
                pos += 1  // Increment the position counter
                // If we have found enough consecutive free blocks
                if pos == int(op[1]) {
                    // Allocate the blocks and set them to the current identifier
                    alocuente[j-int(op[1])+1:j+1] = make([]int, int(op[1]))
                    fmt.Printf("%d\n", ind)  // Output the identifier of the allocated blocks
                    ind++  // Increment the identifier for the next allocation
                    break
                }
            } else {
                pos = 0  // Reset position counter if a block is occupied
        } else {
            // If no sufficient space was found, output NULL
            fmt.Printf("NULL\n")
    
    // Handle the 'erase' operation
    if op[0] == "erase" {
        pos := 0  // Position counter for finding the block to erase
        // Check if the identifier to erase is valid
        if int(op[1]) not in alocuente || int(op[1]) == 0 {
            fmt.Printf("ILLEGAL_ERASE_ARGUMENT\n")  // Output error for illegal erase
        } else {
            // Iterate through the array to find and erase the specified block
            for j := 0; j < m; j++ {
                if int(op[1]) > 0 && alocuente[j] == int(op[1]) {
                    alocuente[j] = 0  // Set the block to 0 to indicate it is free
    
    // Handle the 'defragment' operation
    if op[0] == "defragment" {
        cnt := 0  // Counter for the number of free blocks
        cnt = len(alocuente) - len(alocuente[alocuente[:] == 0])  // Count how many blocks are free
        // Create a new list with only the allocated blocks (non-zero)
        alocuente = alocuente[alocuente[:]!= 0]
        // Append the free blocks (0) back to the end of the list
        for j := 0; j < cnt; j++ {
            alocuente = append(alocuente, 0)
}
