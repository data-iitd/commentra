import array // Importing utility class for array operations
import sys // Importing utility class for input handling

n = int(sys.stdin.readline()) // Read the number of elements
ans = array.array('l', [0] * n) // Initialize array to store long integers

# Populate the array with input values
for i in range(n):
    ans[i] = int(sys.stdin.readline())

# Sort the array in ascending order
ans.sort()

# Initialize count with the largest element in the array
count = ans[n - 1]

# Iterate through the array from the second-to-last element to the first
for i in range(n - 2, -1, -1):
    if ans[i] < ans[i + 1]:
        count += ans[i] // Add the current element to count if it's less than the next element
    else:
        while ans[i] >= ans[i + 1]:
            ans[i] -= 1 // Decrease the current element until it's less than the next element
        if ans[i] > 0:
            count += ans[i] // Add the adjusted current element to count

# Print the final count
print(count)

