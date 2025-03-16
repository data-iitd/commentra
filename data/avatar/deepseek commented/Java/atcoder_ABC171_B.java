import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStream ; 
import java.io.InputStreamReader ; 
import java.io.OutputStream ; 
import java.io.PrintWriter ; 
import java.util.Arrays ; 
import java.util.StringTokenizer ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        InputStream inputStream = System.in ; 
        OutputStream outputStream = System.out ; 
        InputReader in = new InputReader ( inputStream ) ; 
        PrintWriter out = new PrintWriter ( outputStream ) ; 
        Solution sol = new Solution ( ) ; 
        sol.solve ( in , out ) ; 
        out.close ( ) ; 
    } 

    private static class Solution { 
        private void solve ( InputReader in , PrintWriter out ) { 
            int n = in.ni ( ) ; // Reads the number of elements (n)
            int k = in.ni ( ) ; // Reads the number of elements to consider (k)
            int [ ] a = new int [ n ] ; 
            for ( int i = 0 ; i < n ; ++ i ) 
                a [ i ] = in.ni ( ) ; // Reads the elements into an array
            Arrays.parallelSort ( a ) ; // Sorts the array
            int ans = 0 ; 
            for ( int i = 0 ; i < k ; ++ i ) 
                ans += a [ i ] ; // Sums the first k elements
            out.println ( ans ) ; // Prints the result
        } 
    } 

    private static class InputReader { 
        private BufferedReader reader ; 
        private StringTokenizer tokenizer ; 
        private InputReader ( InputStream stream ) { 
            reader = new BufferedReader ( new InputStreamReader ( stream ) , 32768 ) ; 
            tokenizer = null ; 
        } 
        private String n ( ) { 
            while ( tokenizer == null || ! tokenizer.hasMoreTokens ( ) ) { 
                try { 
                    tokenizer = new StringTokenizer ( reader.readLine ( ) ) ; 
                } catch ( IOException e ) { 
                    throw new RuntimeException ( e ) ; 
                } 
            } 
            return tokenizer.nextToken ( ) ; 
        } 
        private int ni ( ) { 
            return Integer.parseInt ( n ( ) ) ; 
        } 
    } 
}