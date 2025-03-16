import sys

class Scanner:
    def __init__(self):
        self.sc = sys.stdin.read().split()  # Read all input and split by whitespace
        self.index = 0  # Initialize index for reading input

    def next_int(self):
        value = int(self.sc[self.index])  # Get the next integer
        self.index += 1  # Move to the next input
        return value

def run(input_stream, output_stream):
    sc = Scanner()  # Initialize a new Scanner

    N = sc.next_int()  # Read the first integer from input

    if N < 4:  # Check if N is less than 4
        print(0)  # Print 0 if N is less than 4
        return 0  # Return 0

    S = input_stream.read().strip()  # Read the string S from input
    nr, nb, ng = 0, 0, 0  # Initialize counters for red, blue, and green balls

    for c in S:  # Iterate through each character in the string S
        if c == 'R':
            nr += 1  # Increment the nr counter
        elif c == 'B':
            nb += 1  # Increment the nb counter
        elif c == 'G':
            ng += 1  # Increment the ng counter

    same = 0  # Initialize a counter for the number of same-colored groups of three balls

    for a in range(1, N):  # Iterate through each index a from 1 to N-1
        i = 0  # Initialize index i to 0
        j = 1 * a  # Initialize index j to a multiplied by 1
        k = 2 * a  # Initialize index k to a multiplied by 2

        while k < N:  # Iterate through each index k from a*2 to N-1
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:  # Check if the balls at indices i, j, and k have different colors
                same += 1  # If so, increment the same counter

            # Update indices
            i += 1
            j += 1
            k += 1

    tot = nr * nb * ng  # Calculate the total number of balls

    print(tot - same)  # Print the result, which is the total number of balls minus the number of same-colored groups of three balls

    return 0  # Return 0 to indicate successful execution

if __name__ == "__main__":
    run(sys.stdin, sys.stdout)  # Run the main function with standard input and output
