# Get the number of hours, minutes, and seconds from the user input
n = int(input())

# Calculate the number of hours from the total number of seconds
h = int(n / 3600)

# Calculate the remaining seconds after extracting the hours
n %= 3600

# Calculate the number of minutes from the remaining seconds
m = int(n / 60)

# Calculate the remaining seconds after extracting the minutes
n %= 60

# Format and print the output as hours:minutes:seconds
print(str(h) + ":" + str(m) + ":" + str(s))