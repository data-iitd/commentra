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

def main():
    reader = FastReader()
    n = reader.next_int()
    m = reader.next_int()
    
    banned_rows = set()
    banned_cols = set()
    
    for _ in range(m):
        r = reader.next_int()
        if 1 < r < n:
            banned_rows.add(r)
        c = reader.next_int()
        if 1 < c < n:
            banned_cols.add(c)
    
    answer = (n - 2) * 2
    answer -= len(banned_rows)
    answer -= len(banned_cols)
    
    if n % 2 != 0:
        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            answer -= 1
    
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
