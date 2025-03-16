n = int(input())
data = list(map(int, input().split()))

max_value = 0
index = 0

# Find the maximum value and its index
for i in range(n):
    if data[i] > max_value:
        max_value = data[i]
        index = i

# Calculate the sum of elements excluding the maximum value
a = sum(data[i] for i in range(n) if i != index)

# Compare the sum of the remaining elements with the maximum value
if a > max_value:
    print("Yes")
else:
    print("No")
