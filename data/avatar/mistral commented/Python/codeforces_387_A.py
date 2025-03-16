# Define the first hour and minute variables from user input
h1, m1 = map(int, input().split(':'))

# Add the hour to the minute value
m1 += h1 * 60

# Define the second hour and minute variables from user input
h2, m2 = map(int, input().split(':'))

# Add the hour to the minute value for the second set of variables
m2 += h2 * 60

# Calculate the difference between the total minutes of the first and second sets of variables
m2 = m1 - m2

# Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
m2 %= 1440

# Print the result in the format of hours and minutes
print(f"{m2 // 60:02d}:{m2 % 60:02d}")
