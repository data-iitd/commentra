
a = int(input()) # Take an integer input from the user and store it in variable a
hours = a // (60 * 60) # Calculate the number of hours
minutes = (a % (60 * 60)) // 60 # Calculate the number of minutes
seconds = (a % (60 * 60)) % 60 # Calculate the number of seconds
print(f"{hours}:{minutes}:{seconds}") # Output the hours, minutes, and seconds

