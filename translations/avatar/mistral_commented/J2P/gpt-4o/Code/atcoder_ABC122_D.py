import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.N = int(sys.stdin.readline().strip())  # Reading the number of test cases
        self.MOD = 1000000007
        self.TOKENS = ["A", "C", "G", "T"]
        self.memo = [defaultdict(int) for _ in range(self.N + 1)]  # Initializing a list of dictionaries for memoization

    def calc(self):
        return self.dfs(0, "TTT")  # Calling the recursive function to calculate the result

    def isOK(self, last4):
        if "AGC" in last4:  # If the sequence contains "AGC", it's invalid
            return False

        for i in range(3):  # Checking all possible pairs of adjacent nucleotides
            vals = list(last4)
            vals[i], vals[i + 1] = vals[i + 1], vals[i]  # Swapping adjacent nucleotides
            s = ''.join(vals)  # Creating a new string from the pair

            if "AGC" in s:  # If the pair contains "AGC", it's invalid
                return False

        return True  # If no invalid sequence is found, the last 4 nucleotides are valid

    def dfs(self, current, last3):
        if last3 in self.memo[current]:  # If the result for the current sub-sequence and last 3 nucleotides is already calculated
            return self.memo[current][last3]

        if current == self.N:  # If we reach the end of the sequence, the result is 1
            return 1

        result = 0  # Initializing the result to 0

        for c in self.TOKENS:  # Iterating through all possible next nucleotides
            if self.isOK(last3 + c):  # If the next nucleotide and the current sequence form a valid sequence
                result = (result + self.dfs(current + 1, last3[1:] + c)) % self.MOD  # Recursively calculating the result for the next sub-sequence

        self.memo[current][last3] = result  # Storing the result for the current sub-sequence and last 3 nucleotides
        return result  # Returning the result

if __name__ == "__main__":
    ins = Main()  # Creating an instance of the Main class
    print(ins.calc())  # Printing the result
# <END-OF-CODE>
