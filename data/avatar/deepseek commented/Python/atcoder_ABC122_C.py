
from itertools import accumulate

# Read the length of the string and the number of queries
n, q = map(int, input().split())

# Read the string
s = input()

# Read the queries
problems = [list(map(int, input().split())) for _ in range(q)]

# Define a function to count occurrences of 'AC' in the string
def count(total, i):
    # Check if the current substring is 'AC'
    if s[i-1:i+1] == 'AC':
        # Increment the count if 'AC' is found
        return total + 1
    else:
        # Return the total count if 'AC' is not found
        return total

# Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
cumsum = list(accumulate([0] + list(range(1, n)), count))

# Iterate over the queries and print the difference in cumulative sums
for l, r in problems:
    print(cumsum[r-1] - cumsum[l-1])


