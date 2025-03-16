
def main():
    # Read input values for N (length of the string) and K (maximum number of '0's allowed)
    N, K = map(int, input().split())

    # Read the input string S
    S = input()

    # Generate run-length encoded blocks from the input string S
    blocks = run_length(S)

    # Initialize variables for the sliding window approach
    sum, zero, l = 0, 0, 0

    # Iterate through the blocks to find the maximum length of segments with at most K '0's
    for r in range(len(blocks)):
        sum += blocks[r].len  # Add the length of the current block to the sum

        # Count the number of '0' blocks encountered
        if blocks[r].value == '0':
            zero += 1

        # If the count of '0' blocks exceeds K, shrink the window from the left
        while K < zero:
            sum -= blocks[l].len  # Subtract the length of the leftmost block from the sum
            if blocks[l].value == '0':
                zero -= 1  # Decrease the count of '0' blocks
            l += 1  # Move the left pointer to the right

    # Print the maximum length of segments with at most K '0's
    print(sum)

# RunLength performs run-length encoding on the input string s and returns a list of Block
def run_length(s):
    r = []  # List to hold the resulting blocks
    if len(s) == 0:
        return r  # Return empty list if input string is empty

    # Initialize the first block with the first character of the string
    t = Block(s[0], 1)
    for v in s[1:]:
        # If the current character matches the block's value, increase the length
        if t.value == v:
            t.len += 1
        else:
            # Otherwise, append the current block to the result and start a new block
            r.append(t)
            t = Block(v, 1)
    # Append the last block to the result
    r.append(t)
    return r  # Return the list of blocks

# Block represents a contiguous segment of characters with a specific value and length
class Block:
    def __init__(self, value, len):
        self.value = value  # The character value of the block
        self.len = len  # The length of the block

# Main function to execute the program
if __name__ == "__main__":
    main()

