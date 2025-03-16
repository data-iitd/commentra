
import sys

class Main:
    def __init__(self):
        self.memory = []
        self.allocIdx = 0

    def main(self):
        t = int(sys.stdin.readline())
        m = int(sys.stdin.readline())
        for j in range(t):
            command = sys.stdin.readline().split()
            if command[0] == "alloc":
                n = int(command[1])
                len = 0
                canAlloc = False
                for i in range(m):
                    if self.memory[i] == 0:
                        len += 1
                    else:
                        len = 0
                    if len == n:
                        canAlloc = True
                        len = i - n + 1
                        break
                if canAlloc:
                    self.allocIdx += 1
                    for i in range(len, len + n):
                        self.memory[i] = self.allocIdx
                    print(self.allocIdx)
                else:
                    print("NULL")
            elif command[0] == "erase":
                x = int(command[1])
                if x <= 0:
                    print("ILLEGAL_ERASE_ARGUMENT")
                    break
                hasErased = False
                for i in range(m):
                    if self.memory[i] == x:
                        self.memory[i] = 0
                        hasErased = True
                if not hasErased:
                    print("ILLEGAL_ERASE_ARGUMENT")
            elif command[0] == "defragment":
                d = 0
                for i in range(m):
                    if self.memory[i] == 0:
                        d += 1
                newSize = m - d
                newMemory = [0] * newSize
                k = 0
                for i in range(m):
                    if self.memory[i]!= 0:
                        newMemory[k] = self.memory[i]
                        k += 1
                self.memory = newMemory
            else:
                print("h")

if __name__ == "__main__":
    obj = Main()
    obj.main()

