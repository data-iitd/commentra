# Importing required packages
import sys

# Define a custom class 'Block'
class Block:
    def __init__(self, value, length):
        self.value = value
        self.length = length

# Main function starts the execution
def main():
    # Read input values for N and K from the standard input
    N, K = map(int, sys.stdin.readline().strip().split())

    # Read the input string S from the standard input
    S = sys.stdin.readline().strip()

    # Call the run_length function to get the run-length encoded blocks
    blocks = run_length(S)

    # Initialize variables sum, zero and length l
    sum_ = 0
    zero = 0
    l = 0
    ans = 0

    # Loop through all the blocks in the blocks list
    for r in range(len(blocks)):
        # Increment the sum by the length of the current block
        sum_ += blocks[r].length

        # If the current block's value is '0', increment the zero counter
        if blocks[r].value == "0":
            zero += 1

        # While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
        while zero > K:
            sum_ -= blocks[l].length
            if blocks[l].value == "0":
                zero -= 1
            l += 1

        # Update the answer with the maximum of the current answer and the sum
        ans = max(ans, sum_)

    # Print the final answer
    print(ans)

# RunLength function to get the run-length encoded blocks
def run_length(s):
    # If the length of the input string is zero, return an empty list
    if len(s) == 0:
        return []

    # Initialize the first block with the first character and length one
    t = Block(s[0], 1)

    # Initialize an empty list to store the blocks
    r = []

    # Loop through all the characters in the input string starting from the second character
    for v in s[1:]:
        # If the current character is the same as the previous character, increment the length of the current block
        if t.value == v:
            t.length += 1
        else:
            # Add the previous block to the result list
            r.append(t)

            # Initialize a new block with the current character and length one
            t = Block(v, 1)

    # Add the last block to the result list
    r.append(t)

    # Return the result list
    return r

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
