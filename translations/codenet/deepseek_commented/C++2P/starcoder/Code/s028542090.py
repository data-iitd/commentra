
# Declare an array to store up to 100100 elements
a = [0] * 100100

# Declare an integer variable to store the number of elements
k = int(input())

# Read the elements of the array from the standard input
for i in range(k):
    a[i] = int(input())

# Declare variables to store the minimum and maximum values
min = 2
max = 3

# Check if the last element of the array is not 2
if a[k - 1]!= 2:
    print(-1)
    exit(0)

# Iterate through the array in reverse order
for i in range(k - 2, -1, -1):
    # Check if the current element is greater than the current maximum
    if a[i] > max:
        print(-1)
        exit(0)
    else:
        # Update the maximum value
        max = ((max // a[i]) + 1) * a[i] - 1
        # Check if min is not a multiple of the current element
        if min % a[i]!= 0:
            # Update the minimum value
            min = ((min // a[i]) + 1) * a[i]

    # Check if the maximum value is not greater than the minimum value
    if max <= min:
        print(-1)
        exit(0)

# Output the minimum and maximum values
print(min, max)

# 