# Read the main string from user input
s = input()

# Read the number of subsequent strings to process
n = int(input())

# Initialize the answer variable to accumulate results
ans = 0

# Loop through each of the n strings provided by the user
for i in range(n):
    # Read the current string
    x = input()
    
    # Initialize counters for characters matching the first and second characters of x
    a, b = 0, 0
    
    # Loop through each character in the main string s
    for j in s:
        # If the character matches the first character of x, increment counter a
        if j == x[0]:
            a += 1
        # If the character matches the second character of x, increment counter b
        elif j == x[1]:
            b += 1
        else:
            # If a character does not match either, add the minimum of a and b to ans
            ans = ans + min(a, b)
            # Reset counters a and b for the next segment
            a, b = 0, 0
    
    # After finishing the loop, add the minimum of a and b to ans for the last segment
    ans = ans + min(a, b)

# Print the final accumulated answer
print(ans)
