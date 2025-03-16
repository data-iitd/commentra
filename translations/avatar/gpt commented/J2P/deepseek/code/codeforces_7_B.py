import sys

def main():
    # Read the number of operations (t) and the size of memory (m)
    t, m = map(int, sys.stdin.readline().split())
    
    # Initialize the memory array to keep track of allocated memory
    memory = [0] * m
    
    # Initialize the allocation index to track the allocation IDs
    alloc_idx = 0
    
    # Process each operation based on the number of operations (t)
    for _ in range(t):
        # Read the operation type (alloc, erase, defragment)
        operation = sys.stdin.readline().strip()
        
        if operation == "alloc":
            # Read the size of memory to allocate
            n = int(sys.stdin.readline().strip())
            length = 0
            can_alloc = False
            
            # Check for a contiguous block of free memory of size n
            for i in range(m):
                if memory[i] == 0:
                    length += 1  # Increase length if the current memory is free
                else:
                    length = 0  # Reset length if the current memory is allocated
                
                # If a sufficient block is found, mark it as allocatable
                if length == n:
                    can_alloc = True
                    length = i - n + 1  # Calculate the starting index for allocation
                    break
            
            # If allocation is possible, allocate memory and print the allocation ID
            if can_alloc:
                alloc_idx += 1
                for i in range(length, length + n):
                    memory[i] = alloc_idx  # Mark the allocated memory with the allocation ID
                print(alloc_idx)  # Output the allocation ID
            else:
                print("NULL")  # Output NULL if allocation failed
        
        elif operation == "erase":
            # Read the allocation ID to erase
            x = int(sys.stdin.readline().strip())
            
            # Check for illegal erase argument
            if x <= 0:
                print("ILLEGAL_ERASE_ARGUMENT")
                continue
            
            has_erased = False
            
            # Erase the memory corresponding to the given allocation ID
            for i in range(m):
                if memory[i] == x:
                    memory[i] = 0  # Free the allocated memory
                    has_erased = True
            
            # If no memory was erased, print an error message
            if not has_erased:
                print("ILLEGAL_ERASE_ARGUMENT")
        
        elif operation == "defragment":
            # Initialize a counter for the number of free blocks
            d = 0
            
            # Move allocated memory to the front of the array
            for i in range(m):
                if memory[i] == 0:
                    d += 1  # Count free blocks
                else:
                    memory[i - d] = memory[i]  # Shift allocated memory left
            
            # Clear the remaining memory at the end of the array
            for i in range(m - d, m):
                memory[i] = 0
        
        else:
            # Handle any unrecognized command
            print("h")

if __name__ == "__main__":
    main()
