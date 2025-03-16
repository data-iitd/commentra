# Declare variables
n = int(input())  # Number of elements in the array
sum_diff = 0  # Variable to store the total sum of differences

# Read n elements into the array from user input
a = list(map(int, input().split()))

# Iterate through the array to calculate the sum of differences
for i in range(1, n):
    # Check if the previous element is greater than the current element
    if a[i - 1] > a[i]:
        # Calculate the difference and add it to the sum
        sum_diff += a[i - 1] - a[i]
        # Update the current element to be equal to the previous element
        a[i] = a[i - 1]

# Print the total sum of differences
print(sum_diff)

# <END-OF-CODE>
