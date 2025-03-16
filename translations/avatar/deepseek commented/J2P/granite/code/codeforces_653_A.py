

n = int ( input ( ) ) # Read the number of integers
a = list ( map ( int, input ( ).split ( ) ) # Read the integers and store them in a list
a = sorted ( list ( set ( a ) ) ) # Remove duplicates and sort the list
found = False # Initialize a flag to check for consecutive integers
for i in range ( len ( a ) - 2 ) : 
    if a [ i ] + 1 == a [ i + 1 ] and a [ i + 1 ] + 1 == a [ i + 2 ] : 
        found = True # Set the flag if three consecutive integers are found
print ( "YES" if found else "NO" ) # Print "YES" if consecutive integers are found, otherwise print "NO"
