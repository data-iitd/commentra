# Define a constant size for the count array
SIZE = (1e5 * 2) + 13

# Declare a count array initialized to zero with a size of SIZE
cnt = [0] * SIZE

# Read the number of elements (n) and the number of largest counts to keep (k)
n, k = map(int, input().split())

# Read n integers and count their occurrences
for i in range(n):
    x = int(input())
    # Increment the count for the number x
    cnt[x] += 1

# Initialize the answer variable to accumulate the result
ans = 0
# Sort the counts in ascending order
a = sorted(cnt)

# Calculate the number of counts to exclude (m) based on k
m = len(a) - k
# Sum the counts of the smallest m elements
for i in range(m):
    ans += a[i] # Add the count to the answer

# Output the final answer
print(ans)

