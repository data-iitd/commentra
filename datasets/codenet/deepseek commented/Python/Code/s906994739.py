n = int(input())
# Read n stores' opening status for each time slot
F = [tuple(map(int, input().split())) for _ in range(n)]
# Read n stores' profit for each time slot
P = [tuple(map(int, input().split())) for _ in range(n)]
# Initialize the maximum profit to a very large negative number
ans = -10 ** 18

# Iterate over all possible combinations of opening or not opening each store for each time slot
for i in range(1, 2**10):
    tmp = 0
    lst = [0] * n
    # Check each time slot and update the opening status for each store
    for j in range(10):
        if (i >> j) & 1:
            for k in range(n):
                lst[k] += F[k][j]
    # Calculate the total profit for each store based on the opening status
    for k in range(n):
        tmp += P[k][lst[k]]
    # Update the maximum profit found so far
    ans = max(ans, tmp)

# Output the maximum profit
print(ans)