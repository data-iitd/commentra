import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        result = self.data[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next())

def main():
    # Read the dimensions of the grid
    n = FastReader().next_int()
    # Read the number of banned cells
    m = FastReader().next_int()

    # Initialize sets to keep track of banned rows and columns
    banned_rows = set()
    banned_cols = set()

    # Read each banned cell and add it to the appropriate set if it's not on the border
    for _ in range(m):
        r = FastReader().next_int()
        if 1 < r < n:
            banned_rows.add(r)
        c = FastReader().next_int()
        if 1 < c < n:
            banned_cols.add(c)

    # Calculate the number of cells that can be reached, accounting for banned rows and columns
    answer = (n - 2) * 2
    answer -= len(banned_rows)
    answer -= len(banned_cols)

    # Adjust the answer if the grid size is odd and the center cell is not banned
    if n % 2 != 0:
        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            answer -= 1

    # Output the final answer
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
