
import sys

# Global variables to store counts and the result
a = []  # Slice to hold counts of specific characters
ans = 0  # Variable to hold the final answer

# Depth-first search function to calculate combinations
def dfs(left, i, res):
    global ans
    # If no more characters left to choose, add the result to ans
    if left == 0:
        ans += res
        return
    # Iterate through the slice starting from index i
    for j in range(i, len(a)):
        # Recursive call to dfs with one less character to choose
        dfs(left-1, j+1, res*a[j])

def main():
    # Initialize input reader
    io = IO()
    # Read the number of characters
    n = io.nextInt()
    # Map to count occurrences of specific characters
    dic = {}

    # Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
    for _ in range(n):
        c = io.nextString()[0]  # Read the first character of the string
        if c in dic:
            dic[c] += 1  # Increment count for the character if it's one of the specified
        else:
            dic[c] = 1

    # Populate the slice a with the counts from the dictionary
    for _, v in dic.items():
        a.append(v)

    # Start the DFS to calculate the product of combinations of 3 characters
    dfs(3, 0, 1)
    # Print the final result
    print(ans)

# Struct to handle input operations
class IO:
    def __init__(self):
        self.tokens = []  # Slice to hold split input tokens
        self.nextToken = 0  # Index for the next token to read

    def nextLine(self):
        line = sys.stdin.readline().strip()  # Read a line from input
        self.tokens = line.split()  # Split the line into tokens
        self.nextToken = 0  # Reset the token index
        return line  # Return the complete line as a string

    def nextString(self):
        # Load more tokens if the current index exceeds the available tokens
        while self.nextToken >= len(self.tokens):
            self.nextLine()  # Read the next line
        r = self.tokens[self.nextToken]  # Get the next token
        self.nextToken += 1  # Move to the next token
        return r  # Return the token

    def nextInt(self):
        return int(self.nextString())  # Convert the next string token to an integer

if __name__ == "__main__":
    main()

