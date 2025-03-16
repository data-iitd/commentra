# Read an integer input which represents the length of the string
N = int(input())

# Read the string input
S = input()

# Initialize the answer variable to count the number of distinct segments
ans = 1

# Set the temporary variable to the first character of the string
tmp = S[0]

# Iterate through each character in the string
for s in S:
    # Check if the current character is different from the last recorded character
    if s != tmp:
        # If it is different, increment the count of distinct segments
        ans += 1
        # Update the temporary variable to the current character
        tmp = s

# Print the total number of distinct segments found in the string
print(ans)
