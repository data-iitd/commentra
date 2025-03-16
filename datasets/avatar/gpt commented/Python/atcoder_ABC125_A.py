# Read input values for 'a', 'b', and 't' from the user
a, b, t = map(int, input().split())

# Initialize the cookie count to zero
cookie = 0

# Set the initial time to 'a'
time = a

# Loop until the time exceeds 't + 0.5'
while time <= t + 0.5:
    # Add 'b' cookies for each time interval
    cookie += b
    # Increment the time by 'a' for the next iteration
    time += a

# Print the total number of cookies collected
print(cookie)
