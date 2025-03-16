
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int num = sc.nextInt ( ) ; // Read the size of the grid
        int counter = 0 ; // Counter for the number of 'C's
        int fine = 0 ; // Fine amount to be calculated
        ArrayList < String > arr = new ArrayList < > ( ) ; // ArrayList to store the grid rows

        // Read num strings representing the grid rows
        for ( int i = 0 ; i < num ; i ++ ) { 
            String s = sc.next ( ) ; 
            arr.add ( s ) ; 
        } 

        // Calculate the fine for each column
        for ( int i = 0 ; i < num ; i ++ ) { 
            for ( int k = 0 ; k < num ; k ++ ) { 
                if ( arr.get ( k ).charAt ( i ) == 'C' ) { 
                    counter ++ ; 
                } 
            } 
            fine += ( counter * ( counter - 1 ) ) / 2 ; // Calculate the fine for the column
            counter = 0 ; // Reset the counter for the next column
        } 

        // Calculate the fine for each row
        for ( int i = 0 ; i < num ; i ++ ) { 
            for ( int k = 0 ; k < num ; k ++ ) { 
                if ( arr.get ( i ).charAt ( k ) == 'C' ) { 
                    counter ++ ; 
                } 
            } 
            fine += ( counter * ( counter - 1 ) ) / 2 ; // Calculate the fine for the row
            counter = 0 ; // Reset the counter for the next row
        } 

        // Print the total fine
        System.out.println ( fine ) ; 
    } 
}

