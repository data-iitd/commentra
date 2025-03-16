# Read an integer input for the number of elements
n = int(input())

# Read a list of integers from input
x = list(map(int, input().split()))

# Initialize a variable to hold the minimum sum of squared differences
ans = 10**10

# Iterate over all possible values from 0 to 100 (inclusive)
for i in range(101):
    # Calculate the squared differences between the current value 'i' and each element in the list 'x'
    tmp = [abs(i - x[j])**2 for j in range(n)]
    
    # If the sum of squared differences is less than the current minimum, update the minimum
    if sum(tmp) < ans:
        ans = sum(tmp)

# Print the minimum sum of squared differences found
print(ans)
