
N = int(input())  # Take an integer input N, likely the number of iterations or the length of the strings S and T.
S, T = input().split()  # Take two space-separated strings S and T as input.

char_lists = []  # Initialize an empty list to store the combined characters.

for i, char in enumerate(S):  # Iterate over the characters in string S.
    char_lists.append(char)  # Append the current character from S to char_lists.
    char_lists.append(T[i])  # Append the corresponding character from T at the same index.

print("".join(char_lists))  # Join the combined characters into a single string and print it.

