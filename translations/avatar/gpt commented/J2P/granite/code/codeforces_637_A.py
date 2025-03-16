
import sys

# Read the number of elements
n = int(input())

# Initialize an array to store the elements
ara = list(map(int, input().split()))

# Create a dictionary to count the frequency of each element
freq = {}

# Read elements and populate the frequency dictionary
for v in ara:
    if v not in freq:
        freq[v] = 1
    else:
        freq[v] += 1

# Find the maximum frequency among the elements
max_freq = max(freq.values())

# Create another dictionary to track the order of elements while checking frequency
order = {}

# Iterate through the original array to find the first element with maximum frequency
for i in range(n):
    if ara[i] not in order:
        order[ara[i]] = 1
        # Check if the current element's frequency matches the maximum frequency
        if order[ara[i]] == max_freq:
            print(ara[i])
            sys.exit()
    else:
        # Increment the count for the existing element
        order[ara[i]] += 1
        # Check if the current element's frequency matches the maximum frequency
        if order[ara[i]] == max_freq:
            print(ara[i])
            sys.exit()

# Debugging method to print objects
def debug(*obj):
    print(*obj, file=sys.stderr)

# End of code
