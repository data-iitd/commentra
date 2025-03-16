# Read two integers from input: num (number of elements) and k (the divisor)
num, k = [int(x) for x in input().split()]

# Read the array of integers from input
arr = [int(x) for x in input().split()]

# Initialize a set to keep track of unique elements that meet the criteria
different = set()

# Initialize a variable to keep track of the maximum size of the 'different' set
temp = 0

# Sort the array to process elements in ascending order
arr.sort()

# Iterate through each element in the sorted array
for x in arr:
    # Check if the element is not divisible by k or if its quotient is not already in the 'different' set
    if (x % k != 0 or not x // k in different):
        # Add the element to the 'different' set since it meets the criteria
        different.add(x)
    
    # Update the maximum size of the 'different' set if the current size is larger
    temp = max(len(different), temp)

# Print the maximum size of the 'different' set found
print(temp)
