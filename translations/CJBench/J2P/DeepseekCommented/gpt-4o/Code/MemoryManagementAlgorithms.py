class Main:
    def __init__(self):
        self.NO_ALLOCATION = -255

    def fit_process(self, size_of_blocks, size_of_processes):
        pass

    @staticmethod
    def find_best_fit(block_sizes, process_size):
        min_diff = float('inf')
        index = Main.NO_ALLOCATION
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] - process_size < min_diff:
                min_diff = block_sizes[i] - process_size
                index = i
        return index

    @staticmethod
    def find_worst_fit(block_sizes, process_size):
        max_block = -1
        index = Main.NO_ALLOCATION
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] > max_block:
                max_block = block_sizes[i]
                index = i
        return index

    @staticmethod
    def find_first_fit(block_sizes, process_size):
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size:
                return i
        return Main.NO_ALLOCATION

    @staticmethod
    def find_next_fit(block_sizes, process_size, counter):
        for i in range(len(block_sizes)):
            idx = (counter + i) % len(block_sizes)
            if block_sizes[idx] >= process_size:
                counter = idx
                return idx
        return Main.NO_ALLOCATION


class BestFitCPU(Main):
    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_best_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc


class WorstFitCPU(Main):
    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_worst_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc


class FirstFitCPU(Main):
    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_first_fit(size_of_blocks, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc


class NextFit(Main):
    def __init__(self):
        super().__init__()
        self.counter = 0

    def fit_process(self, size_of_blocks, size_of_processes):
        mem_alloc = []
        for process_size in size_of_processes:
            chosen_block_idx = self.find_next_fit(size_of_blocks, process_size, self.counter)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != self.NO_ALLOCATION:
                size_of_blocks[chosen_block_idx] -= process_size
        return mem_alloc


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    num_blocks = int(data[0])
    block_sizes = [int(size) for size in data[1:num_blocks + 1]]
    num_processes = int(data[num_blocks + 1])
    process_sizes = [int(size) for size in data[num_blocks + 2:num_blocks + 2 + num_processes]]
    
    choice = int(data[num_blocks + 2 + num_processes])
    algorithm = None
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
    
    for i in range(len(allocations)):
        if allocations[i] != -255:
            print(f"Process {i} -> Block {allocations[i]}")
        else:
            print(f"Process {i} -> No Allocation")


if __name__ == "__main__":
    main()
