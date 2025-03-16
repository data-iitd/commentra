import sys

class Main:
    # Number of characters to generate
    N = 0
    # Modulus value for large number calculations
    MOD = 1000000007L
    # Possible tokens (characters) to use
    TOKENS = ["A", "C", "G", "T"]
    # Memoization array to store computed results
    memo = []

    # Constructor to initialize the class
    def __init__(self):
        # Create a scanner to read input
        in_ = sys.stdin
        # Read the number of characters to generate
        self.N = int(in_.readline())
        # Close the scanner
        in_.close()
        # Initialize the memoization array
        self.memo = [{} for i in range(self.N + 1)]

    # Method to calculate the total valid sequences
    def calc(self):
        # Start the depth-first search with the initial state
        return self.dfs(0, "TTT")

    # Method to check if the last 4 characters are valid
    def isOK(self, last4):
        # Check if the last 4 characters contain "AGC"
        if "AGC" in last4:
            return False
        # Check all permutations of the last 4 characters
        for i in range(3):
            vals = list(last4)
            # Swap characters to create a new permutation
            vals[i], vals[i + 1] = vals[i + 1], vals[i]
            s = "".join(vals)
            # Check if the new permutation contains "AGC"
            if "AGC" in s:
                return False
        # If no invalid sequences found, return true
        return True

    # Depth-first search method to explore all possible sequences
    def dfs(self, current, last3):
        # Check if the result is already computed and stored in memo
        if last3 in self.memo[current]:
            return self.memo[current][last3]
        # Base case: if the current length equals N, return 1 (valid sequence)
        if current == self.N:
            return 1
        # Variable to accumulate the result
        result = 0
        # Iterate through each possible token
        for c in self.TOKENS:
            # Check if adding the token to the last 3 characters is valid
            if self.isOK(last3 + c):
                # Recursively call dfs for the next character
                result = (result + self.dfs(current + 1, last3[1:] + c)) % self.MOD
        # Store the computed result in memoization array
        self.memo[current][last3] = result
        return result

    # Main method to execute the program
    def main(self):
        # Create an instance of Main class
        ins = Main()
        # Print the result of the calculation
        print(ins.calc())

# 