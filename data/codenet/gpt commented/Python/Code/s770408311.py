# Read an integer input from the user which represents the number of strings to be processed
n = int(input())

# Initialize an empty list to store the input strings
res = []

# Loop n times to read n strings from the user
for i in range(n):
    # Read a string input from the user
    a = input()
    # Append the input string to the list
    res.append(a)

# Convert the list to a set to remove duplicates and print the number of unique strings
print(len(set(res)))
