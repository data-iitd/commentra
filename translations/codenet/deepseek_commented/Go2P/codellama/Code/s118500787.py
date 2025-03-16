
# Read the two strings S and T from standard input
S, T = input(), input()

# Initialize the maximum number of matching characters to 0
max = 0

# Iterate over the possible starting positions of the substring of S that is the same length as T
for i in range(len(S) - len(T) + 1):
    # Initialize a counter for the number of matching characters in the current substring
    c = 0
    
    # Check each character in the current substring against the corresponding character in T
    for j in range(len(T)):
        if S[i + j] == T[j]:
            # Increment the counter if the characters match
            c += 1
    
    # Update max if the current count of matching characters is greater than the previous max
    if max < c:
        max = c

# Print the number of characters that need to be changed to make S contain T as a substring
print(len(T) - max)

