# Include necessary libraries
# The code starts by importing the necessary libraries for input and output operations.

# Input values
# The values for `train` and `bus` are taken from the user.
train = list(map(int, input().split()))
bus = list(map(int, input().split()))

# Calculate the sum
# The code then calculates the sum of the minimum values from both lists.
result = min(train[0], train[1]) + min(bus[0], bus[1])

# Output the result
print(result)

# <END-OF-CODE>
