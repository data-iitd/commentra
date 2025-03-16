
# Declare variables for number of intervals and time range
n, t = map(int, input().split())

# Declare variables for left and right endpoints of intervals
l, r = map(int, input().split())

# Declare an array to store cumulative changes
mem = [0] * (t + 1)

# Read each interval and update the cumulative changes in the array
for i in range(n):
    l, r = map(int, input().split())
    mem[l] += 1
    mem[r] -= 1

# Initialize ans with the value at mem[0]
ans = mem[0]

# Compute the prefix sum and find the maximum value in the array
for i in range(1, t + 1):
    mem[i] += mem[i - 1]
    if ans < mem[i]:
        ans = mem[i]

# Print the maximum value found
print(ans)

