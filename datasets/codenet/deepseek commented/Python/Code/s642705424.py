
N = int(input())  # Read an integer N from the user input
S = input()       # Read a string S from the user input
x = 1             # Initialize a variable x to 1

# Loop through the string S from the first character to the N-1th character
for i in range(N-1):
    if S[i] != S[i+1]:  # Check if the current character is not equal to the next character
        x = x + 1       # If true, increment x by 1

print(x)  # Print the final value of x


