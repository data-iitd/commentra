import sys
input = sys.stdin.readline

# Step 1: Reading the number of elements (n)
n = int(input())

# Step 2: Reading the list of elements (a)
a = list(map(int, input().split()))

# Step 3: Initializing variables
pre = float('inf')  # Initialize pre to infinity
ans = 0  # Initialize ans to 0

# Step 4: Sorting the list in descending order
a.sort(reverse=True)

# Step 5: Iterating through the list
for j in range(n):
    # Calculate the maximum value that can be added to ans
    ans += max(0, min(pre - 1, a[j]))
    # Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
    pre = max(0, min(pre - 1, a[j]))

# Step 6: Printing the result
print(ans)
