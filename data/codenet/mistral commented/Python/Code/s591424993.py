########
# Code #
########

# Take two integers d and g as input
d, g = list(map(int, input().split()))

# Initialize a list 'pc' of size 'd' containing pairs of integers
pc = [list(map(int, input().split())) for _ in range(d)]

# Initialize an answer variable 'ans' with a large initial value
ans = float("inf")

# Iterate through all possible combinations of 1's and 0's in binary representation of length 'd'
for bit in range(1 << d):
    # Initialize counters 'count' and 'sum' and a set 'nokori'
    count = 0
    sum = 0
    nokori = set(range(1, d + 1))

    # Iterate through each index 'i' in the range of 'd'
    for i in range(d):
        # If the current bit is set (1) at position 'i' in the binary representation 'bit'
        if bit & (1 << i):
            # Add the contribution of the current process to the sum and count
            sum += pc[i][0] * (i + 1) * 100 + pc[i][1]
            count += pc[i][0]
            # Remove the index 'i+1' from the set 'nokori' as it has been used
            nokori.discard(i + 1)

    # Check if the sum of contributions from all used processes is less than the target 'g'
    if sum < g:
        # Find the index 'use' of the next process that can be used to minimize the difference between 'g' and 'sum'
        use = max(nokori)
        # Calculate the minimum number 'n' of the current process that can be used to reach or exceed the target 'g'
        n = min(pc[use-1][0], -(-(g - sum) // (use * 100)))
        # Add the contribution of the new process to the sum and count
        count += n
        sum += n * use * 100

    # Check if the sum of contributions from all used processes is greater than or equal to the target 'g'
    if sum >= g:
        # Update the answer variable 'ans' with the minimum count among all valid combinations
        ans = min(ans, count)

# Print the minimum count
print(ans)
