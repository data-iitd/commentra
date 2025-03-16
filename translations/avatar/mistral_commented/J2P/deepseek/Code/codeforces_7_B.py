import sys

def main():
    t = int(input().strip())
    m = int(input().strip())
    memory = [0] * m
    alloc_idx = 0

    for _ in range(t):
        command = input().strip().split()
        if command[0] == "alloc":
            n = int(command[1])
            len_free = 0
            can_alloc = False
            for i in range(m):
                if memory[i] == 0:
                    len_free += 1
                else:
                    len_free = 0
                if len_free == n:
                    can_alloc = True
                    len_free = i - n + 1
                    break
            if can_alloc:
                alloc_idx += 1
                for i in range(len_free, len_free + n):
                    memory[i] = alloc_idx
                print(alloc_idx)
            else:
                print("NULL")
        elif command[0] == "erase":
            x = int(command[1])
            if x <= 0:
                print("ILLEGAL_ERASE_ARGUMENT")
                continue
            has_erased = False
            for i in range(m):
                if memory[i] == x:
                    memory[i] = 0
                    has_erased = True
            if not has_erased:
                print("ILLEGAL_ERASE_ARGUMENT")
        elif command[0] == "defragment":
            len_free = 0
            for i in range(m):
                if memory[i] == 0:
                    len_free += 1
            new_size = m - len_free
            new_memory = [0] * new_size
            k = 0
            for i in range(m):
                if memory[i] != 0:
                    new_memory[k] = memory[i]
                    k += 1
            memory = new_memory
        else:
            print("h")

if __name__ == "__main__":
    main()

