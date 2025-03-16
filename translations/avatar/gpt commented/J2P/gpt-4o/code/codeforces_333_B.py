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
    # FastReader for efficient input reading
    in_reader = FastReader()
    
    # Read the dimensions of the grid
    n = in_reader.next_int()
    m = in_reader.next_int()
    
    # Initialize sets to keep track of banned rows and columns
    banned_rows = set()
    banned_cols = set()
    
    # Read the banned rows and columns
    for _ in range(m):
        r = in_reader.next_int()
        # Add to banned_rows if the row is within valid range
        if 1 < r < n:
            banned_rows.add(r)
        c = in_reader.next_int()
        # Add to banned_cols if the column is within valid range
        if 1 < c < n:
            banned_cols.add(c)
    
    # Calculate the initial answer based on the grid size
    answer = (n - 2) * 2
    # Subtract the number of banned rows and columns from the answer
    answer -= len(banned_rows)
    answer -= len(banned_cols)
    
    # If n is odd, check the middle row and column
    if n % 2 != 0:
        mid = (n + 1) // 2
        # If the middle row and column are not banned, decrement the answer
        if mid not in banned_rows and mid not in banned_cols:
            answer -= 1
    
    # Output the final answer
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
