import sys

def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        command = sys.stdin.readline().split()
        if command[0] == "alloc":
            n = int(command[1])
            memory = [0] * m
            for i in range(m):
                if memory[i] == 0:
                    memory[i] = i + 1
                    print(i + 1)
                    break
        elif command[0] == "erase":
            x = int(command[1])
            if x <= 0:
                print("ILLEGAL_ERASE_ARGUMENT")
            else:
                for i in range(m):
                    if memory[i] == x:
                        memory[i] = 0
                        break
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
    m = int(sys.stdin.readline())
    main()

