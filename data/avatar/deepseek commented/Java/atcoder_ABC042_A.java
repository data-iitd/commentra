
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        // Create a BufferedReader to read input from the user
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        
        // Read a line of input from the user
        String line = br.readLine ( ) ; 
        
        // Split the input line into an array of strings
        String [ ] list = line.split ( " " ) ; 
        
        // Parse the first three elements of the array as integers
        int x = Integer.parseInt ( list [ 0 ] ) ; 
        int a = Integer.parseInt ( list [ 1 ] ) ; 
        int y = Integer.parseInt ( list [ 2 ] ) ; 
        
        // Initialize a variable to store the result
        String h = "NO" ; 
        
        // Check if any of the integers is either 5 or 7
        if ( x == 5 | x == 7 | a == 5 | a == 7 | y == 5 | y == 7 ) { 
            // Check if the sum of the integers is 17
            if ( x + y + a == 17 ) { 
                h = "YES" ; 
            } 
        } 
        
        // Print the result
        System.out.println ( h ) ; 
    } 
}

