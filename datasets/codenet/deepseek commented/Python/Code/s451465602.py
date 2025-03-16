n = int(input())  # Take an integer input representing total seconds
h = int(n / 3600)  # Calculate the number of hours
n %= 3600  # Update n to the remainder of the division by 3600
m = int(n / 60)  # Calculate the number of minutes
n %= 60  # Update n to the remainder of the division by 60
s = int(n)  # Calculate the remaining seconds
print(str(h) + ":" + str(m) + ":" + str(s))  # Print the time in "hours:minutes:seconds" format
