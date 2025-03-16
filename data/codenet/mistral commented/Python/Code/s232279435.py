
# Read input from user
n = int(input())
# Number of substrings in the given string

s = str(input())
# Given string

ans = 0
# Initialize answer variable

for i in range(n):
    # Iterate through each substring ending at index i

    x = set(s[:i+1])
    # Create a set of characters in the substring from 0 to i

    y = set(s[i+1:])
    # Create a set of characters in the substring from i+1 to the end of the string

    z = 0
    # Initialize counter variable

    for w in x:
        # Iterate through each character in the first set

        if w in y:
            # If the character is present in both sets, increment counter
            z +=1

    if z > ans:
        # If the counter is greater than the current answer, update answer
        ans = z
# Print the answer
print(ans)