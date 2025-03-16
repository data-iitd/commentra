
h, w, ka = map(int, input().split())  # Read the dimensions and the required number of '#' characters
mat = [list(input()) for i in range(h)]  # Read the matrix
ans = 0  # Initialize the answer counter

# Iterate over all possible combinations of rows and columns using a bitmask approach
for i in range(2 ** (h + w)):
    b = bin(i)[2:].zfill(h + w)  # Convert the current combination to a binary string
    rs = b[:h]  # Extract the binary representation for rows
    cs = b[h:]  # Extract the binary representation for columns
    ct = 0  # Initialize the count of '#' characters in the current combination

    # Count the number of '#' characters in the selected rows and columns
    for l in range(h):
        for k in range(w):
            if mat[l][k] == '#' and rs[l] == '0' and cs[k] == '0':
                ct += 1

    # If the count matches the required number of '#' characters, increment the answer counter
    if ct == ka:
        ans += 1

# Print the total number of valid combinations
print(ans)

