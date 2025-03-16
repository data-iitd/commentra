# Function to check if a year is a leap year
def leapyear(n):
    # Check if the year is a leap year by checking if it satisfies the conditions
    if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
        # If the conditions are met, return "y" to indicate that the year is a leap year
        return "y"
    else:
        # If the conditions are not met, return "n" to indicate that the year is not a leap year
        return "n"

# Take an integer input from the user
n = int(input())

# Initialize a variable 'd' to keep track of the day of the week for the given year
d = "f"

# Check if the given year is a leap year
if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
    # If the year is a leap year, set the answer to "ly"
    ans = "ly"
else:
    # If the year is not a leap year, set the answer to "nly"
    ans = "nly"

# Keep updating the day of the week and the year until we find the correct answer
while (True):
    # Check if the given year is a leap year
    if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
        # If the year is a leap year, update the day of the week accordingly
        if (d == "m"):
            d = "w"
            n += 1
        elif (d == "t"):
            d = "th"
            n += 1
        elif (d == "w"):
            d = "f"
            n += 1
        elif (d == "th"):
            d = "sa"
            n += 1
        elif (d == "f"):
            d = "s"
            n += 1
        elif (d == "sa"):
            d = "m"
            n += 1
        elif (d == "s"):
            d = "t"
            n += 1
    else:
        # If the year is not a leap year, update the day of the week accordingly
        if (d == "m"):
            d = "t"
            n += 1
        elif (d == "t"):
            d = "w"
            n += 1
        elif (d == "w"):
            d = "th"
            n += 1
        elif (d == "th"):
            d = "f"
            n += 1
        elif (d == "f"):
            d = "sa"
            n += 1
        elif (d == "sa"):
            d = "s"
            n += 1
        elif (d == "s"):
            d = "m"
            n += 1

    # Check if we have found the correct answer
    if (d == "f" and ans == "ly" and leapyear(n) == "y"):
        # If we have found the correct answer, break out of the loop
        break
    elif (d == "f" and ans == "nly" and leapyear(n) == "n"):
        # If we have found the correct answer, break out of the loop
        break

# Print the result
print(n)
