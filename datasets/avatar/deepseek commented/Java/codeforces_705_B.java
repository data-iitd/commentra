import java.util.* ; 
import java.io.* ; 

public class Main { 
    static class FastReader { 
        BufferedReader br ; 
        StringTokenizer st ; 
        public FastReader ( ) { 
            br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        } 
        String next ( ) { 
            while ( st == null || ! st.hasMoreElements ( ) ) { 
                try { 
                    st = new StringTokenizer ( br.readLine ( ) ) ; 
                } catch ( IOException e ) { 
                    e.printStackTrace ( ) ; 
                } 
            } 
            return st.nextToken ( ) ; 
        } 
        int nextInt ( ) { 
            return Integer.parseInt ( next ( ) ) ; 
        } 
        long nextLong ( ) { 
            return Long.parseLong ( next ( ) ) ; 
        } 
        double nextDouble ( ) { 
            return Double.parseDouble ( next ( ) ) ; 
        } 
        String nextLine ( ) { 
            String str = "" ; 
            try { 
                str = br.readLine ( ) ; 
            } catch ( IOException e ) { 
                e.printStackTrace ( ) ; 
            } 
            return str ; 
        } 
    } 
    static FastReader scan = new FastReader ( ) ; 

    public static void main ( String [ ] args ) { 
        int t = 1 ; 
        while ( t -- > 0 ) { 
            solve ( ) ; 
        } 
    } 

    public static void solve ( ) { 
        int t = scan.nextInt ( ) ; // Read the number of test cases
        int [ ] arr = new int [ t ] ; // Initialize an array to store the elements
        for ( int i = 0 ; i < arr.length ; i ++ ) { 
            arr [ i ] = scan.nextInt ( ) ; // Read the elements of the array
        } 
        int prevWinner = 0 ; // Initialize the previous winner variable
        for ( int i = 0 ; i < arr.length ; i ++ ) { 
            if ( arr [ i ] == 1 ) { // Check if the current element is 1
                if ( prevWinner == 0 ) { // If no previous winner, set the winner to 2
                    prevWinner = 2 ; 
                } 
            } 
            if ( prevWinner == 2 || prevWinner == 0 ) { // Check if the previous winner is 2 or unset
                if ( ( arr [ i ] - 1 ) % 2 == 0 ) { // Check if the condition for player 2 is met
                    System.out.println ( 2 ) ; // Print the winner
                    prevWinner = 2 ; // Update the previous winner
                } else { 
                    System.out.println ( 1 ) ; // Print the winner
                    prevWinner = 1 ; // Update the previous winner
                } 
            } else { // If the previous winner is 1
                if ( ( arr [ i ] - 1 ) % 2 == 0 ) { // Check if the condition for player 1 is met
                    System.out.println ( 1 ) ; // Print the winner
                    prevWinner = 1 ; // Update the previous winner
                } else { 
                    System.out.println ( 2 ) ; // Print the winner
                    prevWinner = 2 ; // Update the previous winner
                } 
            } 
        } 
    } 
}