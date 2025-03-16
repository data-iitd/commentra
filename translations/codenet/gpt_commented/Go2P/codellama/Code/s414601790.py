
# Declare variables to hold the number of operations (n) and the sequence of operations (s)
n = 0
s = ""

# Read input values for n and s from the standard input
n, s = input().split()
n = int(n)

# Initialize variables to track the maximum count and the current count
max = 0
cnt = 0

# Iterate over each character in the string s
for r in s:
    # Increment count for 'I' and decrement for any other character
    if r == 'I':
        cnt += 1
    else:
        cnt -= 1

    # Update max if the current count exceeds the previously recorded maximum
    if cnt > max:
        max = cnt

# Print the maximum count achieved during the iterations
print(max)

