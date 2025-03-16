class MemoryManager:
    def __init__(self, m):
        self.memory = [0] * m  # Initialize an array to keep track of memory allocation.
        self.alloc_idx = 0  # Initialize the allocation index.

    def alloc(self, n):
        len_free = 0  # Initialize the length counter.
        can_alloc = False  # Flag to check if allocation is possible.
        start_index = 0  # To store the starting index of the block.

        for i in range(len(self.memory)):  # Iterate through memory to find a suitable block.
            if self.memory[i] == 0:  # Increment length if current block is free.
                len_free += 1
            else:
                len_free = 0  # Reset length if current block is allocated.

            if len_free == n:  # Check if a block of size n is found.
                can_alloc = True  # Set flag to true.
                start_index = i - n + 1  # Set the starting index of the block.
                break  # Exit the loop as block is found.

        if can_alloc:  # If allocation is possible.
            self.alloc_idx += 1  # Increment the allocation index.
            for i in range(start_index, start_index + n):
                self.memory[i] = self.alloc_idx  # Allocate the block.
            print(self.alloc_idx)  # Print the allocation index.
        else:
            print("NULL")  # If allocation is not possible, print "NULL".

    def erase(self, x):
        if x <= 0:  # Check if the index is valid.
            print("ILLEGAL_ERASE_ARGUMENT")  # Print error message if index is invalid.
            return

        has_erased = False  # Flag to check if any block is erased.

        for i in range(len(self.memory)):  # Iterate through memory to find the block to erase.
            if self.memory[i] == x:  # Check if the block matches the index.
                self.memory[i] = 0  # Erase the block.
                has_erased = True  # Set flag to true.

        if not has_erased:
            print("ILLEGAL_ERASE_ARGUMENT")  # If no block is erased, print error message.

    def defragment(self):
        d = 0  # Initialize the defragmentation index.
        for i in range(len(self.memory)):  # Iterate through memory to defragment.
            if self.memory[i] == 0:
                d += 1  # Increment defragmentation index if current block is free.
            else:
                self.memory[i - d] = self.memory[i]  # Shift the block to the left.

        for i in range(len(self.memory) - d, len(self.memory)):
            self.memory[i] = 0  # Fill the remaining space with zeros.


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    t = int(data[0])  # Read the number of test cases (t) from the input.
    m = int(data[1])  # Read the size of memory (m) from the input.
    memory_manager = MemoryManager(m)  # Create a MemoryManager instance.

    for j in range(2, 2 + t):  # Loop through each test case.
        command = data[j].split()  # Read the command and perform the corresponding action.
        if command[0] == "alloc":
            n = int(command[1])  # Read the size of memory block to allocate.
            memory_manager.alloc(n)
        elif command[0] == "erase":
            x = int(command[1])  # Read the index of the block to erase.
            memory_manager.erase(x)
        elif command[0] == "defragment":
            memory_manager.defragment()
        else:
            print("h")  # If the command is unknown, print "h".

if __name__ == "__main__":
    main()  # Execute the main function.

# <END-OF-CODE>
