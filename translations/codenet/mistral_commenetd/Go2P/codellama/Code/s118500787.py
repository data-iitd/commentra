
# Package main is the entry point of the program
import sys

def main():
    # Initialize two empty strings S and T
    S, T = ReadString(), ReadString()

    # Initialize max as 0
    max = 0

    # Loop through all possible substrings of S with length equal to T
    for i in range(len(S) - len(T) + 1):
        # Initialize a counter c for the number of matching characters between S[i:i+len(T)] and T
        c = 0

        # Check character by character for matching characters
        for j in range(len(T)):
            # If current characters match, increment counter c
            if S[i + j] == T[j]:
                c += 1

        # If current substring has more matching characters than the current max, update max
        if max < c:
            max = c

    # Print the length of the shortest substring of S that matches T with all characters
    print(len(T) - max)

# Helper functions to read input from stdin
def ReadString():
    # Function to read input and store it in the provided interface
    return sys.stdin.readline().strip()

def ReadInt():
    # Function to read input and store it in the provided interface
    return int(sys.stdin.readline().strip())

def ReadInts(n):
    # Function to read n integers and return a slice
    return [int(x) for x in sys.stdin.readline().strip().split()]

# END-OF-CODE
