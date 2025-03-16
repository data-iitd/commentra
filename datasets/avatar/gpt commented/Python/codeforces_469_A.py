# Read the maximum level from user input
max_level = int(input())

# Read the levels completed by player X and convert them to a list of integers
x = list(map(int, input().split()))

# Read the levels completed by player Y and convert them to a list of integers
y = list(map(int, input().split()))

# Remove the first element from both lists, which represents the count of levels
x.pop(0)
y.pop(0)

# Convert the lists of levels into sets to eliminate duplicates
x = set(x)
y = set(y)

# Check if player X has completed level 0, if so, remove it from the set
if 0 in x:
    x.discard(0)
# If player X has not completed level 0, check if player Y has, and remove it if present
elif 0 in y:
    y.discard(0)

# Create a union of both sets to combine all unique levels completed by both players
z = x.union(y)

# Check if the number of unique levels completed matches the maximum level
if len(z) != max_level:
    # If not, print a message indicating that not all levels were completed
    print("Oh, my keyboard!")
else:
    # If all levels were completed, print a success message
    print("I become the guy.")
