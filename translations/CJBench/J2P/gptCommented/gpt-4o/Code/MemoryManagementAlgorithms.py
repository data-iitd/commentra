from abc import ABC, abstractmethod

# Abstract class representing the main memory allocation algorithm
class Main(ABC):
    # Constant representing no allocation
    NO_ALLOCATION = -255

    @abstractmethod
    def fit_process(self, size_of_blocks, size_of_processes):
        pass

def main():
    # Read the number of memory blocks
    num_blocks = int(input())
    block_sizes = list(map(int, input().split()))
    
    # Read the number of processes
    num_processes = int(input())
    process_sizes = list(map(int, input().split()))
    
    # Read the user's choice of memory allocation algorithm
    choice = int(input())
    
    # Select the appropriate memory allocation algorithm based on user choice
    if choice == 1:
        algorithm = BestFitCPU()
    elif choice == 2:
        algorithm = WorstFitCPU()
    elif choice == 3:
        algorithm = FirstFitCPU()
    elif choice == 4:
        algorithm = NextFit()
    else:
        # Handle invalid choice
        print("Invalid choice.")
        return
    
    # Perform memory allocation using the selected algorithm
    allocations = algorithm.fit_process(block_sizes, process_sizes)
    
    # Output the results of memory allocation
    print("Memory Allocation Results:")
    for i in range(len(allocations)):
        if allocations[i] != Main.NO_ALLOCATION:
            print(f"Process {i} -> Block {allocations[i]}")
        else:
            print(f"Process {i} -> No Allocation")

# Class implementing the Best Fit memory allocation algorithm
class BestFitCPU(Main):
    def find_best_fit(self, block_sizes, process_size):
        min_diff = float('inf')  # Initialize minimum difference
        index = self.NO_ALLOCATION  # Initialize index for no allocation
        
        # Iterate through the blocks to find the best fit
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] - process_size < min_diff:
                min_diff = block_sizes[i] - process_size  # Update minimum difference
                index = i  # Update index of the best fit block
        return index  # Return the index of the best fit block

    # Override the fit_process method to implement Best Fit allocation
    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []  # List to store memory allocations
        
        # Allocate memory for each process
        for process_size in size_of_processes:
            chosen_block_idx = self.find_best_fit(size_of_blocks, process_size)  # Find the best fit block
            mem_alloc.append(chosen_block_idx)  # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc  # Return the list of allocations

# Class implementing the Worst Fit memory allocation algorithm
class WorstFitCPU(Main):
    def find_worst_fit(self, block_sizes, process_size):
        max_size = -1  # Initialize maximum size
        index = self.NO_ALLOCATION  # Initialize index for no allocation
        
        # Iterate through the blocks to find the worst fit
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] > max_size:
                max_size = block_sizes[i]  # Update maximum size
                index = i  # Update index of the worst fit block
        return index  # Return the index of the worst fit block

    # Override the fit_process method to implement Worst Fit allocation
    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []  # List to store memory allocations
        
        # Allocate memory for each process
        for process_size in size_of_processes:
            chosen_block_idx = self.find_worst_fit(size_of_blocks, process_size)  # Find the worst fit block
            mem_alloc.append(chosen_block_idx)  # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc  # Return the list of allocations

# Class implementing the First Fit memory allocation algorithm
class FirstFitCPU(Main):
    def find_first_fit(self, block_sizes, process_size):
        # Iterate through the blocks to find the first fit
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size:
                return i  # Return the index of the first fit block
        return self.NO_ALLOCATION  # Return no allocation if no fit is found

    # Override the fit_process method to implement First Fit allocation
    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []  # List to store memory allocations
        
        # Allocate memory for each process
        for process_size in size_of_processes:
            chosen_block_idx = self.find_first_fit(size_of_blocks, process_size)  # Find the first fit block
            mem_alloc.append(chosen_block_idx)  # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc  # Return the list of allocations

# Class implementing the Next Fit memory allocation algorithm
class NextFit(Main):
    def __init__(self):
        self.counter = 0  # Counter to track the next fit position

    def find_next_fit(self, block_sizes, process_size):
        # Iterate through the blocks starting from the last allocated position
        for i in range(len(block_sizes)):
            idx = (self.counter + i) % len(block_sizes)  # Calculate the index in a circular manner
            if block_sizes[idx] >= process_size:
                self.counter = idx  # Update the counter to the current index
                return idx  # Return the index of the next fit block
        return self.NO_ALLOCATION  # Return no allocation if no fit is found

    # Override the fit_process method to implement Next Fit allocation
    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []  # List to store memory allocations
        
        # Allocate memory for each process
        for process_size in size_of_processes:
            chosen_block_idx = self.find_next_fit(size_of_blocks, process_size)  # Find the next fit block
            mem_alloc.append(chosen_block_idx)  # Add the allocation result
            
            # If a block is allocated, reduce its size
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc  # Return the list of allocations

if __name__ == "__main__":
    main()

# <END-OF-CODE>
