
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws Exception { 
        Scanner sc = new Scanner ( System.in ) ; // Step 1: Read input from the user
        String str = sc.next ( ) ; // Step 2: Read the input string
        char [ ] c = str.toCharArray ( ) ; // Step 3: Convert the string to a character array
        long k = sc.nextLong ( ) ; // Step 4: Read the value of k
        int n = str.length ( ) ; // Step 5: Initialize the length of the string
        
        for ( int i = 0 ; i < k ; i ++ ) { // Step 6: Loop through the character array k times
            if ( c [ i ] == '1' ) { // Step 7: Check if the character at the current index is '1'
                if ( i == k - 1 ) { // Step 8: Check if the current index is the last index
                    System.out.println ( 1 ) ; // Step 9: Print '1' and return
                    return ; 
                } 
            } else { // Step 10: If it is not '1'
                System.out.println ( c [ i ] ) ; // Step 11: Print the character and return
                return ; 
            } 
        } 
    } 
}

