# Read an integer input N from the user
N = int(input())

# Read two strings S and T from the user, separated by a space
S, T = input().split()

# Initialize an empty list to store the interleaved characters
char_lists = []

# Iterate over the characters in string S using their index
for i, char in enumerate(S):
    # Append the current character from S to the list
    char_lists.append(char)
    # Append the corresponding character from T to the list
    char_lists.append(T[i])

# Join the list of characters into a single string and print the result
print("".join(char_lists))
