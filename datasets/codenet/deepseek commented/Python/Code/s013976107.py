
A,B = map(int,input().split())  # Read two integers A and B from standard input
S = list(input())               # Read a single string S from standard input

# Check if the character at position A is a hyphen and if there is exactly one hyphen in the string S
if S[A] == '-' and S.count('-') == 1:
    print("Yes")                 # Print "Yes" if the conditions are met
else:
    print("No")                  # Print "No" otherwise

