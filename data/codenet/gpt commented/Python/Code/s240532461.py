# Read two integers N and L from input
N, L = map(int, input().split())

# Initialize an empty list to store the values
aji = []

# Populate the list 'aji' with values from L to L + N - 1
for i in range(1, N + 1):
    aji.append(L + i - 1)

# Check if the minimum value in 'aji' is non-negative
if min(aji) >= 0:
    # If true, remove the minimum value from the list
    aji.pop(aji.index(min(aji)))
# Check if the maximum value in 'aji' is non-positive
elif max(aji) <= 0:
    # If true, remove the maximum value from the list
    aji.pop(aji.index(max(aji)))
else:
    # If there are both positive and negative values, remove the value with the smallest absolute value
    aji.pop(aji.index(min(aji, key=abs)))

# Print the sum of the remaining values in the list
print(sum(aji))
