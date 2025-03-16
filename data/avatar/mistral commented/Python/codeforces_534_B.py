# Get the initial values of v1, v2, t, and d from user input
v1, v2 = input().split()
t, d = input().split()

# Convert the input strings to integers
v1 = int(v1)
v2 = int(v2)
t = int(t)
d = int(d)

# Initialize variables
a = 1
v = v1
distance = 0

# For loop to calculate the total distance
for i in range(t):
    # Check if v is ahead of v2 by more than the difference * (time - i)
    if v - v2 > (t - i) * d:
        # If so, change the direction of acceleration
        a *= -1
        # Update the position of v
        v = (t - i) * d + v2

    # Add the current position of v to the total distance
    distance += v

    # Update the position of v based on the acceleration
    v += a * d

# Print the total distance
print(distance)
