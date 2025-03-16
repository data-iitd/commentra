
N = int(input())  # Ask user for the length of strings S and T
S, T = input().split()  # Ask user to input strings S and T separated by a space

char_lists = []  # Create an empty list to store the characters of the combined string S+T

for i in range(N):  # Iterate through each character in string S
    char = S[i]  # Assign the current character in string S to variable char
    char_lists.append(char)  # Append the character from string S to list char_lists
    char_lists.append(T[i])  # Append the corresponding character from string T to list char_lists

print("".join(char_lists))  # Join all the elements of list char_lists into a single string and print it out