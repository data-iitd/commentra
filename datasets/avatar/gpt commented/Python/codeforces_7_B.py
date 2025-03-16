# Read the number of operations (t) and the size of the array (m)
t, m = map(int, input().split())
# Initialize an array to keep track of allocated memory blocks, initially all set to 0
alocuente = [0] * m
# Initialize an index to keep track of the next allocation identifier
ind = 1

# Process each operation
for i in range(t):
    # Read the operation and its parameters
    op = input().split()
    
    # Handle the 'alloc' operation
    if op[0] == 'alloc':
        pos = 0  # Position counter to find free blocks
        for j in range(m):
            # Check if the current block is free (0)
            if alocuente[j] == 0:
                pos += 1  # Increment the position counter
                # If we have found enough consecutive free blocks
                if pos == int(op[1]):
                    # Allocate the blocks and set them to the current identifier
                    alocuente[j - int(op[1]) + 1:j + 1] = [ind] * int(op[1])
                    print(ind)  # Output the identifier of the allocated blocks
                    ind += 1  # Increment the identifier for the next allocation
                    break
            else:
                pos = 0  # Reset position counter if a block is occupied
        else:
            # If no sufficient space was found, output NULL
            print("NULL")
    
    # Handle the 'erase' operation
    if op[0] == 'erase':
        pos = 0  # Position counter for finding the block to erase
        # Check if the identifier to erase is valid
        if int(op[1]) not in alocuente or int(op[1]) == 0:
            print('ILLEGAL_ERASE_ARGUMENT')  # Output error for illegal erase
        else:
            # Iterate through the array to find and erase the specified block
            for j in range(m):
                if int(op[1]) > 0 and alocuente[j] == int(op[1]):
                    alocuente[j] = 0  # Set the block to 0 to indicate it is free
    
    # Handle the 'defragment' operation
    if op[0] == "defragment":
        cnt = 0  # Counter for the number of free blocks
        cnt = alocuente.count(0)  # Count how many blocks are free
        # Create a new list with only the allocated blocks (non-zero)
        alocuente = [j for j in alocuente if j != 0]
        # Append the free blocks (0) back to the end of the list
        for j in range(cnt):
            alocuente.append(0)
