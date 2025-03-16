
# Python 3 program to find the number of days
# until Sunday

# Initialize week array with 7 days of the week
week = ["Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"]

# Read input string from user
s = input("Enter a day of the week: ")

# Find index of the given day in week array
index = -1
for i in range(len(week)):
    if week[i] == s:
        index = i
        break

# If the given day is not present in the week array,
# print error message
if index == -1:
    print("Invalid day of the week")

# Calculate the number of days between the given day and Sunday
# and print the result
daysUntilSunday = 7 - index
print("The number of days until Sunday is:", daysUntilSunday)

# This code is contributed by <NAME>

