def run_length(s):
    """Perform run-length encoding on the input string s and return a list of blocks."""
    r = []  # List to hold the resulting blocks
    if len(s) == 0:
        return r  # Return empty list if input string is empty

    # Initialize the first block with the first character of the string
    t = (s[0], 1)
    for v in s[1:]:
        # If the current character matches the block's value, increase the length
        if t[0] == v:
            t = (t[0], t[1] + 1)
        else:
            # Otherwise, append the current block to the result and start a new block
            r.append(t)
            t = (v, 1)
    # Append the last block to the result
    r.append(t)
    return r  # Return the list of blocks


def max_length_with_k_zeros(N, K, S):
    """Find the maximum length of segments with at most K '0's."""
    blocks = run_length(S)  # Generate run-length encoded blocks from the input string S

    sum_length, zero_count, l = 0, 0, 0
    ans = 0

    # Iterate through the blocks to find the maximum length of segments with at most K '0's
    for r in range(len(blocks)):
        sum_length += blocks[r][1]  # Add the length of the current block to the sum

        # Count the number of '0' blocks encountered
        if blocks[r][0] == '0':
            zero_count += 1

        # If the count of '0' blocks exceeds K, shrink the window from the left
        while zero_count > K:
            sum_length -= blocks[l][1]  # Subtract the length of the leftmost block from the sum
            if blocks[l][0] == '0':
                zero_count -= 1  # Decrease the count of '0' blocks
            l += 1  # Move the left pointer to the right

        # Update the answer with the maximum sum found so far
        ans = max(ans, sum_length)

    return ans


if __name__ == "__main__":
    # Read input values for N (length of the string) and K (maximum number of '0's allowed)
    N, K = map(int, input().split())

    # Read the input string S
    S = input().strip()

    # Get the maximum length of segments with at most K '0's
    result = max_length_with_k_zeros(N, K, S)

    # Print the maximum length of segments with at most K '0's
    print(result)

# <END-OF-CODE>
