# Importing required classes for file I/O and Scanner
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

# Main method starts the execution of the program
def main ( ):
    sc = Scanner ( System.in ) # Initialize Scanner for user input
    bw = BufferedWriter ( OutputStreamWriter ( System.out ) ) # Initialize BufferedWriter for output
    H = sc.nextInt ( ) # Read input values for H, W, A, and B
    W = sc.nextInt ( )
    A = sc.nextInt ( )
    B = sc.nextInt ( )

    # Check if the grid dimensions meet the conditions
    if ( W < 2 * A or H < 2 * B ):
        print ( - 1 ) # Print -1 if the conditions are not met
        return # Exit the program

    # Write the grid to the output
    for i in range ( H ):
        for j in range ( W ):
            # Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ( ( i < B and j < A ) or ( i >= B ) and ( j >= A ) ):
                bw.write ( "0" )
            else:
                bw.write ( "1" )
        bw.newLine ( ) # Move to the next line after writing a row

    # Flush the buffer to write the output to the console
    bw.flush ( )

# 