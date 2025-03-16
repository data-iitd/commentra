from operator import itemgetter  # Import itemgetter to facilitate sorting by specific item in tuples

# Read the number of elements from user input
N = int(input())

# Read the elements from user input, creating a list of tuples (index, value)
A = [(i + 1, int(x)) for i, x in enumerate(input().split())]

# Sort the list of tuples based on the second item (the value) in each tuple
A_ = sorted(A, key=itemgetter(1))

# Extract the first item (the original index) from each sorted tuple into a new list
A__ = [a[0] for a in A_]

# Print the indices of the sorted values, separated by spaces
for i in A__[:-1]:  # Loop through all but the last index
    print(i, end=' ')  # Print each index followed by a space

# Print the last index without a trailing space
print(A__[-1])
