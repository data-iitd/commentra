# Declare variables to hold the number of operations (n) and the sequence of operations (s)
n = int(input())
s = input()

# Initialize variables to track the maximum count and the current count
max_count = 0
cnt = 0

# Iterate over each character in the string s
for r in s:
    # Increment count for 'I' and decrement for any other character
    if r == 'I':
        cnt += 1
    else:
        cnt -= 1

    # Update max_count if the current count exceeds the previously recorded maximum
    if cnt > max_count:
        max_count = cnt

# Print the maximum count achieved during the iterations
print(max_count)

# <END-OF-CODE>
