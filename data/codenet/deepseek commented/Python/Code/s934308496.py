
n, x = map(int, input().split())
# Take two inputs, `n` and `x`, and convert them to integers.

m = [int(input()) for _ in range(n)]
# Create a list `m` containing `n` integers, each read from input.

m.sort()
# Sort the list `m` in ascending order.

print(n + (x - sum(m)) // m[0])
# Print the result based on the sum of the sorted list `m` and the remaining value `x`.

