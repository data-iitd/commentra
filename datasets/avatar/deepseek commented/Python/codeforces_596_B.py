
n = int(input())  # Read the number of elements in the list `r`
r = [*map(int, input().split())]  # Read the space-separated string of integers and convert them to a list of integers
ans = abs(r[0])  # Initialize `ans` to the absolute value of the first element in the list `r`

# The for loop iterates over the range from 1 to `n` (inclusive)
# For each iteration, it adds the absolute difference between the current element and the previous element in the list `r` to `ans`
for i in range(1, n):
    ans += abs(r[i] - r[i - 1])

print(ans)  # Print the value of `ans`

