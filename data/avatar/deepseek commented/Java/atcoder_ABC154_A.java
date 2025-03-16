
import java.io.BufferedReader ; 
import java.io.InputStreamReader ; 
import java.io.IOException ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        // Create a BufferedReader to read input from the standard input stream
        BufferedReader in = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        
        // Read the first line of input, split by spaces, and store in an array of strings
        String [ ] str = in.readLine ( ).split ( " " ) ; 
        
        // Create a StringTokenizer to parse the next line of input as integers
        StringTokenizer st = new StringTokenizer ( in.readLine ( ) ) ; 
        
        // Parse the first integer from the tokenized input
        int a = Integer.parseInt ( st.nextToken ( ) ) ; 
        
        // Parse the second integer from the tokenized input
        int b = Integer.parseInt ( st.nextToken ( ) ) ; 
        
        // Read another string from the input
        String u = in.readLine ( ) ; 
        
        // Check if the read string is equal to the first element of the array and print accordingly
        System.out.println ( u.equals ( str [ 0 ] ) ? ( a - 1 ) + " " + b : a + " " + ( b - 1 ) ) ; 
    } 
}

