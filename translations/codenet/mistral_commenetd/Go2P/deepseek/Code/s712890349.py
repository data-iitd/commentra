# Importing required packages
import sys

# Define a custom type 'Block'
class Block:
    def __init__(self, value, length):
        self.value = value
        self.length = length

# Main function starts the execution
def main():
    # Initialize variables
    N, K, ans = 0, 0, 0

    # Read input values for N and K from the standard input
    N, K = map(int, sys.stdin.readline().split())

    # Read the input string S from the standard input
    S = sys.stdin.readline().strip()

    # Call the RunLength function to get the run-length encoded blocks
    blocks = RunLength(S)

    # Initialize variables sum, zero and length l
    sum_val, zero, l = 0, 0, 0

    # Loop through all the blocks in the blocks slice
    for r in range(len(blocks)):
        # Increment the sum by the length of the current block
        sum_val += blocks[r].length

        # If the current block's value is '0', increment the zero counter
        if blocks[r].value == '0':
            zero += 1

        # While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
        while K < zero:
            sum_val -= blocks[l].length
            if blocks[l].value == '0':
                zero -= 1
            l += 1

        # Update the answer with the maximum of the current answer and the sum
        ans = max(ans, sum_val)

    # Print the final answer
    print(ans)

# RunLength function to get the run-length encoded blocks
def RunLength(s):
    # If the length of the input string is zero, return an empty list
    if len(s) == 0:
        return []

    # Initialize the first block with the first character and length one
    t = Block(s[0], 1)

    # Initialize an empty list to store the blocks
    r = []

    # Loop through all the characters in the input string starting from the second character
    for i in range(1, len(s)):
        # If the current character is the same as the previous character, increment the length of the current block
        if t.value == s[i]:
            t.length += 1
        else:
            # Add the previous block to the result list
            r.append(t)

            # Initialize a new block with the current character and length one
            t = Block(s[i], 1)

    # Add the last block to the result list
    r.append(t)

    # Return the result list
    return r

# Max function to find the maximum of two integers
def max(a, b):
    # If b is greater than a, return b, otherwise return a
    return b if b > a else a

# End of the code
