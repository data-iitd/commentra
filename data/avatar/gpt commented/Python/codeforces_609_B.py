def _input():
    # Read a line of input, split it into parts, and convert each part to an integer
    return map(int, input().split())

# Read the values of n and m from input
n, m = _input()

# Read a list of integers from input
lst = list(_input())

# Initialize a dictionary to count occurrences of each integer in the list
l = {}

# Count the occurrences of each integer in the list
for i in range(n):
    if lst[i] not in l:
        # If the integer is not in the dictionary, add it with a count of 1
        l[lst[i]] = 1
    else:
        # If the integer is already in the dictionary, increment its count
        l[lst[i]] += 1

# Initialize the result variable to store the final count
res = 0

# Calculate the result based on the occurrences of integers
for i in range(n):
    if l[lst[i]] > 1:
        # If the current integer appears more than once
        res += n - i - l[lst[i]]  # Add the number of valid pairs
        l[lst[i]] -= 1  # Decrease the count of this integer
    else:
        # If the current integer appears only once
        res += n - i - 1  # Add the number of valid pairs for unique integers

# Print the final result
print(res)
