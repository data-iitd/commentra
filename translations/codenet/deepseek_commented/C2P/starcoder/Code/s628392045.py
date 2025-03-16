# Include standard input/output library for input/output operations
# Include string library for string manipulation
# Include standard library for dynamic memory management

# Declare variables for number of elements and loop index
n = int(input())
h = [0] * n

# Initialize max to -1 to store the maximum height found
max = -1

# Initialize flag to 0 to indicate whether the condition is met
flag = 0

# Loop to read heights and update the maximum height found
for i in range(n):
    h[i] = int(input())
    if max < h[i]:
        max = h[i]
    if max - h[i] >= 2:
        flag = 1

# Print "No" if the condition is met
if flag == 1:
    print("No")
# Print "Yes" if the condition is not met
else:
    print("Yes")

