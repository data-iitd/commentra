
import sys ; # Importing the sys module for reading input

def main ( ) : # Defining the main function
    scan = sys.stdin ; # Creating a new object for reading input from the console
    i, j, x, y, k, dx, dy, flag = 0, 0, 0, 0, 0, 0, 0, 0, True ; # Declaring and initializing variables
    s, ch, co = '', [ ], [ [ 0 for i in range ( 101 ) ] for j in range ( 2 ) ] ; # Declaring and initializing variables
    s = scan.readline ( ) ; # Reading the input string from the console
    ch = list ( s ) ; # Converting the String to a list of characters
    co [ 0 ] [ k ] = x ; co [ 1 ] [ k ] = y ; # Initializing the first element of the array with x and y values
    k += 1 ; # Incrementing the size of the array
    for i in range ( len ( s ) ) : # Loop to iterate through each character in the string
        if ( ch [ i ] == 'L' ) : # If the character is 'L'
            x -= 1 ; # Move x to the left
        elif ( ch [ i ] == 'R' ) : # If the character is 'R'
            x += 1 ; # Move x to the right
        elif ( ch [ i ] == 'U' ) : # If the character is 'U'
            y += 1 ; # Move y up
        elif ( ch [ i ] == 'D' ) : # If the character is 'D'
            y -= 1 ; # Move y down
        co [ 0 ] [ k ] = x ; co [ 1 ] [ k ] = y ; # Updating the current position in the array
        k += 1 ; # Incrementing the size of the array
    for i in range ( k - 3 ) : # Outer loop to iterate through all elements except the last three
        for j in range ( i + 3, k ) : # Inner loop to compare the current element with the next three elements
            dx = co [ 0 ] [ i ] - co [ 0 ] [ j ] ; # Calculate the difference in x-coordinates
            dy = co [ 1 ] [ i ] - co [ 1 ] [ j ] ; # Calculate the difference in y-coordinates
            if ( dx < 0 ) : # If dx is negative
                dx *= ( -1 ) ; # Make dx positive
            if ( dy < 0 ) : # If dy is negative
                dy *= ( -1 ) ; # Make dy positive
            if ( ( dx <= 1 and dy == 0 ) or ( dy <= 1 and dx == 0 ) ) : # If the difference is within 1 unit in either x or y direction
                flag = False ; # Set the flag to False if a difference of 1 unit is found
                break ; # Exit the inner loop if a difference of 1 unit is found
        if ( not flag ) : # If the flag is False
            break ; # Exit the outer loop if a difference of 1 unit is found in any of the inner loops
    if ( flag ) : # If the flag is True
        print ( "OK" ) ; # Print "OK" if no difference of 1 unit is found
    else : # If the flag is False
        print ( "BUG" ) ; # Print "BUG" if a difference of 1 unit is found

if __name__ == '__main__' : # If the script is run directly
    main ( ) ; # Call the main function