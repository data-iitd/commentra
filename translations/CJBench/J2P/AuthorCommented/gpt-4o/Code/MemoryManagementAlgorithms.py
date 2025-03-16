from abc import ABC, abstractmethod

NO_ALLOCATION = -255

class MemoryManagementAlgorithm(ABC):
    @abstractmethod
    def fit_process(self, size_of_blocks, size_of_processes):
        pass

class BestFitCPU(MemoryManagementAlgorithm):
    @staticmethod
    def find_best_fit(block_sizes, process_size):
        min_diff = float('inf')
        index = NO_ALLOCATION
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and (block_sizes[i] - process_size) < min_diff:
                min_diff = block_sizes[i] - process_size
                index = i
        return index

    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_best_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

class WorstFitCPU(MemoryManagementAlgorithm):
    @staticmethod
    def find_worst_fit(block_sizes, process_size):
        max_size = -1
        index = NO_ALLOCATION
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] > max_size:
                max_size = block_sizes[i]
                index = i
        return index

    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_worst_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

class FirstFitCPU(MemoryManagementAlgorithm):
    @staticmethod
    def find_first_fit(block_sizes, process_size):
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size:
                return i
        return NO_ALLOCATION

    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_first_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

class NextFit(MemoryManagementAlgorithm):
    def __init__(self):
        self.counter = 0

    def find_next_fit(self, block_sizes, process_size):
        for i in range(len(block_sizes)):
            idx = (self.counter + i) % len(block_sizes)
            if block_sizes[idx] >= process_size:
                self.counter = idx
                return idx
        return NO_ALLOCATION

    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_next_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc

def main():
    num_blocks = int(input())
    block_sizes = list(map(int, input().split()))
    
    num_processes = int(input())
    process_sizes = list(map(int, input().split()))
    
    choice = int(input())
    
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
        return

    allocations = algorithm.fit_process(block_sizes, process_sizes)
    print("Memory Allocation Results:")
    for i in range(len(allocations)):
        if allocations[i] != NO_ALLOCATION:
            print(f"Process {i} -> Block {allocations[i]}")
        else:
            print(f"Process {i} -> No Allocation")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
