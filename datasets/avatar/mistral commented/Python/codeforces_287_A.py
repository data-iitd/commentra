
t = [ ] # Initialize an empty list 't' to store the input strings

for i in range ( 4 ) : # Loop through 4 iterations to get input strings from user
    l = list ( map ( str , input ( ) ) ) # Convert input string to list of strings
    t.append ( l ) # Append the list to list 't'

black = 0 # Initialize black and white counters to 0
white = 0
correct = 0

for i in range ( 3 ) : # Loop through the first 3 rows of the 4x4 grid represented by list 't'
    for j in range ( 3 ) : # Loop through the first 3 columns of the current row
        if t [ i ] [ j ] == '#' : # If current cell contains '#', increment 'black' counter
            black += 1
        else : # If current cell contains '.', increment 'white' counter
            white += 1
        
        # Check the neighboring cells and increment 'black' or 'white' counter accordingly
        if t [ i ] [ j + 1 ] == '#' :
            black += 1
        else :
            white += 1
        
        if t [ i + 1 ] [ j ] == '#' :
            black += 1
        else :
            white += 1
        
        if t [ i + 1 ] [ j + 1 ] == '#' :
            black += 1
        else :
            white += 1
        
        # Check the current cell and its neighbors for winning conditions
        if ( black == 0 or black == 3 or white == 0 or white == 3 or white == 4 or black == 4 ) :
            correct = 1 # If a winning condition is met, set 'correct' to 1 and break out of the loop
            break
        
        # Reset black and white counters for the next iteration of the inner loop
        black = 0
        white = 0

if correct == 1 : # If 'correct' is set to 1, print 'YES'
    print ( 'YES' )
else : # If 'correct' is not set to 1, print 'NO'
    print ( 'NO' )