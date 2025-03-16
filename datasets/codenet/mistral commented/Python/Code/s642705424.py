# Ask the user for the number of strings (N) and read it as an integer
N = int(input())

# Ask the user for a single string (S) and store it as a string
S = input()

# Initialize a variable x with a value of 1. This variable will be used to count the number of consecutive different characters in the string.
x = 1

# Iterate through the string S from the first index to the second last index
for i in range(N-1):
    # Check if the character at the current index is different from the character at the next index
    if S[i] != S[i+1]:
        # If they are different, increment the value of x by 1
        x += 1

# Print the final value of x, which represents the number of consecutive different characters in the string
print(x)
