# Read input strings s and t from the user
s = input()
t = input()

# Define a function to count the number of differing characters between two strings
def check(a, b):
    # Initialize a counter for differences
    s = 0
    # Iterate over pairs of characters from both strings
    for i, j in zip(a, b):
        # Increment the counter if characters are different
        s += i != j
    # Return the total count of differing characters
    return s

# Initialize the answer with a large number (infinity)
ans = 10**6

# Iterate over all possible starting positions in string s
for i in range(len(s)):
    # Create a substring a starting from the current index i
    a = s[i:]
    # Check if the length of the substring a is at least as long as t
    if len(a) >= len(t):
        # Update the minimum number of differing characters found
        ans = min(ans, check(t, a[:len(t)]))

# Print the minimum number of differing characters found
print(ans)
