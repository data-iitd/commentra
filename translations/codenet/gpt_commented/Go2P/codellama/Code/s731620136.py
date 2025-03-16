
# +build ignore
import sys

# Scanner struct for handling input
class Scanner:
    sc = sys.stdin

    # nextStr reads the next string from input
    def nextStr(self):
        return self.sc.readline().strip()

    # nextInt reads the next integer from input
    def nextInt(self):
        return int(self.nextStr())

    # nextFloat reads the next float from input
    def nextFloat(self):
        return float(self.nextStr())

    # nextRuneSlice reads the next string and converts it to a byte slice
    def nextRuneSlice(self):
        return bytes(self.nextStr(), encoding="utf-8")

    # nextIntSlice reads a slice of integers from input
    def nextIntSlice(self, n):
        return [self.nextInt() for i in range(n)]

    # nextFloatSlice reads a slice of floats from input
    def nextFloatSlice(self, n):
        return [self.nextFloat() for i in range(n)]

# run processes the input and produces output
def run(input, output):
    sc = Scanner() # Create a new scanner instance
    N = sc.nextInt() # Read the number of elements
    S = sc.nextStr() # Read the string of colors

    # Handle case where there are no elements
    if N == 0:
        return 0

    # If there are fewer than 4 elements, output 0
    if N < 4:
        print(0)
        return 0

    # Count occurrences of each color
    nr, nb, ng = 0, 0, 0
    for c in S:
        if c == 'R':
            nr += 1
        if c == 'B':
            nb += 1
        if c == 'G':
            ng += 1

    same = 0 # Counter for same color combinations

    # Iterate through possible combinations of indices
    for a in range(1, N):
        i = 0
        j = 1 * a
        k = 2 * a
        if k >= N:
            break # Exit if index exceeds string length
        while k < N:
            # Check if the colors at the indices are different
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
                same += 1 # Increment same color combination counter
            i += 1 # Move to the next index
            j += 1
            k += 1

    # Calculate total combinations of different colors
    tot = nr * nb * ng

    # Output the result by subtracting same combinations from total
    print(tot - same)

    return 0 # Return success

# main function to execute the program
def main():
    os.exit(run(sys.stdin, sys.stdout)) # Run the program and exit

