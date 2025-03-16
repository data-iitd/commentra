n = int(input())  # Read the number of elements

# Read n integers into list a
a = list(map(int, input().split()))

# Read n integers into list b and calculate the sum of positive differences
sum_diff = 0
b = list(map(int, input().split()))
for i in range(n):
    if a[i] - b[i] > 0:  # Check if a[i] is greater than b[i]
        sum_diff += a[i] - b[i]  # Add the difference to sum

# Output the sum
print(sum_diff)

# <END-OF-CODE>
