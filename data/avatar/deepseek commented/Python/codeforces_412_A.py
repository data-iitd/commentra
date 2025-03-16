
n , k = map ( int , input ( ).split ( ) )
# Input the number of elements (n) and the position index (k)

v = input ( )
# Input the string v

d = [ "LEFT" , "RIGHT" ]
# Define a list containing the directions "LEFT" and "RIGHT"

f = k - 1 < n - k
# Determine the boolean value of f based on the comparison between k-1 and n-k

m = min ( k - 1 , n - k )
# Assign m as the minimum of k-1 and n-k

a = [ ]
# Initialize an empty list a to store the sequence of actions

for i in range ( 0 , m ) :
    a.append ( d [ not f ] )
    # Append the opposite direction to a based on the value of f

for i in v [ : : -1 + 2 * f ] :
    a.append ( "PRINT " + i )
    a.append ( d [ f ] )
    # Iterate over the reversed string v with a step of 2*f-1, appending "PRINT" and the current character, followed by the direction f

print ( * a [ : -1 ] , sep = "\n" )
# Print all elements in a except the last one, separated by newlines

