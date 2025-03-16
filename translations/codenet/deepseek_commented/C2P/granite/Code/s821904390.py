
in = int(input())  # Read an integer input from the user, which represents the total time in seconds
h = in // 3600  # Calculate the number of hours by integer division
in %= 3600  # Update in to store the remainder of the division, which represents the remaining seconds
m = in // 60  # Calculate the number of minutes by integer division
in %= 60  # Update in to store the remainder of the division, which represents the remaining seconds
s = in  # The remaining value in in is the number of seconds
print(f"{h}:{m}:{s}")  # Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"

