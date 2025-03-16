# Read an integer input N, which represents the length of the string
N = int(input())

# Read a string input S
S = input()

# Initialize a counter x to 1, as there is at least one segment
x = 1

# Iterate through the string from the first character to the second last character
for i in range(N - 1):
    # Check if the current character is different from the next character
    if S[i] != S[i + 1]:
        # If they are different, increment the segment counter x
        x = x + 1

# Print the total number of segments found in the string
print(x)
