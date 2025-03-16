# Read two integers n and m from input, representing the number of strings and some other parameter
n, m = map(int, input().split())

# Create a set comprehension to calculate the difference in indices of 'S' and 'G' for each string
# The difference is calculated as the index of 'S' minus the index of 'G'
c = set(s.find("S") - s.find("G") for s in (input() for _ in range(n)))

# Check if any of the calculated differences are negative
# If any difference is negative, print -1; otherwise, print the number of unique differences
print(-1 if any(a < 0 for a in c) else len(c))
