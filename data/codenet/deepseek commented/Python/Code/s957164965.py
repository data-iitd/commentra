
X, N = list(map(int, input().split()))
# Read two integers, X and N, from the input.
p = list(map(int, input().split()))
# Read a list of integers p.

p.sort()
# Sort the list p to easily find the closest number to X.

candidates = {}
# Initialize an empty dictionary to store candidate numbers based on their difference from X.
for i in range(-1, 102):
    # Iterate over a range from -1 to 102 to generate potential candidates.

    if i in p:
        continue
        # Skip the iteration if the current number i is already in the list p.

    if not (abs(X-i) in candidates.keys()):
        candidates[abs(X-i)] = [i]
        # If the difference is not already a key in the dictionary, add it with the current number as its value.
    else:
        candidates[abs(X-i)].append(i)
        # If the difference is already a key, append the current number to the list of values.

smallest = min(candidates.keys())
# Find the smallest key in the dictionary, representing the smallest absolute difference.

minNum = min(candidates[smallest])
# Find the minimum number from the list of values associated with the smallest key.

print(minNum)
# Print the closest number to X.