

a = int(input("Enter the number of seconds: ")) # Read an integer value from the standard input stream and assign it to the variable a

hours = a // (60 * 60) # Extract the hours from the number of seconds
minutes = (a % (60 * 60)) // 60 # Extract the minutes from the remaining seconds
seconds = (a % (60 * 60)) % 60 # Extract the seconds from the remaining seconds

print(f"{hours}:{minutes}:{seconds}") # Print the time representation of the number of seconds

