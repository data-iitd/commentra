
n = int(input())  # Take an integer input from the user
print(len(set([input() for _ in range(n)])))  # Print the length of the set created from the list comprehension of user inputs

# List comprehension to get list of user inputs
user_inputs = [input() for _ in range(n)]

# Convert the list to a set to remove duplicates
unique_inputs = set(user_inputs)

# Find the length of the set to get the number of unique user inputs
num_unique_inputs = len(unique_inputs)

print(num_unique_inputs)  # Print the number of unique user inputs