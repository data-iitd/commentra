# Define the number of elements in the list 'A'
N = int(input())

# Initialize an empty list 'A' with 'N' elements
# Each element is a tuple containing an index and a value
A = [(i + 1, int(x)) for i, x in enumerate(input().split())]

# Sort the list 'A' based on the second element of each tuple (the value)
A_ = sorted(A, key=itemgetter(1))

# Extract the first element (index) of each tuple in 'A_' into a new list 'A__'
A__ = [a[0] for a in A_]

# Iterate through the list 'A__' (excluding the last element) and print each index
for i in A__[:-1]:
    print(i, end=' ')

# Print the last index in 'A__'
print(A__[-1])
