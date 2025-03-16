import sys

def main():
    t = int(input().strip())  # Step 1: Read the number of test cases (t) from the input.
    m = int(input().strip())  # Step 1: Read the size of memory (m) from the input.
    memory = [0] * m  # Step 2: Initialize an array to keep track of memory allocation.
    alloc_idx = 0  # Initialize the allocation index.
    
    for _ in range(t):  # Step 3: Loop through each test case.
        command = input().strip()  # Step 4: Read the command and perform the corresponding action.
        
        if command == "alloc":
            n = int(input().strip())  # Step 5: Read the size of memory block to allocate.
            len_ = 0  # Initialize the length counter.
            can_alloc = False  # Flag to check if allocation is possible.
            
            for i in range(m):  # Iterate through memory to find a suitable block.
                if memory[i] == 0:
                    len_ += 1  # Increment length if current block is free.
                else:
                    len_ = 0  # Reset length if current block is allocated.
                
                if len_ == n:  # Check if a block of size n is found.
                    can_alloc = True  # Set flag to true.
                    len_ = i - n + 1  # Set the starting index of the block.
                    break  # Exit the loop as block is found.
            
            if can_alloc:  # Step 5: If allocation is possible.
                alloc_idx += 1  # Increment the allocation index.
                for i in range(len_, len_ + n):
                    memory[i] = alloc_idx  # Allocate the block.
                print(alloc_idx)  # Print the allocation index.
            else:
                print("NULL")  # Step 5: If allocation is not possible, print "NULL".
        
        elif command == "erase":
            x = int(input().strip())  # Step 6: Read the index of the block to erase.
            if x <= 0:  # Check if the index is valid.
                print("ILLEGAL_ERASE_ARGUMENT")  # Print error message if index is invalid.
                continue
            has_erased = False  # Flag to check if any block is erased.
            
            for i in range(m):  # Iterate through memory to find the block to erase.
                if memory[i] == x:  # Check if the block matches the index.
                    memory[i] = 0  # Erase the block.
                    has_erased = True  # Set flag to true.
            
            if not has_erased:  # Step 6: If no block is erased, print error message.
                print("ILLEGAL_ERASE_ARGUMENT")
        
        elif command == "defragment":
            d = 0  # Initialize the defragmentation index.
            for i in range(m):  # Iterate through memory to defragment.
                if memory[i] == 0:
                    d += 1  # Increment defragmentation index if current block is free.
                else:
                    memory[i - d] = memory[i]  # Shift the block to the left.
            for i in range(m - d, m):
                memory[i] = 0  # Fill the remaining space with zeros.
        
        else:
            print("h")  # Step 8: If the command is unknown, print "h".
    
    # Step 9: Close the scanner (not applicable in Python).

if __name__ == "__main__":
    main()
