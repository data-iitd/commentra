# User inputs the maximum level of the set
max_level = int(input())

# User inputs two lists, x and y, separated by a newline
x = list(map(int, input().split()))
y = list(map(int, input().split()))

# Remove the first element from both lists, as they are not part of the sets
x.pop(0)
y.pop(0)

# Convert both lists to sets for faster set operations
x = set(x)
y = set(y)

# Check if zero is present in the first set
if 0 in x:
    # If it is, remove it
    x.discard(0)
# Else, check if zero is present in the second set
else:
    if 0 in y:
        # If it is, remove it
        y.discard(0)

# Combine both sets into a new set z
z = x.union(y)

# Check if the size of the combined set is equal to the maximum level
if len(z) != max_level:
    # If not, print an error message
    print("Oh, my keyboard!")
# Else, print a success message
else:
    print("I become the guy.")
