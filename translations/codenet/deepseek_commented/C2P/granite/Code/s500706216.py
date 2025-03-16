
import sys

# Define the size of the arrays
MAX_SIZE = 200000

# Define the data type for large integers
ll = int

# Declare the arrays and variables
a = [0] * MAX_SIZE
tmpa = [0] * MAX_SIZE
light = [0] * (MAX_SIZE + 10)

# Read the values of n and k from standard input
n, k = map(int, input().split())

# Read n integers from standard input and store them in array a
a = list(map(int, input().split()))

# Initialize the light array based on the initial positions of the lights
for i in range(n):
    r = i - a[i]
    l = i + a[i]
    light[r if r >= 0 else 0] += 1
    light[l + 1 if l + 1 <= n else n + 1] -= 1

# Debugging: Print the light array
# print(*light, sep=" ")

# Apply the lights k times
for _ in range(k):
    sum = 0
    # Update array a based on the light array
    for j in range(n):
        tmpa[j] = a[j]
        sum += light[j]
        a[j] = sum
    # Adjust the light array based on the new state of array a
    for j in range(n):
        r = j - tmpa[j]
        l = j + tmpa[j]
        light[r if r >= 0 else 0] -= 1
        light[l + 1 if l + 1 <= n else n + 1] += 1
        r = j - a[j]
        l = j + a[j]
        light[r if r >= 0 else 0] += 1
        light[l + 1 if l + 1 <= n else n + 1] -= 1
    # Check if the array a has become stable
    isSame = True
    for j in range(n - 1):
        if a[j]!= a[j + 1]:
            isSame = False
            break
    # Check if the array a is stable and the first element is n
    if isSame and a[0] == n:
        break

# Print the final state of array a
print(*a, sep=" ")

