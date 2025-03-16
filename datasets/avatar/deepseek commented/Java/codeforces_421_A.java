
import java.math.BigInteger ; 
import java.nio.charset.IllegalCharsetNameException ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Step 3: Create a Scanner object to read input from the user
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Step 4: Read the values of n, a, and b
        int n , a , b ; 
        n = sc.nextInt ( ) ; 
        a = sc.nextInt ( ) ; 
        b = sc.nextInt ( ) ; 
        
        // Step 5: Create two ArrayList objects to store the lists of integers
        ArrayList < Integer > list1 = new ArrayList < > ( ) ; 
        ArrayList < Integer > list2 = new ArrayList < > ( ) ; 
        
        // Step 6: Read the elements of list1 and list2 from the user
        for ( int i = 0 ; i < a ; i ++ ) { 
            list1.add ( sc.nextInt ( ) ) ; 
        } 
        for ( int i = 0 ; i < b ; i ++ ) { 
            list2.add ( sc.nextInt ( ) ) ; 
        } 
        
        // Step 7: Iterate through the range from 1 to n and print the appropriate list number
        for ( int i = 0 ; i < n ; i ++ ) { 
            if ( list1.contains ( i + 1 ) ) { 
                System.out.print ( 1 + " " ) ; 
            } else { 
                System.out.print ( 2 + " " ) ; 
            } 
        } 
    } 
}

