
# <START-OF-CODE>

# Reading input values
h = int ( input ( ) ) # Height of the grid
w = int ( input ( ) ) # Width of the grid
n = int ( input ( ) ) # Number of moves
sr = int ( input ( ) ) # Starting row
sc = int ( input ( ) ) # Starting column

# Reading the moves
s = input ( ) # Sequence of moves in a string
t = input ( ) # Sequence of moves in a string

# Initializing variables to track safe bounds
end = False # Flag to check if an unsafe condition is encountered
usafe = 1 # Safe upper bound for row
dsafe = h # Safe lower bound for row

# Processing moves in reverse order for rows
for i in range ( n - 1, -1, -1 ) :
    if ( s [ i ] == 'U' ) :
        usafe += 1 # Move up, increase upper safe bound
    elif ( s [ i ] == 'D' ) :
        dsafe -= 1 # Move down, decrease lower safe bound
    if ( usafe > dsafe ) : # Check if upper safe bound exceeds lower safe bound
        end = True # Set end flag to true if unsafe
        break # Break out of the loop
    if ( i > 0 ) : # Check if it's not the first move
        if ( t [ i - 1 ] == 'U' ) :
            dsafe = min ( dsafe + 1, h ) # Adjust lower safe bound if previous move was up
        elif ( t [ i - 1 ] == 'D' ) :
            usafe = max ( usafe - 1, 1 ) # Adjust upper safe bound if previous move was down

# Initializing variables to track safe bounds for columns
lsafe = 1 # Safe left bound for column
rsafe = w # Safe right bound for column

# Processing moves in reverse order for columns
for i in range ( n - 1, -1, -1 ) :
    if ( s [ i ] == 'L' ) :
        lsafe += 1 # Move left, increase left safe bound
    elif ( s [ i ] == 'R' ) :
        rsafe -= 1 # Move right, decrease right safe bound
    if ( lsafe > rsafe ) : # Check if left safe bound exceeds right safe bound
        end = True # Set end flag to true if unsafe
        break # Break out of the loop
    if ( i > 0 ) : # Check if it's not the first move
        if ( t [ i - 1 ] == 'L' ) :
            rsafe = min ( rsafe + 1, w ) # Adjust right safe bound if previous move was left
        elif ( t [ i - 1 ] == 'R' ) :
            lsafe = max ( lsafe - 1, 1 ) # Adjust left safe bound if previous move was right

# Checking if the final position is safe
if ( sr >= usafe and sr <= dsafe and sc >= lsafe and sc <= rsafe and not end ) :
    print ( "YES" ) # Output YES if safe
else :
    print ( "NO" ) # Output NO if not safe

# 