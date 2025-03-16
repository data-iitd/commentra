import sys

def main():
    # Read the number of operations (t) and the size of memory (m)
    t = int(sys.stdin.readline())
    m = int(sys.stdin.readline())

    # Initialize the memory array to keep track of allocated memory
    memory = [0] * m

    # Initialize the allocation index to track the allocation IDs
    allocIdx = 0

    # Process each operation based on the number of operations (t)
    for j in range(t):
        # Read the operation type (alloc, erase, defragment)
        op = sys.stdin.readline().strip()

        if op == "alloc":
            # Read the size of memory to allocate
            n = int(sys.stdin.readline())
            len = 0
            canAlloc = False

            # Check for a contiguous block of free memory of size n
            for i in range(m):
                if memory[i] == 0:
                    len += 1 # Increase length if the current memory is free
                else:
                    len = 0 # Reset length if the current memory is allocated

                # If a sufficient block is found, mark it as allocatable
                if len == n:
                    canAlloc = True
                    len = i - n + 1 # Calculate the starting index for allocation
                    break

            # If allocation is possible, allocate memory and print the allocation ID
            if canAlloc:
                allocIdx += 1
                for i in range(len, len + n):
                    memory[i] = allocIdx # Mark the allocated memory with the allocation ID
                print(allocIdx) # Output the allocation ID
            else:
                print("NULL") # Output NULL if allocation failed

        elif op == "erase":
            # Read the allocation ID to erase
            x = int(sys.stdin.readline())

            # Check for illegal erase argument
            if x <= 0:
                print("ILLEGAL_ERASE_ARGUMENT")
                break

            hasErased = False

            # Erase the memory corresponding to the given allocation ID
            for i in range(m):
                if memory[i] == x:
                    memory[i] = 0 # Free the allocated memory
                    hasErased = True

            # If no memory was erased, print an error message
            if not hasErased:
                print("ILLEGAL_ERASE_ARGUMENT")

        elif op == "defragment":
            # Initialize a counter for the number of free blocks
            d = 0

            # Move allocated memory to the front of the array
            for i in range(m):
                if memory[i] == 0:
                    d += 1 # Count free blocks
                else:
                    memory[i - d] = memory[i] # Shift allocated memory left

            # Clear the remaining memory at the end of the array
            for i in range(m - d, m):
                memory[i] = 0

        else:
            # Handle any unrecognized command
            print("h")

if __name__ == "__main__":
    main()

# 