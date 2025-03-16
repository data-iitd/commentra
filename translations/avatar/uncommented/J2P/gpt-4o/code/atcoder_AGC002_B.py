class Box:
    def __init__(self, n, r):
        self.num = n
        self.red = r

    def move_to(self, other):
        if self.num == 0:
            return
        elif self.num == 1:
            self.num = 0
            other.num += 1
            if self.red:
                other.red = True
            self.red = False
        else:
            self.num -= 1
            other.num += 1
            if self.red:
                other.red = True

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    M = int(data[1])
    
    B = [None] * N
    B[0] = Box(1, True)
    
    for i in range(1, N):
        B[i] = Box(1, False)
    
    index = 2  # Starting index for moves in the input data
    for _ in range(M):
        x = int(data[index]) - 1
        y = int(data[index + 1]) - 1
        B[x].move_to(B[y])
        index += 2
    
    counter = sum(1 for b in B if b.red)
    print(counter)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
