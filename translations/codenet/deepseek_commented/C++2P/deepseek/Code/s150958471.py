# Include necessary headers
# Python does not require headers for input and output operations.

# Declare arrays
# Two arrays, `train` and `bus`, are declared to store the values.
train = [0] * 2
bus = [0] * 2

# Input values
# The values for `train` and `bus` are taken from the user.
train[0], train[1] = map(int, input().split())
bus[0], bus[1] = map(int, input().split())

# Calculate the sum
# The code then calculates the sum of the minimum values from both arrays.
result = min(train[0], train[1]) + min(bus[0], bus[1])

# Output the result
# Finally, the result is printed to the console.
print(result)

# End-of-code comment
