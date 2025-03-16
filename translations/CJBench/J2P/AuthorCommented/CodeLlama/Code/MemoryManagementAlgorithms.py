
import sys

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
        sys.exit()

    allocations = algorithm.fit_process(block_sizes, process_sizes)
    print("Memory Allocation Results:")
    for i in range(len(allocations)):
        if allocations[i] != -255:
            print(f"Process {i} -> Block {allocations[i]}")
        else:
            print(f"Process {i} -> No Allocation")


class BestFitCPU:
    def fit_process(self, block_sizes, process_sizes):
        mem_alloc = []
        for process_size in process_sizes:
            chosen_block_idx = self.find_best_fit(block_sizes, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != -255:
                block_sizes[chosen_block_idx] -= process_size
        return mem_alloc

    def find_best_fit(self, block_sizes, process_size):
        min_diff = sys.maxsize
        index = -255
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] - process_size < min_diff:
                min_diff = block_sizes[i] - process_size
                index = i
        return index


class WorstFitCPU:
    def fit_process(self, block_sizes, process_sizes):
        mem_alloc = []
        for process_size in process_sizes:
            chosen_block_idx = self.find_worst_fit(block_sizes, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != -255:
                block_sizes[chosen_block_idx] -= process_size
        return mem_alloc

    def find_worst_fit(self, block_sizes, process_size):
        max = -1
        index = -255
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size and block_sizes[i] > max:
                max = block_sizes[i]
                index = i
        return index


class FirstFitCPU:
    def fit_process(self, block_sizes, process_sizes):
        mem_alloc = []
        for process_size in process_sizes:
            chosen_block_idx = self.find_first_fit(block_sizes, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != -255:
                block_sizes[chosen_block_idx] -= process_size
        return mem_alloc

    def find_first_fit(self, block_sizes, process_size):
        for i in range(len(block_sizes)):
            if block_sizes[i] >= process_size:
                return i
        return -255


class NextFit:
    def fit_process(self, block_sizes, process_sizes):
        mem_alloc = []
        for process_size in process_sizes:
            chosen_block_idx = self.find_next_fit(block_sizes, process_size)
            mem_alloc.append(chosen_block_idx)
            if chosen_block_idx != -255:
                block_sizes[chosen_block_idx] -= process_size
        return mem_alloc

    def find_next_fit(self, block_sizes, process_size):
        for i in range(len(block_sizes)):
            idx = (self.counter + i) % len(block_sizes)
            if block_sizes[idx] >= process_size:
                self.counter = idx
                return idx
        return -255


if __name__ == "__main__":
    main()

