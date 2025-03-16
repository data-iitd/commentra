
# FastReader class to read input efficiently
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
        self.idx = 0
        self.val = input()
        return self.val

# Main function
if __name__ == '__main__':
    # Read the dimensions of the grid
    n = FastReader().nextInt()
    # Read the number of banned cells
    m = FastReader().nextInt()

    # Initialize sets to keep track of banned rows and columns
    bannedRows = set()
    bannedCols = set()

    # Read each banned cell and add it to the appropriate set if it's not on the border
    for i in range(m):
        r = FastReader().nextInt()
        if r > 1 and r < n:
            bannedRows.add(r)
        c = FastReader().nextInt()
        if c > 1 and c < n:
            bannedCols.add(c)

    # Calculate the number of cells that can be reached, accounting for banned rows and columns
    answer = (n - 2) * 2
    answer -= len(bannedRows)
    answer -= len(bannedCols)

    # Adjust the answer if the grid size is odd and the center cell is not banned
    if n % 2!= 0:
        mid = (n + 1) // 2
        if mid not in bannedRows and mid not in bannedCols:
            answer -= 1

    # Output the final answer
    print(answer)

