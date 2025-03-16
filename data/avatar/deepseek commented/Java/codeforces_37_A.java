
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Create an instance of FastScanner to read input efficiently
        FastScanner input = new FastScanner ( ) ; 
        
        // Read the number of integers
        int n = input.nextInt ( ) ; 
        
        // Create a HashMap to store the frequency of each integer
        HashMap < Integer , Integer > map = new HashMap < > ( ) ; 
        
        // Read n integers and update their counts in the hash map
        for ( int i = 0 ; i < n ; i ++ ) { 
            int val = input.nextInt ( ) ; 
            map.put ( val , map.getOrDefault ( val , 0 ) + 1 ) ; 
        } 
        
        // Initialize max to the smallest possible integer value
        int max = Integer.MIN_VALUE ; 
        
        // Iterate through the hash map to find the maximum count
        for ( Map.Entry < Integer , Integer > entry : map.entrySet ( ) ) { 
            Integer value = entry.getValue ( ) ; 
            max = Math.max ( max , value ) ; 
        } 
        
        // Print the maximum count and the size of the hash map
        System.out.println ( max + "" + map.size ( ) ) ; 
    } 
    
    // Utility class to read input efficiently
    static class FastScanner { 
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        StringTokenizer st = new StringTokenizer ( "" ) ; 
        
        // Method to read the next token
        String next ( ) { 
            while ( ! st.hasMoreTokens ( ) ) { 
                try { 
                    st = new StringTokenizer ( br.readLine ( ) ) ; 
                } catch ( IOException e ) { 
                    e.printStackTrace ( ) ; 
                } 
            } 
            return st.nextToken ( ) ; 
        } 
        
        // Method to read the next integer
        int nextInt ( ) { 
            return Integer.parseInt ( next ( ) ) ; 
        } 
        
        // Method to read the next long
        long nextLong ( ) { 
            return Long.parseLong ( next ( ) ) ; 
        } 
        
        // Method to read the next double
        double nextDouble ( ) { 
            return Double.parseDouble ( next ( ) ) ; 
        } 
        
        // Method to read the next line
        String nextLine ( ) throws IOException { 
            return br.readLine ( ) ; 
        } 
    } 
}
