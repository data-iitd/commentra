def run_length(s):
    r = []  # Initialize a list to store the encoded blocks
    if len(s) == 0:
        return r  # Return an empty list if the input string is empty
    t = (s[0], 1)  # Initialize the first block as a tuple (character, length)
    for v in s[1:]:
        if t[0] == v:
            t = (t[0], t[1] + 1)  # Increment the length of the current block if the character is the same
        else:
            r.append(t)  # Append the current block to the result list
            t = (v, 1)  # Initialize a new block for the new character
    r.append(t)  # Append the last block to the result list
    return r

def max_value(a, b):
    return b if b > a else a

def main():
    N, K = map(int, input().split())  # Read the number of characters and the maximum allowed changes
    S = input().strip()  # Read the input string

    # Apply Run Length Encoding to the input string S
    blocks = run_length(S)

    # Initialize variables for the sliding window approach
    sum_length, zero_count, l = 0, 0, 0
    ans = 0
    for r in range(len(blocks)):
        sum_length += blocks[r][1]  # Add the length of the current block to the sum
        if blocks[r][0] == "0":
            zero_count += 1  # Increment the count of '0' blocks
        # Adjust the window size if the number of '0' blocks exceeds K
        while zero_count > K:
            sum_length -= blocks[l][1]  # Subtract the length of the block at the left of the window
            if blocks[l][0] == "0":
                zero_count -= 1  # Decrement the count of '0' blocks
            l += 1  # Move the left pointer to the right
        ans = max_value(ans, sum_length)  # Update the answer if the current window sum is greater
    print(ans)  # Print the final answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
