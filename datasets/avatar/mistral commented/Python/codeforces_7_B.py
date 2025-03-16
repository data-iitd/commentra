#######
# Code
#######

# Read input number of tests and memory size
t, m = map(int, input().split())

# Initialize an array to represent the memory allocation status
alocuente = [0] * m

# Loop through each test case
for i in range(t):
    # Read the operation type and arguments
    op = input().split()

    # Allocate memory if the operation type is 'alloc'
    if op[0] == 'alloc':
        pos = 0  # Initialize position counter
        for j in range(m):
            # Check if the position is available for allocation
            if alocuente[j] == 0:
                # If the position is available, allocate the memory block of the given size
                pos += 1
                if pos == int(op[1]):
                    # Set the allocated memory blocks to the given index
                    alocuente[j - int(op[1]) + 1:j + 1] = [ind] * int(op[1])
                    # Print the allocated index
                    print(ind)
                    # Increment the index for the next allocation
                    ind += 1
                    # Break the loop since we found the suitable position
                    break
                else:
                    pos = 0  # Reset the position counter for the next iteration
        else:
            # If no suitable position is found, print 'NULL'
            print("NULL")

    # Erase memory if the operation type is 'erase'
    elif op[0] == 'erase':
        pos = 0  # Initialize position counter
        # Check if the given index is valid and allocated
        if int(op[1]) not in alocuente or int(op[1]) == 0:
            # If the index is not valid or already freed, print 'ILLEGAL_ERASE_ARGUMENT'
            print('ILLEGAL_ERASE_ARGUMENT')
        else:
            # If the index is valid and allocated, free the memory block
            for j in range(m):
                if int(op[1]) > 0 and alocuente[j] == int(op[1]):
                    # Set the memory block to 0 to indicate it is freed
                    alocuente[j] = 0

    # Defragment memory if the operation type is 'defragment'
    elif op[0] == "defragment":
        cnt = 0  # Initialize free block counter
        # Count the number of free blocks
        cnt = alocuente.count(0)
        # Create a new list with only allocated blocks
        alocuente = [j for j in alocuente if j != 0]
        # Add free blocks at the end of the list
        for j in range(cnt):
            alocuente.append(0)
