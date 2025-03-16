#######
# Code
#######

# Get the number of strings (N) and the string (S) as input from the user
N = int(input())  # Get the number of strings
S = input()      # Get the string

# Initialize answer variable with a value of 1 and the first character of the string as the temporary character
ans = 1
tmp = S[0]

# Iterate through each character in the string
for s in S:
    # If the current character is different from the temporary character, increment the answer variable and update the temporary character
    if s != tmp:
        ans += 1
        tmp = s

# Print the final answer
print(ans)
