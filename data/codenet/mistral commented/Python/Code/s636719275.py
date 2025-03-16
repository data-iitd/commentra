# Take two strings as input
s = input()
t = input()

# Define a helper function to check the edit distance between two strings
def check(a, b):
    # Initialize a variable to keep track of the edit distance
    s = 0
    
    # Iterate through the corresponding characters of a and b
    for i, j in zip(a, b):
        # Increment the edit distance if the characters are not equal
        s += i != j
        
    # Return the edit distance
    return s

# Initialize a variable to keep track of the minimum edit distance
ans = 10**6

# Iterate through each character in the string s
for i in range(len(s)):
    # Extract a substring from s starting from the current index
    a = s[i:]
    
    # Check if the length of the substring is greater than or equal to the length of t
    if len(a) >= len(t):
        # Call the check function with t and the first len(t) characters of a
        # and update the minimum edit distance if necessary
        ans = min(ans, check(t, a[:len(t)]))

# Print the minimum edit distance
print(ans)
