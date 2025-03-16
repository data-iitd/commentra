#######
# Code
#######

# Get the number of elements X and the number of integers N from user input
X, N = list(map(int, input().split()))

# Comment: Initialize two variables X and N with the number of elements and the number of integers respectively

p = list(map(int, input().split()))

# Comment: Get the list p of N integers from user input

p.sort()

# Comment: Sort the list p in ascending order

candidates = {}
# Comment: Initialize an empty dictionary candidates to store the differences between X and possible integers

for i in range(-1, 102):
    # Comment: Iterate through all possible integers i from -1 to 101

    if i in p:
        # Comment: If i is already in the list p, skip it
        continue

    if not (abs(X-i) in candidates.keys()):
        # Comment: If the absolute difference between X and i is not in the dictionary candidates, add it as a key with a list value containing i
        candidates[abs(X-i)] = [i]
    else:
        # Comment: If the absolute difference between X and i is already a key in the dictionary candidates, append i to the list value
        candidates[abs(X-i)].append(i)

# Comment: After iterating through all possible integers, the dictionary candidates will contain the list of integers that have the smallest absolute difference with X

smallest = min(candidates.keys())
# Comment: Find the smallest absolute difference between X and any integer

minNum = min(candidates[smallest])
# Comment: Find the integer with the smallest absolute difference from X

print(minNum)
# Comment: Print the integer with the smallest absolute difference from X
