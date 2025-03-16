// Importing required classes for file I/O and Scanner
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

// Main method starts the execution of the program
public static void main ( String [ ] args ) throws IOException {
    Scanner sc = new Scanner ( System.in ); // Initialize Scanner for user input
    BufferedWriter bw = new BufferedWriter ( new OutputStreamWriter ( System.out ) ); // Initialize BufferedWriter for output
    int H; // Height of the grid
    int W; // Width of the grid
    int A; // Number of columns in the first row
    int B; // Number of rows in the last row

    // Read input values for H, W, A, and B
    H = sc.nextInt ( );
    W = sc.nextInt ( );
    A = sc.nextInt ( );
    B = sc.nextInt ( );

    // Check if the grid dimensions meet the conditions
    if ( W < 2 * A || H < 2 * B ) {
        System.out.println ( - 1 ); // Print -1 if the conditions are not met
        return; // Exit the program
    }

    // Write the grid to the output
    for ( int i = 0 ; i < H ; i ++ ) {
        for ( int j = 0 ; j < W ; j ++ ) {
            // Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ( ( i < B && j < A ) || ( i >= B ) && ( j >= A ) )
                bw.write ( "0" );
            else
                bw.write ( "1" );
        }
        bw.newLine ( ); // Move to the next line after writing a row
    }

    // Flush the buffer to write the output to the console
    bw.flush ( );

}

