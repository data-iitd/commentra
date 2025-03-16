from collections import deque

# Block represents a run-length encoded block of characters
class Block:
    def __init__(self, value, length):
        self.value = value
        self.length = length

def main():
    # Read the number of characters and the maximum allowed changes from the standard input
    N, K = map(int, input().split())
    # Read the input string from the standard input
    S = input()

    # Apply Run Length Encoding to the input string S
    blocks = RunLength(S)

    # Initialize variables for the sliding window approach
    sum_blocks = 0
    zero_count = 0
    l = 0
    ans = 0

    for r in range(len(blocks)):
        sum_blocks += blocks[r].length  # Add the length of the current block to the sum
        if blocks[r].value == '0':
            zero_count += 1  # Increment the count of '0' blocks

        # Adjust the window size if the number of '0' blocks exceeds K
        while zero_count > K:
            sum_blocks -= blocks[l].length  # Subtract the length of the block at the left of the window
            if blocks[l].value == '0':
                zero_count -= 1  # Decrement the count of '0' blocks
            l += 1  # Move the left pointer to the right

        ans = max(ans, sum_blocks)  # Update the answer if the current window sum is greater

    print(ans)  # Print the final answer

def RunLength(s):
    r = []  # Initialize a list to store the encoded blocks
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

# Max returns the maximum of two integers
def max(a, b):
    if b > a:
        return b
    return a

# Call the main function
main()

