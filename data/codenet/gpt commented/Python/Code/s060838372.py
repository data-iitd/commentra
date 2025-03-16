# Read two integers N and K from input, where N is the length of the string and K is the position to modify
N, K = map(int, input().split())

# Read the string S from input
S = list(input())

# Check the character at the (K-1)th position in the string
if S[K-1] == "A":
    # If the character is 'A', change it to 'a'
    S[K-1] = "a"
elif S[K-1] == "B":
    # If the character is 'B', change it to 'b'
    S[K-1] = "b"
else:
    # If the character is neither 'A' nor 'B', change it to 'c'
    S[K-1] = "c"

# Join the modified list back into a string
ans = "".join(S)

# Print the resulting string
print(ans)
