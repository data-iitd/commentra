# The code starts by taking input for the maximum level and two lists of integers.
max_level = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

# Remove the first element from each list, convert them into sets, and check if there's a 0 in either set.
x.pop(0)
y.pop(0)
x = set(x)
y = set(y)

# If there's a 0 in either set, discard it from the set.
if 0 in x:
    x.discard(0)
elif 0 in y:
    y.discard(0)

# Find the union of the two sets and check if its length is equal to the maximum level.
z = x.union(y)
if len(z) != max_level:
    print("Oh, my keyboard!")
else:
    print("I become the guy.")
