# Declare an integer variable to hold the input seconds
in_seconds = int(input())

# Calculate the number of hours by dividing total seconds by 3600
h = in_seconds // 3600
# Update the input seconds to the remainder after extracting hours
in_seconds %= 3600

# Calculate the number of minutes by dividing the remaining seconds by 60
m = in_seconds // 60
# Update the input seconds to the remainder after extracting minutes
in_seconds %= 60

# The remaining seconds are now stored in 'in_seconds'
s = in_seconds

# Print the result in the format of hours:minutes:seconds
print(f"{h}:{m}:{s}")

# <END-OF-CODE>
