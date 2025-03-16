
import sys

# Reading the input from the console
h = int ( sys.stdin.readline ( ).strip ( ) )
w = int ( sys.stdin.readline ( ).strip ( ) )
n = int ( sys.stdin.readline ( ).strip ( ) )

sr = int ( sys.stdin.readline ( ).strip ( ) )
sc = int ( sys.stdin.readline ( ).strip ( ) )

s = sys.stdin.readline ( ).strip ( )
t = sys.stdin.readline ( ).strip ( )

# Initializing a boolean variable to keep track of whether the safe zone is valid or not
end = False

# Initializing two variables to keep track of the upper and lower boundaries of the safe zone
usafe = 1
dsafe = h

# The first for loop is to check the vertical boundaries of the safe zone based on the sequence's'
for i in range ( n - 1, -1, -1 ) :
    if s [ i ] == 'U' :  # If the current character in the sequence's' is 'U', increase the upper boundary by 1
        usafe += 1
    elif s [ i ] == 'D' :  # If the current character in the sequence's' is 'D', decrease the lower boundary by 1
        dsafe -= 1
    if usafe > dsafe :  # If the upper boundary is greater than the lower boundary, the safe zone is not valid
        end = True
        break
    if i > 0 :  # If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
        if t [ i - 1 ] == 'U' :
            dsafe = min ( dsafe + 1, h )  # If the previous character is 'U', increase the lower boundary by 1 to the minimum of the height
        elif t [ i - 1 ] == 'D' :
            usafe = max ( usafe - 1, 1 )  # If the previous character is 'D', decrease the upper boundary by 1 to the maximum of 1

# Initializing two variables to keep track of the left and right boundaries of the safe zone
lsafe = 1
rsafe = w

# The second for loop is to check the horizontal boundaries of the safe zone based on the sequence 't'
for i in range ( n - 1, -1, -1 ) :
    if s [ i ] == 'L' :  # If the current character in the sequence's' is 'L', increase the left boundary by 1
        lsafe += 1
    elif s [ i ] == 'R' :  # If the current character in the sequence's' is 'R', decrease the right boundary by 1
        rsafe -= 1
    if lsafe > rsafe :  # If the left boundary is greater than the right boundary, the safe zone is not valid
        end = True
        break
    if i > 0 :  # If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
        if t [ i - 1 ] == 'L' :
            rsafe = min ( rsafe + 1, w )  # If the previous character is 'L', increase the right boundary by 1 to the minimum of the width
        elif t [ i - 1 ] == 'R' :
            lsafe = max ( lsafe - 1, 1 )  # If the previous character is 'R', decrease the left boundary by 1 to the maximum of 1

# Checking if the starting position of the safe zone is within the safe zone boundaries and the safe zone is valid
if sr >= usafe and sr <= dsafe and sc >= lsafe and sc <= rsafe and not end :
    print ( "YES" )
else :
    print ( "NO" )

# 