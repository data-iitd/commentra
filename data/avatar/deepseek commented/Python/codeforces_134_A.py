
import sys
input = sys.stdin.readline

# Read the number of elements in the list `w`
n = int(input())

# Read `n` integers from the standard input and store them in the list `w`
w = list(map(int, input().split()))

# Calculate the sum of all elements in the list `w`
x = sum(w)

# Initialize an empty list `d` to store the indices of elements that satisfy the condition
d = []

# Iterate over each element in the list `w`
for i in range(n):
    # Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
    if (x - w[i]) / (n - 1) == w[i]:
        # Append the 1-based index of the element to the list `d`
        d.append(i + 1)

# Print the length of the list `d`
print(len(d))

# Print the indices in `d` separated by spaces
print(' '.join(map(str, d)))

