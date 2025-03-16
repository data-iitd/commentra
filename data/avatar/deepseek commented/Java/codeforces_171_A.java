
import java.io.* ; 
import java.util.* ; 

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
    
    public static void main ( String [ ] args ) { 
        FastReader sc = new FastReader ( ) ; 
        int n = sc.nextInt ( ) ; // Read the first integer
        int m = sc.nextInt ( ) ; // Read the second integer
        int t = reverse ( m ) ; // Reverse the second integer
        System.out.println ( t + n ) ; // Print the sum of the reversed integer and the first integer
    } 
    
    public static int reverse ( int n ) { 
        if ( n < 10 ) return n * 10 ; // If the number is a single digit, return it multiplied by 10
        int t = n , r = 0 ; 
        while ( t > 0 ) { 
            r = ( r * 10 ) + t % 10 ; // Reverse the number
            t = t / 10 ; 
        } 
        return r ; 
    } 
}
