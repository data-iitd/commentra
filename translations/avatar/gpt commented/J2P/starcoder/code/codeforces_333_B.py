
# FastReader for efficient input reading
class FastReader:
    def __init__(self):
        self.val = input()
        self.idx = 0

    def next(self):
        self.idx += 1
        return self.val[self.idx - 1]

    def nextInt(self):
        self.idx += 1
        return int(self.val[self.idx - 1])

    def nextLong(self):
        self.idx += 1
        return int(self.val[self.idx - 1])

    def nextDouble(self):
        self.idx += 1
        return float(self.val[self.idx - 1])

    def nextLine(self):
        self.idx += 1
        return self.val[self.idx - 1]

# Main function
if __name__ == '__main__':
    # Read the dimensions of the grid
    n = FastReader().nextInt()
    m = FastReader().nextInt()

    # Initialize sets to keep track of banned rows and columns
    bannedRows = set()
    bannedCols = set()

    # Read the banned rows and columns
    for i in range(m):
        r = FastReader().nextInt()
        # Add to bannedRows if the row is within valid range
        if r > 1 and r < n:
            bannedRows.add(r)
        c = FastReader().nextInt()
        # Add to bannedCols if the column is within valid range
        if c > 1 and c < n:
            bannedCols.add(c)

    # Calculate the initial answer based on the grid size
    answer = (n - 2) * 2
    # Subtract the number of banned rows and columns from the answer
    answer -= len(bannedRows)
    answer -= len(bannedCols)

    # If n is odd, check the middle row and column
    if n % 2!= 0:
        mid = (n + 1) // 2
        # If the middle row and column are not banned, decrement the answer
        if mid not in bannedRows and mid not in bannedCols:
            answer -= 1

    # Output the final answer
    print(answer)

