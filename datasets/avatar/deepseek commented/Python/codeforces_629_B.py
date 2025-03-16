
import sys
input = sys.stdin.readline

# Define the maximum number of time slots
N = 368

# Initialize lists to store changes for males and females
m = [ 0 ] * N
f = [ 0 ] * N

# Read the number of operations
for i in range ( int ( input ( ) ) ) :
    # Read each line, strip newline, and split into gender, start time, and end time
    x , a , b = input ( ) [ : - 1 ].split ( )
    a = int ( a )
    b = int ( b ) + 1
    
    # Update the changes in the lists based on gender
    if x == 'M' :
        m [ a ] += 2
        m [ b ] -= 2
    else :
        f [ a ] += 2
        f [ b ] -= 2

# Initialize variables to store the maximum number of people and the current number of people
a , b , c = 0 , 0 , 0

# Calculate the cumulative sum of changes and find the maximum number of people at any time slot
for i in range ( N ) :
    a += m [ i ]
    b += f [ i ]
    if min ( a , b ) > c :
        c = min ( a , b )

# Print the maximum number of people at any time slot
print ( c )

