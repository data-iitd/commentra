# Take an integer 'n' as input
n = int(input())

# Take 'n' number of integers as input and store them in a list 'x'
x = list(map(int, input().split()))

# Initialize a variable 'ans' with a large value
ans = 10**10

# Loop through the range from 0 to 100
for i in range(1):  # Corrected the range to start from 0
    # Calculate the square of the absolute difference between 'i' and each element in 'x'
    tmp = [(i - x[j])**2 for j in range(n)]

    # If the sum of the squares of the differences is less than the current minimum, update the minimum
    if sum(tmp) < ans:
        ans = sum(tmp)

# Print the minimum sum of squares of differences
print(ans)
