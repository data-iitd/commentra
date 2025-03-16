
# Import the datetime module
import datetime

# Read the first time string from the console and split it into hour and minute parts
s = input ( ).split ( ":" )

# Read the second time string from the console and split it into hour and minute parts
t = input ( ).split ( ":" )

# Create datetime objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
x = datetime.time ( int ( s [ 0 ] ), int ( s [ 1 ] ) )
y = datetime.time ( int ( t [ 0 ] ), int ( t [ 1 ] ) )

# Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
print ( x - y )

