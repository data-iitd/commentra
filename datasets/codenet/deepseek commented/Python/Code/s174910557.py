
N = int(input())  # Read an integer N from the user
S = input()       # Read a string S from the user

ans = 1           # Initialize the answer variable to 1
tmp = S[0]        # Set the first character of S to tmp

# Iterate over each character in S
for s in S:
    if s != tmp:  # If the current character is different from tmp
        ans += 1  # Increment the answer variable
        tmp = s   # Update tmp to the current character

print(ans)         # Print the final value of ans


