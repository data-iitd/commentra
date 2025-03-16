
import java.io.PrintWriter ; 
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Step 1: Create a Scanner object to read input from the standard input stream.
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Step 2: Read the first integer A from the input.
        int A = Integer.parseInt ( sc.next ( ) ) ; 
        
        // Step 3: Read the second integer B from the input.
        int B = Integer.parseInt ( sc.next ( ) ) ; 
        
        // Step 4: Initialize variables to store the quotient and remainder.
        int amari = 0 ; 
        int result = 0 ; 
        
        // Step 5: Calculate the quotient (result) by dividing (B-1) by (A-1).
        result = ( B - 1 ) / ( A - 1 ) ; 
        
        // Step 6: Calculate the remainder (amari) by taking the modulus of (B-1) by (A-1).
        amari = ( B - 1 ) % ( A - 1 ) ; 
        
        // Step 7: If the remainder is not zero, increment the result by 1.
        if ( amari!= 0 ) { 
            result += 1 ; 
        } 
        
        // Step 8: Create a PrintWriter object to write output to the standard output stream.
        PrintWriter out = new PrintWriter ( System.out ) ; 
        
        // Step 9: Print the result to the standard output.
        out.println ( result ) ; 
        
        // Step 10: Close the Scanner object to free up resources.
        sc.close ( ) ; 
        
        // Step 11: Flush the PrintWriter to ensure all output is written to the output stream.
        out.flush ( ) ; 
    } 
}

