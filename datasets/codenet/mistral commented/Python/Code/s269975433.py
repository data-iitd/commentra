# Import necessary modules
from itertools import combinations_with_replacement
import sys

# Define a helper function to read a line of input as a list of integers
def LI(): return map(int, sys.stdin.readline().rstrip().split())

# Read the input: the number of tests Q, the number of elements in the set M, and the number of elements to be picked in each test N
N, M, Q = LI()

# Create an empty list Q_groups to store the groups of tests
Q_groups = []

# For each test, read its elements (the indices of the elements to be compared, the difference between them, and the score) and append it to Q_groups
for _ in range(Q):
    # Read a line of input as a list of integers
    a, b, c, d = LI()
    # Append the test group to Q_groups
    Q_groups.append([a, b, c, d])

# Initialize a variable max_score to store the maximum score that can be obtained
max_score = 0

# Generate all combinations of N elements from the set of indices [1, ..., M] using the combinations_with_replacement function from itertools
for p in combinations_with_replacement(range(1, M + 1), r=N):
    # Initialize a variable temp_score to 0
    temp_score = 0
    
    # For each test group q in Q_groups, check if the difference between the indices in p matches the difference in q
    for q in Q_groups:
        # Check if the difference between the indices in p matches the difference in q
        if p[q[1] - 1] - p[q[0] - 1] == q[2]:
            # Add the score to temp_score
            temp_score += q[3]
    
    # Update max_score with the maximum of its current value and temp_score
    max_score = max(max_score, temp_score)

# Print the maximum score
print(max_score)
