# Read the dimensions of the matrix (height and width) and the target count of '#' characters (ka)
h, w, ka = map(int, input().split())

# Read the matrix input, where each row is a list of characters
mat = [list(input()) for i in range(h)]

# Initialize the answer counter to zero
ans = 0

# Iterate over all possible combinations of row and column selections (2^(h+w) combinations)
for i in range(2**(h + w)):
    # Convert the current index to a binary string, padded with zeros to match the length of h + w
    b = bin(i)[2:].zfill(h + w)
    
    # Split the binary string into row selections (rs) and column selections (cs)
    rs = b[:h]  # Row selections
    cs = b[h:]  # Column selections
    
    # Initialize a counter for the number of '#' characters that meet the selection criteria
    ct = 0
    
    # Iterate through each cell in the matrix
    for l in range(h):
        for k in range(w):
            # Check if the current cell is '#' and both the corresponding row and column are not selected
            if mat[l][k] == '#' and rs[l] == '0' and cs[k] == '0':
                ct += 1  # Increment the counter if the conditions are met
    
    # If the count of selected '#' characters matches the target count (ka), increment the answer
    if ct == ka:
        ans += 1

# Print the final count of valid configurations
print(ans)
