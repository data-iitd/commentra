# Read an integer input from the user, which represents the number of strings to be entered
n = int(input())

# Create a set comprehension to collect unique strings from user input
# The input() function is called n times to gather the strings
# The set will automatically handle duplicates, keeping only unique values
unique_strings = set([input() for _ in range(n)])

# Print the number of unique strings by calculating the length of the set
print(len(unique_strings))
