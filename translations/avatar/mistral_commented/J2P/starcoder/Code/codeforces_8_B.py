
# Importing the Scanner class for reading input
import java.util.Scanner ;

# Defining the Main class
class Main:
    # Defining the main method
    def main ( self ) :
        scan = java.util.Scanner ( ) ; # Creating a new Scanner object for reading input from the console

        i, j, x = 0, 0, 0, 0, 0, 0 ; # Declaring and initializing variables
        flag = True ; # Declaring and initializing a boolean variable
        s = scan.next ( ) ; # Reading the input string from the console
        ch = s.toCharArray ( ) ; # Converting the String to a character array
        co = [ [ 0 for i in range ( 101 ) ] for j in range ( 2 ) ] ; # Declaring and initializing a 2D integer array of size 2 x 101

        co [ 0 ] [ 0 ] = x ; co [ 1 ] [ 0 ] = y ; # Initializing the first element of the array with x and y values
        k = 1 ; # Incrementing the size of the array

        for i in range ( 0, s.length ( ) ) : # Loop to iterate through each character in the string
            if ( ch [ i ] == 'L' ) : x -= 1 ; # Move x to the left
            elif ( ch [ i ] == 'R' ) : x += 1 ; # Move x to the right
            elif ( ch [ i ] == 'U' ) : y += 1 ; # Move y up
            elif ( ch [ i ] == 'D' ) : y -= 1 ; # Move y down

            co [ 0 ] [ k ] = x ; co [ 1 ] [ k ] = y ; # Updating the current position in the array
            k += 1 ; # Incrementing the size of the array

        for i in range ( 0, k - 3 ) : # Outer loop to iterate through all elements except the last three
            for j in range ( i + 3, k ) : # Inner loop to compare the current element with the next three elements
                dx = co [ 0 ] [ i ] - co [ 0 ] [ j ] ; # Calculate the difference in x-coordinates
                dy = co [ 1 ] [ i ] - co [ 1 ] [ j ] ; # Calculate the difference in y-coordinates
                if ( dx < 0 ) dx *= ( -1 ) ; # Making dx positive if it's negative
                if ( dy < 0 ) dy *= ( -1 ) ; # Making dy positive if it's negative
                if ( ( dx <= 1 and dy == 0 ) or ( dy <= 1 and dx == 0 ) ) : # Checking if the difference is within 1 unit in either x or y direction
                    flag = False ; # Setting the flag to false if a difference of 1 unit is found
                    break ; # Exiting the inner loop if a difference of 1 unit is found
            if ( not flag ) break ; # Exiting the outer loop if a difference of 1 unit is found in any of the inner loops
        if ( flag ) print ( "OK" ) ; # Printing "OK" if no difference of 1 unit is found
        else print ( "BUG" ) ; # Printing "BUG" if a difference of 1 unit is found

# 