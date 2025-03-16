
n = int(input())  # Take an integer input representing the number of elements in the list `a`.
a = list(map(int, input().split()))  # Take a list of integers as input and store it in the list `a`.

# Calculate `m1` which is the sum of the elements in `a` multiplied by `(-1)^i` for each element, divided by 2.
m1 = int(sum([a[i] * ((-1)**i) for i in range(n)]) / 2)

result = str(m1)  # Convert `m1` to a string and store it in the variable `result`.

m = [None] * n  # Initialize a list `m` with `n` elements, all set to `None`.
m[0] = m1  # Set the first element of `m` to `m1`.

# Start a loop that iterates from 1 to `n-1` and calculates each subsequent element of `m` as the previous element of `a` minus the corresponding element of `m`.
for i in range(1, n):
  m[i] = a[i-1] - m[i-1]

# Print the elements of `m` multiplied by 2, joined by spaces.
print(' '.join([str(x*2) for x in m]))

