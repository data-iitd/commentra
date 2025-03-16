# Read input values for X and N
X, N = list(map(int, input().split()))

# Read the list of integers p
p = list(map(int, input().split()))

# Sort the list of integers p
p.sort()

# Initialize a dictionary to hold candidates based on their distance from X
candidates = {}

# Iterate through a range of possible integers from -1 to 101
for i in range(-1, 102):
    # Skip the current integer if it is already in the list p
    if i in p:
        continue

    # Calculate the absolute distance from X and check if it's already a key in candidates
    if not (abs(X-i) in candidates.keys()):
        # If not, create a new entry with the distance as the key and the integer as the value
        candidates[abs(X-i)] = [i]
    else:
        # If it exists, append the integer to the list of candidates for that distance
        candidates[abs(X-i)].append(i)

# Find the smallest distance from X among the candidates
smallest = min(candidates.keys())

# Find the minimum integer associated with the smallest distance
minNum = min(candidates[smallest])

# Print the result, which is the integer closest to X that is not in p
print(minNum)
