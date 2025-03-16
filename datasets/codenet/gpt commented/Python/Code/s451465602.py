# Read an integer input representing the total number of seconds
n = int(input())

# Calculate the number of hours by dividing total seconds by 3600
h = int(n / 3600)

# Update n to the remainder of seconds after extracting hours
n %= 3600

# Calculate the number of minutes by dividing the remaining seconds by 60
m = int(n / 60)

# Update n to the remainder of seconds after extracting minutes
n %= 60

# The remaining value of n is the number of seconds
s = int(n)

# Print the time in the format "hours:minutes:seconds"
print(str(h) + ":" + str(m) + ":" + str(s))
