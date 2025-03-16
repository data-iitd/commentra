# Initialize an empty list to store the sequence
L = []

# Read input (not used, but could be for prompting the user)
input()

# Initialize a variable 'r' to keep track of the current number to be added to the list
r = 1

# Read a line of input, split it into parts, and iterate over each part
for k in input().split():
    # Extend the list 'L' by adding 'r' for 'int(k)' times
    L += [r] * int(k)
    # Increment 'r' for the next number
    r += 1

# Read another line of input (not used, but could be for prompting the user)
input()

# Read a line of input, split it into parts, and iterate over each part
for j in input().split():
    # Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
    print(L[int(j) - 1])
