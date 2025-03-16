
n = int(input())  # Take an integer input representing the length of the list `a`
a = list(map(int, input().split()))  # Take a space-separated string of integers and convert them to a list `a` of integers
b = [0] * n  # Initialize an empty list `b` of length `n`

# Assign the index of each element in `a` to the corresponding position in `b`, adjusting for zero-based indexing
for i in range(n):
    b[a[i] - 1] = i

res = 0  # Initialize the result variable `res` to 0

# Calculate the sum of absolute differences between the positions of consecutive elements in `b`
for i in range(1, n):
    res += abs(b[i] - b[i - 1])

print(res)  # Print the result


