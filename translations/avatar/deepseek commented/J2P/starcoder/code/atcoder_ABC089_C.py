
import sys ; 
# Import necessary libraries.

class TaskC:
    def __init__ ( self ):
        pass ; 
    # Constructor.

    def solve ( self, testNumber, in, out ):
        n = int ( in.readline ( ) )
        # Read the number of strings.

        cnt = [ 0 for i in range ( 5 ) ]
        # Initialize the count array.

        for i in range ( n ):
            str = in.readline ( ).strip ( )
            # Read a string.

            if ( str [ 0 ] == 'M' ):
                cnt [ 0 ] += 1
            elif ( str [ 0 ] == 'A' ):
                cnt [ 1 ] += 1
            elif ( str [ 0 ] == 'R' ):
                cnt [ 2 ] += 1
            elif ( str [ 0 ] == 'C' ):
                cnt [ 3 ] += 1
            elif ( str [ 0 ] == 'H' ):
                cnt [ 4 ] += 1
            # Count the occurrences of each character at the start of the strings.

        res = cnt [ 0 ] * cnt [ 1 ] * cnt [ 2 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 2 ] * cnt [ 3 ] * cnt [ 4 ]
        # Calculate the number of combinations.

        out.write ( str ( res ) + '\n' )
        # Print the result.

if __name__ == '__main__' :
    task = TaskC ( )
    # Create an instance of TaskC.

    task.solve ( 1, sys.stdin, sys.stdout )
    # Solve the problem.

