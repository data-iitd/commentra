# Take an integer 'n' as input
n = int(input())

# Initialize a list 'a' of 'n' integers by taking input
a = list(map(int, input().split()))

# Initialize an empty list 'b' of length 'n'
b = [0] * n

# Assign indices to 'b' based on the values in 'a'
for i in range(n):
    # Assign index 'i' to the position 'a[i] - 1' in list 'b'
    b[a[i] - 1] = i

# Initialize a variable 'res' to 0
res = 0

# Calculate the absolute difference between consecutive indices in 'b' and sum them up
for i in range(1, n):
    # Add the absolute difference between indices 'i' and 'i-1' to 'res'
    res += abs(b[i] - b[i-1])

# Print the final result 'res'
print(res)
