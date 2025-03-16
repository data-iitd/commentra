# Take the first line of input which are two integers 'num' and 'k'
num, k = [int(x) for x in input().split()]

# Comment: Initialize 'num' and 'k' with the values from user input

# Take the second line of input which is a list 'arr' of integers
arr = [int(x) for x in input().split()]

# Comment: Initialize an empty list 'arr' to store the input integers

# Create an empty set 'different' to store unique integers
different = set()

# Comment: Initialize an empty set 'different' to store unique integers

# Sort the list 'arr' in ascending order
arr.sort()

# Comment: Sort the list 'arr' in ascending order for easier comparison

# Iterate through each integer 'x' in the sorted list 'arr'
for x in arr:

    # Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
    if (x % k != 0 or not x // k in different):

        # If the condition is true, add 'x' to the set 'different'
        different.add(x)

        # Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'

    # Update the maximum length of 'different' seen so far
    temp = max(len(different), temp)

# Comment: After the loop, 'temp' stores the maximum length of 'different' seen during the iteration

# Print the maximum length of 'different'
print(temp)

# Comment: Finally, print the maximum length of 'different'
