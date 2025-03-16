def leapyear(n):
    # Determine if the given year n is a leap year
    if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
        return "y"  # Return 'y' if it is a leap year
    else:
        return "n"  # Return 'n' if it is not a leap year

# Read an integer input from the user representing the year
n = int(input())

# Initialize the day variable to 'f' (Friday)
d = "f"

# Check if the initial year n is a leap year and set the answer accordingly
if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
    ans = "ly"  # 'ly' indicates leap year
else:
    ans = "nly"  # 'nly' indicates non-leap year

# Infinite loop to determine the next occurrence of a specific day
while True:
    # If the current year n is a leap year
    if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
        # Update the day variable and increment the year based on the current day
        if (d == "m"):
            d = "w"  # Monday to Wednesday
            n += 1
        elif (d == "t"):
            d = "th"  # Tuesday to Thursday
            n += 1
        elif (d == "w"):
            d = "f"  # Wednesday to Friday
            n += 1
        elif (d == "th"):
            d = "sa"  # Thursday to Saturday
            n += 1
        elif (d == "f"):
            d = "s"  # Friday to Sunday
            n += 1
        elif (d == "sa"):
            d = "m"  # Saturday to Monday
            n += 1
        elif (d == "s"):
            d = "t"  # Sunday to Tuesday
            n += 1
    else:
        # If the current year n is not a leap year, update the day variable accordingly
        if (d == "m"):
            d = "t"  # Monday to Tuesday
            n += 1
        elif (d == "t"):
            d = "w"  # Tuesday to Wednesday
            n += 1
        elif (d == "w"):
            d = "th"  # Wednesday to Thursday
            n += 1
        elif (d == "th"):
            d = "f"  # Thursday to Friday
            n += 1
        elif (d == "f"):
            d = "sa"  # Friday to Saturday
            n += 1
        elif (d == "sa"):
            d = "s"  # Saturday to Sunday
            n += 1
        elif (d == "s"):
            d = "m"  # Sunday to Monday
            n += 1

    # Check if we have reached a Friday and the leap year condition matches the answer
    if (d == "f" and ans == "ly" and leapyear(n) == "y"):
        break  # Exit the loop if it's a leap year and it's Friday
    elif (d == "f" and ans == "nly" and leapyear(n) == "n"):
        break  # Exit the loop if it's not a leap year and it's Friday

# Print the resulting year
print(n)
