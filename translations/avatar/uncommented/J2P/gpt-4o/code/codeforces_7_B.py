class Main:
    def main():
        import sys
        input = sys.stdin.read
        data = input().splitlines()
        
        t = int(data[0])
        m = int(data[1])
        memory = [0] * m
        alloc_idx = 0
        
        for j in range(t):
            command = data[j + 2].split()
            if command[0] == "alloc":
                n = int(command[1])
                length = 0
                can_alloc = False
                for i in range(m):
                    if memory[i] == 0:
                        length += 1
                    else:
                        length = 0
                    if length == n:
                        can_alloc = True
                        start_index = i - n + 1
                        break
                if can_alloc:
                    alloc_idx += 1
                    for i in range(start_index, start_index + n):
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
                d = 0
                for i in range(m):
                    if memory[i] == 0:
                        d += 1
                    else:
                        memory[i - d] = memory[i]
                for i in range(m - d, m):
                    memory[i] = 0
            else:
                print("h")

    if __name__ == "__main__":
        main()

# <END-OF-CODE>
