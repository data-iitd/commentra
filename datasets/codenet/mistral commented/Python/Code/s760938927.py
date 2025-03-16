#######
# Code
#######

# Read input: height, width, and number of 'X's in the minefield
h, w, ka = map(int, input().split())

# Initialize 2D matrix to store the minefield
mat = [list(input()) for i in range(h)]

# Initialize answer variable to 0
ans = 0

# Loop through all possible binary combinations of size h+w
for i in range(2 ** (h + w)):

    # Convert the binary number to a string and zero-pad it to the left
    # to match the size of h+w
    b = bin(i)[2:].zfill(h + w)

    # Extract the first h bits as row indices and the remaining w bits as column indices
    rs = b[:h]
    cs = b[h:]

    # Initialize a counter to keep track of the number of 'X's in the current configuration
    ct = 0

    # Loop through each row and column in the minefield
    for l in range(h):
        for k in range(w):

            # If the current cell is an 'X' and the corresponding row and column indices
            # in the binary string are both 0, increment the counter
            if mat[l][k] == '#' and rs[l] == '0' and cs[k] == '0':
                ct += 1

    # If the counter equals the number of 'X's in the minefield, increment the answer
    if ct == ka:
        ans += 1

# Print the final answer
print(ans)
