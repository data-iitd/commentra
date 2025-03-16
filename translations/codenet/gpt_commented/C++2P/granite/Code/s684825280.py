
import sys
from collections import Counter

# Read the number of elements (n) and the number of largest counts to keep (k)
n, k = map(int, sys.stdin.readline().split())

# Read n integers and count their occurrences
cnt = Counter(map(int, sys.stdin.read().split()))

# Transfer the counts of numbers that appeared at least once to a list
a = [cnt[x] for x in cnt if cnt[x] > 0]

# Initialize the answer variable to accumulate the result
ans = 0

# Sort the counts in ascending order
a.sort()

# Calculate the number of counts to exclude (m) based on k
m = len(a) - k

# Sum the counts of the smallest m elements
for i in range(m):
    ans += a[i]  # Add the count to the answer

# Output the final answer
print(ans)

