# Take input from the user
s = input()

# Define a list of all lowercase alphabets
alphabets = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

# Iterate through the list of alphabets using their indices
for i in range(len(alphabets)):
    # Check if the current alphabet matches the user input
    if alphabets[i] == s:
        # Print the next alphabet in the list
        print(alphabets[i + 1])
