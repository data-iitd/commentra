class MemoryManager:
    def __init__(self, m):
        self.memory = [0] * m
        self.alloc_idx = 0

    def alloc(self, n):
        len_free = 0
        can_alloc = False
        start_index = 0

        for i in range(len(self.memory)):
            if self.memory[i] == 0:
                len_free += 1
            else:
                len_free = 0

            if len_free == n:
                can_alloc = True
                start_index = i - n + 1
                break

        if can_alloc:
            self.alloc_idx += 1
            for i in range(start_index, start_index + n):
                self.memory[i] = self.alloc_idx
            print(self.alloc_idx)
        else:
            print("NULL")

    def erase(self, x):
        if x <= 0:
            print("ILLEGAL_ERASE_ARGUMENT")
            return

        has_erased = False
        for i in range(len(self.memory)):
            if self.memory[i] == x:
                self.memory[i] = 0
                has_erased = True

        if not has_erased:
            print("ILLEGAL_ERASE_ARGUMENT")

    def defragment(self):
        d = 0
        for i in range(len(self.memory)):
            if self.memory[i] == 0:
                d += 1
            else:
                self.memory[i - d] = self.memory[i]

        for i in range(len(self.memory) - d, len(self.memory)):
            self.memory[i] = 0


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    t, m = map(int, data[0].split())
    memory_manager = MemoryManager(m)

    for i in range(1, t + 1):
        command = data[i].split()
        if command[0] == "alloc":
            n = int(command[1])
            memory_manager.alloc(n)
        elif command[0] == "erase":
            x = int(command[1])
            memory_manager.erase(x)
        elif command[0] == "defragment":
            memory_manager.defragment()
        else:
            print("h")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
