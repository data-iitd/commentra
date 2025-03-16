
import sys

# Synchronize the input and output streams with stdio
sys.stdin, sys.stdout = open("input.txt", "r"), open("output.txt", "w")

# Read an integer n from the standard input
n = int(input())

# Allocate an array p of size n to store the input integers
p = list(map(int, input().split()))

# Initialize the variable ans to 0
ans = 0

# Iterate through the array p from index 0 to n-3
for i in range(n - 2):
    # Check if the current element p[i] is smaller than the next two elements p[i+1] and p[i+2]
    if p[i] < p[i+1] and p[i+1] < p[i+2]:
        # Increment the ans variable if both conditions are true
        ans += 1

    # Check if the current element p[i] is greater than the next two elements p[i+1] and p[i+2]
    if p[i] > p[i+1] and p[i+1] > p[i+2]:
        # Increment the ans variable if both conditions are true
        ans += 1

# Print the value of ans to the standard output
print(ans)

