
# Declare an array to hold the input values
a = []

# Read the number of elements
k = int(input())

# Read the input values into the array
for i in range(k):
    a.append(int(input()))

# Initialize max and min values
max = 3
min = 2

# Check if the last element is not equal to 2
if a[k - 1]!= 2:
    print(-1) # Output -1 if the condition is met
    exit(0) # Exit the program

# Iterate through the array from the second last element to the first
for i in range(k - 2, -1, -1):
    # If the current element is greater than max, output -1
    if a[i] > max:
        print(-1) # Output -1 if the condition is met
        exit(0) # Exit the program
    else:
        # Update max based on the current element
        max = ((max // a[i]) + 1) * a[i] - 1
        # Adjust min to be a multiple of the current element if necessary
        if min % a[i]!= 0:
            min = ((min // a[i]) + 1) * a[i]

    # Check if the updated max is less than or equal to min
    if max <= min:
        print(-1) # Output -1 if the condition is met
        exit(0) # Exit the program

# Output the final min and max values
print(min, max)

# 