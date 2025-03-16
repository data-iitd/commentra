# Read an integer input from the user, which represents time in seconds
a = int(input())

# Calculate and display the time in hours, minutes, and seconds
# a // (60 * 60) calculates the number of hours
# (a // 60) % 60 calculates the number of minutes
# a % 60 calculates the remaining seconds
print(f"{a // (60 * 60)}:{((a // 60) % 60)}:{a % 60}")

# End of code
