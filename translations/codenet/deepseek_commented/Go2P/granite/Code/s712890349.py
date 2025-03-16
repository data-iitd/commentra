

import sys

# Block represents a run-length encoded block of characters
class Block:
    def __init__(self, value, length):
        self.value = value
        self.length = length

def main():
    N, K = map(int, input().split())  # Read the number of characters and the maximum allowed changes from the standard input
    S = input()  # Read the input string from the standard input

    # Apply Run Length Encoding to the input string S
    blocks = run_length_encoding(S)

    # Initialize variables for the sliding window approach
    sum, zero, l = 0, 0, 0
    for r in range(len(blocks)):
        sum += blocks[r].length  # Add the length of the current block to the sum
        if blocks[r].value == "0":
            zero += 1  # Increment the count of '0' blocks
        # Adjust the window size if the number of '0' blocks exceeds K
        while K < zero:
            sum -= blocks[l].length  # Subtract the length of the block at the left of the window
            if blocks[l].value == "0":
                zero -= 1  # Decrement the count of '0' blocks
            l += 1  # Move the left pointer to the right
    print(sum)  # Print the final answer

# RunLength performs run-length encoding on the input string
def run_length_encoding(s):
    r = []  # Initialize an empty list to store the encoded blocks
    if len(s) == 0:
        return r  # Return an empty list if the input string is empty
    t = Block(s[0], 1)  # Initialize the first block
    for v in s[1:]:
        if t.value == v:
            t.length += 1  # Increment the length of the current block if the character is the same
        else:
            r.append(t)  # Append the current block to the result list
            t = Block(v, 1)  # Initialize a new block for the new character
    r.append(t)  # Append the last block to the result list
    return r

if __name__ == "__main__":
    main()

