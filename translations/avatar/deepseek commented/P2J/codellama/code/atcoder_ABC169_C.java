
public class Main {
    public static void main ( String [ ] args ) {
        // Set the recursion limit to avoid infinite recursion
        setRecursionLimit ( 1000000 );
        
        // Debugging function to print debug information if TERM_PROGRAM is in environ
        dbg = ( ) -> {
            if ( "TERM_PROGRAM".equals ( System.getenv ( "TERM_PROGRAM" ) ) ) {
                System.out.println ( );
            }
        };
        
        // Function to read input from stdin without trailing whitespace
        input = ( ) -> {
            return new Scanner ( System.in ).nextLine ( ).trim ( );
        };
        
        // Helper function to read a list of integers
        LMIIS = ( ) -> {
            return Arrays.stream ( input ( ).split ( " " ) ).mapToInt ( Integer::parseInt ).toArray ( );
        };
        
        // Helper function to read a single integer
        II = ( ) -> {
            return Integer.parseInt ( input ( ) );
        };
        
        // Constant for modulo operation
        P = 1000000007;
        
        // Constant for infinity
        INF = 1000000000;
        
        // Read two inputs, convert one to integer and the other to scaled integer
        String [ ] sa = input ( ).split ( " " );
        int a = Integer.parseInt ( sa [ 0 ] );
        int b = ( int ) ( Double.parseDouble ( sa [ 1 ] ) * 100 + 0.1 );
        
        // Perform the calculation and print the result
        System.out.println ( a * b / 100 );
    }
}

