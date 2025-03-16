def leapyear(n):  # Function to check if a year is a leap year
    if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
        return "y"
    else:
        return "n"

n = int(input())  # Take an integer input from the user
d = "f"  # Initialize the variable d to "f"

# Determine if the year is a leap year and initialize ans accordingly
if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
    ans = "ly"
else:
    ans = "nly"

# Start an infinite loop to find the next Friday the 13th
while (True):
    if (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):  # Check if n is a leap year
        if (d == "m"):  # Update d and n based on the current day
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

    # Check if the current day is Friday and the year is a leap year or not
    if (d == "f" and ans == "ly" and leapyear(n) == "y"):
        break  # Exit the loop if the condition is met
    elif (d == "f" and ans == "nly" and leapyear(n) == "n"):
        break  # Exit the loop if the condition is met

print(n)  # Print the final year after finding the next Friday the 13th
