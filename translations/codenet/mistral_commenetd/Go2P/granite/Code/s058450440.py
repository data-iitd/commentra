
import sys

# Importing necessary packages

a = []
ans = 0

# Defining global variables

def dfs(left, i, res):
    # Function to perform Depth First Search (DFS) algorithm

    global ans

    if left == 0:
        ans += res
        return

    for j in range(i, len(a)):
        dfs(left-1, j+1, res*a[j])

# Main function definition
if __name__ == "__main__":
    # Initializing an io object for input/output handling
    io = IO()

    # Reading the number of test cases
    n = io.nextInt()

    # Initializing an empty map to store the frequency of each character
    dic = {}

    # Reading strings and updating the map
    for _ in range(n):
        c = io.nextString()[0]
        if c in ['M', 'A', 'R', 'C', 'H']:
            dic[c] = dic.get(c, 0) + 1

    # Converting map values to integers and appending them to the 'a' slice
    for _, v in dic.items():
        a.append(v)

    # Calling the 'dfs' function with initial arguments
    dfs(3, 0, 1)

    # Printing the answer
    print(ans)

# Struct definition for input/output handling
class IO:
    def __init__(self):
        self.reader = sys.stdin
        self.tokens = []
        self.nextToken = 0

    # Function to read a line from the standard input
    def nextLine(self):
        line = self.reader.readline()
        return line

    # Function to read a token (a word) from the standard input
    def nextString(self):
        while self.nextToken >= len(self.tokens):
            line = self.nextLine()
            self.tokens = line.split()
            self.nextToken = 0
        r = self.tokens[self.nextToken]
        self.nextToken += 1
        return r

    # Function to convert a token (a string) to an integer
    def nextInt(self):
        return int(self.nextString())

# 

