# Ask the user for the number of elements in the list
n = int(input())

# Ask the user to input the elements of the list separated by spaces
r = [* map(int, input().split())]

# Initialize a variable to store the answer
ans = abs(r[0])

# Use a for loop to calculate the sum of the absolute differences between consecutive elements
for i in range(1, n):
    ans += abs(r[i] - r[i-1])

# Print the final answer
print(ans)
