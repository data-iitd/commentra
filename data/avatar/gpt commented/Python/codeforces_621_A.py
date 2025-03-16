# Read an integer input for the number of elements
n = int(input())

# Read a list of integers from input and convert them to a list of integers
lst = list(map(int, input().split()))

# Sort the list in ascending order
lst.sort()

# Reverse the list to get it in descending order
lst.reverse()

# Initialize a counter for odd numbers
od = 0

# Count the number of odd integers in the list
for i in lst:
    if (i & 1):  # Check if the number is odd using bitwise AND
        od += 1  # Increment the odd counter

# Initialize variables for sum and a flag to track even number inclusion
sum = 0
ok = 0

# Iterate through the sorted list to calculate the desired sum
for i in range(n):
    if (lst[i] % 2 == 0):  # Check if the current number is even
        sum += lst[i]  # Add even numbers directly to the sum
    else:
        # If we have already included an odd number or there is more than one odd number left
        if (ok or od > 1):
            sum += lst[i]  # Add the odd number to the sum
            od -= 1  # Decrement the odd counter
            ok = not ok  # Toggle the flag to indicate an odd number has been included

# Print the final calculated sum
print(sum)
