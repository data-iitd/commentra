from typing import List

# Abstract class for the memory allocation problem solution
class Main:
    # Constant value for no allocation
    NO_ALLOCATION = -255

    # Abstract method to find the best fit process for given block sizes and process sizes
    def fit_process(self, size_of_blocks: List[int], size_of_processes: List[int]) -> List[int]:
        raise NotImplementedError("Subclasses should implement this method.")

# BestFitCPU class for the Best Fit algorithm
class BestFitCPU(Main):
    # Find the index of the block with the best fit for the given process size
    @staticmethod
    def find_best_fit(block_sizes: List[int], process_size: int) -> int:
        min_diff = float('inf')
        index = Main.NO_ALLOCATION
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and (block_sizes[i] - process_size) < min_diff:
                min_diff = block_sizes[i] - process_size
                index = i
        return index

    # Override the fit_process method to implement the Best Fit algorithm
    def fit_process(self, size_of_blocks: List[int], size_of_processes: List[int]) -> List[int]:
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_best_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != Main.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

# WorstFitCPU class for the Worst Fit algorithm
class WorstFitCPU(Main):
    # Find the index of the block with the worst fit for the given process size
    @staticmethod
    def find_worst_fit(block_sizes: List[int], process_size: int) -> int:
        max_size = -1
        index = Main.NO_ALLOCATION
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] > max_size:
                max_size = block_sizes[i]
                index = i
        return index

    # Override the fit_process method to implement the Worst Fit algorithm
    def fit_process(self, size_of_blocks: List[int], size_of_processes: List[int]) -> List[int]:
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_worst_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != Main.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

# FirstFitCPU class for the First Fit algorithm
class FirstFitCPU(Main):
    # Find the index of the first available block for the given process size
    @staticmethod
    def find_first_fit(block_sizes: List[int], process_size: int) -> int:
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size:
                return i
        return Main.NO_ALLOCATION

    # Override the fit_process method to implement the First Fit algorithm
    def fit_process(self, size_of_blocks: List[int], size_of_processes: List[int]) -> List[int]:
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_first_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != Main.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

# NextFit class for the Next Fit algorithm
class NextFit(Main):
    # Counter variable to keep track of the index in the block_sizes array
    def __init__(self):
        self.counter = 0

    # Find the index of the next available block for the given process size
    def find_next_fit(self, block_sizes: List[int], process_size: int) -> int:
        idx = (self.counter + 1) % len(block_sizes)
        while idx < len(block_sizes):
            if block_sizes[idx] >= process_size:
                self.counter = idx
                return idx
            idx += 1
        return Main.NO_ALLOCATION

    # Override the fit_process method to implement the Next Fit algorithm
    def fit_process(self, size_of_blocks: List[int], size_of_processes: List[int]) -> List[int]:
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_next_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != Main.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

# Main execution block
if __name__ == "__main__":
    num_blocks = int(input())
    block_sizes = list(map(int, input().split()))
    num_processes = int(input())
    process_sizes = list(map(int, input().split()))
    choice = int(input())

    # Initialize the appropriate algorithm object based on the user choice
    if choice == 1:
        algorithm = BestFitCPU()
    elif choice == 2:
        algorithm = WorstFitCPU()
    elif choice == 3:
        algorithm = FirstFitCPU()
    elif choice == 4:
        algorithm = NextFit()
    else:
        print("Invalid choice.")
        exit()

    # Call the fit_process method of the algorithm object to find the memory allocation for each process
    allocations = algorithm.fit_process(block_sizes, process_sizes)

    # Print the memory allocation results
    print("Memory Allocation Results:")
    for i in range(len(allocations)):
        if allocations[i] != Main.NO_ALLOCATION:
            print(f"Process {i} -> Block {allocations[i]}")
        else:
            print(f"Process {i} -> No Allocation")

# <END-OF-CODE>











