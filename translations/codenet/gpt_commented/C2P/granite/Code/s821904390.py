
# Python code to convert seconds to hours, minutes, and seconds

# Read the total number of seconds from user input
in_seconds = int(input("Enter the total number of seconds: "))

# Calculate the number of hours by dividing total seconds by 3600
hours = in_seconds // 3600

# Update the input seconds to the remainder after extracting hours
in_seconds %= 3600

# Calculate the number of minutes by dividing the remaining seconds by 60
minutes = in_seconds // 60

# Update the input seconds to the remainder after extracting minutes
in_seconds %= 60

# The remaining seconds are now stored in 'in_seconds'
seconds = in_seconds

# Print the result in the format of hours:minutes:seconds
print(f"{hours}:{minutes}:{seconds}")

