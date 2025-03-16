# Prompt the user for input and convert it to an integer
# This input is expected to be the day of the month (1-31)
day_of_month = int(input())

# Calculate the absolute difference between the input day and 25
# This represents how many days away from Christmas (December 25) the input day is
days_until_christmas = abs(day_of_month - 25)

# Construct the output string by concatenating 'Christmas' with ' Eve' repeated
# The number of times ' Eve' is repeated corresponds to the number of days until Christmas
# If the input is 25, it will print 'Christmas' with no ' Eve' appended
output = 'Christmas' + ' Eve' * days_until_christmas

# Print the final output
print(output)
