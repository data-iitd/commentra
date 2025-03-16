import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

def solve():
    t = scan.next_int()
    arr = [scan.next_int() for _ in range(t)]
    prev_winner = 0
    
    for i in range(len(arr)):
        if arr[i] == 1:
            if prev_winner == 0:
                prev_winner = 2
        
        if prev_winner == 2 or prev_winner == 0:
            if (arr[i] - 1) % 2 == 0:
                print(2)
                prev_winner = 2
            else:
                print(1)
                prev_winner = 1
        else:
            if (arr[i] - 1) % 2 == 0:
                print(1)
                prev_winner = 1
            else:
                print(2)
                prev_winner = 2

scan = FastReader()

if __name__ == "__main__":
    solve()

# <END-OF-CODE>
