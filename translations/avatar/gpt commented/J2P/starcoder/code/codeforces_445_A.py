
# <START-OF-CODE>

# Create a BufferedReader to read input from the console
buf = open(0)

# Read the first line of input and split it into an array of strings
inp = buf.readline().split()

# Parse the first two elements of the input array as integers n and m
n = int(inp[0])
m = int(inp[1])

# Initialize an array to hold the resulting strings
ans = []

# Loop through each of the n lines of input
for i in range(n):
    # Read the current line of input
    str = buf.readline()

    # Create a StringBuilder to construct the output for the current line
    temp = ""

    # Loop through each character in the current line
    for j in range(m):
        # Check if the character is a '-'
        if str[j] == '-':
            # Append '-' to the StringBuilder if it is
            temp += '-'
        else:
            # If the character is not '-', determine whether to append 'W' or 'B'
            if ((i + j) % 2 == 1):
                temp += 'W'  # Append 'W' for odd indices
            else:
                temp += 'B'  # Append 'B' for even indices

    # Store the constructed string in the ans array
    ans.append(temp)

# Output the resulting strings line by line
for i in range(n):
    print(ans[i])

# 