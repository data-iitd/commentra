
# Read two strings S and T from standard input
S, T = input(), input()

# Initialize a variable to keep track of the maximum number of matching characters
max = 0

# Iterate over each possible starting index in S where T can fit
for i in range(len(S) - len(T) + 1):
    # Initialize a counter for matching characters
    c = 0

    # Compare characters of T with the corresponding characters in S
    for j in range(len(T)):
        if S[i + j] == T[j]:
            c += 1 # Increment the counter for each matching character

    # Update the maximum count of matching characters if the current count is greater
    if max < c:
        max = c

# Output the number of characters in T that do not match with S
print(len(T) - max)

