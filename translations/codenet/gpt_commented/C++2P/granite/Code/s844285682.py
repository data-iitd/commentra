
a = int(input()) # Read an integer input from the user, which represents time in seconds
hours = a // (60 * 60) # Calculate the number of hours
minutes = (a % (60 * 60)) // 60 # Calculate the number of minutes
seconds = (a % (60 * 60)) % 60 # Calculate the remaining seconds
print(f"{hours}:{minutes}:{seconds}") # Display the time in hours, minutes, and seconds

