# Read the integer input which represents the length of the strings
n = int(input())

# Read the first string and convert it to a list of characters
s = list(input())

# Read the second string and convert it to a list of characters
t = list(input())

# Check if both strings are identical
if s == t:
    # If they are the same, print the length of the strings
    print(n)
else:
    # Initialize a counter to keep track of the matching characters
    cnt = 0
    
    # Iterate over each character in the first string
    for i in range(n):
        # For each character, check the subsequent characters in the second string
        for j in range(n - i):
            # If characters at the current position do not match, break the inner loop
            if s[i + j] != t[j]:
                break
            
            # If we have matched all characters from this starting point
            if j == n - i - 1:
                # Update the count of matching characters
                cnt = n - i
    
    # Print the result based on the number of matching characters found
    print(2 * n - cnt)
