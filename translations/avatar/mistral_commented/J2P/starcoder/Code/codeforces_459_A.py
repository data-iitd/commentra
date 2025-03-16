
import sys ; // Import the sys module

def main ( ):
    in = sys.stdin ; // Create a standard input stream
    out = sys.stdout ; // Create a standard output stream

    x1 = int ( in.readline ( ) ) ; // Read the first x-coordinate
    y1 = int ( in.readline ( ) ) ; // Read the first y-coordinate
    x2 = int ( in.readline ( ) ) ; // Read the second x-coordinate
    y2 = int ( in.readline ( ) ) ; // Read the second y-coordinate

    if ( x1 == x2 ) :
        dif = abs ( y1 - y2 ) ; // Calculate the absolute difference between y1 and y2
        out.write ( str ( x1 + dif ) + " " + str ( y1 ) + " " + str ( x1 + dif ) + " " + str ( y2 ) + "\n" ) ; # Print the result to the standard output stream
    elif ( y1 == y2 ) :
        dif = abs ( x1 - x2 ) ; // Calculate the absolute difference between x1 and x2
        out.write ( str ( x1 ) + " " + str ( y1 + dif ) + " " + str ( x2 ) + " " + str ( y2 + dif ) + "\n" ) ; # Print the result to the standard output stream
    elif ( abs ( x1 - x2 ) == abs ( y1 - y2 ) ) :
        out.write ( str ( x1 ) + " " + str ( y2 ) + " " + str ( x2 ) + " " + str ( y1 ) + "\n" ) ; # Print the result to the standard output stream
    else :
        out.write ( str ( - 1 ) + "\n" ) ; # Print -1 to the standard output stream

    out.close ( ) ; # Close the standard output stream to free up system resources

if ( __name__ == '__main__' ) :
    main ( ) ; # Call the main function

