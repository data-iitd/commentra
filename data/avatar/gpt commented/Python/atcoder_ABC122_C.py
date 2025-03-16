from itertools import accumulate

# Read the number of characters in the string and the number of queries
n, q = map(int, input().split())

# Read the input string
s = input()

# Read the queries, each containing two integers l and r
problems = [list(map(int, input().split())) for _ in range(q)]

# Define a function to count occurrences of 'AC' in the string
def count(total, i):
    # Increment total if the substring from index i-1 to i is 'AC'
    return total + 1 if s[i - 1:i + 1] == 'AC' else total

# Create a cumulative sum list to keep track of 'AC' occurrences
cumsum = list(accumulate([0] + list(range(1, n)), count))

# Process each query to find the number of 'AC' occurrences in the specified range
for l, r in problems:
    # Output the difference in cumulative sums to get the count in the range [l, r]
    print(cumsum[r - 1] - cumsum[l - 1])
