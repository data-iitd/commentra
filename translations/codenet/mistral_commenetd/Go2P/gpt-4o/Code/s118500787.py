# Importing required modules
import sys

def main():
    # Initialize two empty strings S and T
    S = read_string()
    T = read_string()

    # Initialize max as 0
    max_count = 0

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
        if max_count < c:
            max_count = c

    # Print the length of the shortest substring of S that matches T with all characters
    print(len(T) - max_count)

def read_string():
    # Function to read a string from stdin
    return sys.stdin.readline().strip()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
