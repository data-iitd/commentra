
import datetime

# Step 1: Read two times from the user, split by colon and convert to LocalTime objects
s = input ( ).split ( ":" )
t = input ( ).split ( ":" )
x = datetime.time ( int ( s [ 0 ] ) , int ( s [ 1 ] ) )
y = datetime.time ( int ( t [ 0 ] ) , int ( t [ 1 ] ) )

# Step 2: Calculate the difference between the two times
print ( x - y )

