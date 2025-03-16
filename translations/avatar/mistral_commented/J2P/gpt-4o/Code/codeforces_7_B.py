class MemoryManager:  # Defining the MemoryManager class

    def __init__(self, m):  # Initializing the memory manager with size m
        self.memory = [0] * m  # Initializing a list of size m to represent the memory
        self.alloc_idx = 0  # Initializing a counter for allocated memory blocks

    def alloc(self, n):  # Allocate method
        len_free = 0  # Initializing a counter for free memory blocks
        can_alloc = False  # Flag to check if allocation is possible
        start_index = 0  # To store the starting index of the allocation

        for i in range(len(self.memory)):  # Loop through the memory list
            if self.memory[i] == 0:  # If the current block is free
                len_free += 1  # Increment the counter
            else:  # If the current block is allocated
                len_free = 0  # Reset the counter

            if len_free == n:  # If the free memory blocks form a block of size n
                can_alloc = True  # Set the flag
                start_index = i - n + 1  # Calculate the start index of the block
                break  # Exit the loop

        if can_alloc:  # If allocation is possible
            self.alloc_idx += 1  # Increment the counter for allocated blocks
            for i in range(start_index, start_index + n):  # Allocate the block in the memory
                self.memory[i] = self.alloc_idx
            return self.alloc_idx  # Return the allocated block number
        else:  # If allocation is not possible
            return "NULL"  # Return NULL

    def erase(self, x):  # Erase method
        if x <= 0:  # If the block number is invalid
            return "ILLEGAL_ERASE_ARGUMENT"  # Return an error message

        has_erased = False  # Flag to check if the block has been erased
        for i in range(len(self.memory)):  # Loop through the memory list
            if self.memory[i] == x:  # If the current block matches the given block number
                self.memory[i] = 0  # Erase the block
                has_erased = True  # Set the flag

        if not has_erased:  # If the block was not found
            return "ILLEGAL_ERASE_ARGUMENT"  # Return an error message

    def defragment(self):  # Defragment method
        new_memory = [block for block in self.memory if block != 0]  # Create a new memory list with only allocated blocks
        self.memory = new_memory + [0] * (len(self.memory) - len(new_memory))  # Update the memory list

def main():  # Main function
    import sys
    input = sys.stdin.read
    data = input().splitlines()  # Read all input lines
    t = int(data[0])  # Reading the number of test cases
    m = int(data[1])  # Reading the size of the memory
    memory_manager = MemoryManager(m)  # Creating a MemoryManager object

    for j in range(2, 2 + t):  # Loop through each test case
        command = data[j].split()  # Split the command line
        if command[0] == "alloc":  # Allocate command
            n = int(command[1])  # Reading the size of the block to be allocated
            result = memory_manager.alloc(n)  # Call the alloc method
            print(result)  # Print the result
        elif command[0] == "erase":  # Erase command
            x = int(command[1])  # Reading the block number to be erased
            result = memory_manager.erase(x)  # Call the erase method
            if result:  # If there's a result to print
                print(result)  # Print the result
        elif command[0] == "defragment":  # Defragment command
            memory_manager.defragment()  # Call the defragment method
        else:  # Invalid command
            print("h")  # Print an error message

if __name__ == "__main__":  # If this script is run directly
    main()  # Call the main function

# <END-OF-CODE>
