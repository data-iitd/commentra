# Include necessary headers
# The code starts by including necessary headers for input and output operations.
# Headers for input and output operations are included.

# Declare arrays
# Two arrays, `train` and `bus`, are declared to store the values.
train = [0,0]
bus = [0,0]

# Input values
# The values for `train` and `bus` are taken from the user.
train[0] = int(input())
train[1] = int(input())
bus[0] = int(input())
bus[1] = int(input())

# Calculate the sum
# The code then calculates the sum of the minimum values from both arrays.
print((train[0]<train[1]?train[0]:train[1])+(bus[0]<bus[1]?bus[0]:bus[1]))

# Output the result
# Finally, the result is printed to the console.
