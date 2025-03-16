

import sys

# Initialize week array with 7 days of the week
week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

# Read input string from scanner
s = input()

# Find index of the given day in week array
index = -1
for i, day in enumerate(week):
    if s == day:
        index = i
        break

# Print the result
print(7 - index)

