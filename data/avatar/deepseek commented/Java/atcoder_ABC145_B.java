
import java.util.* ; 
import java.math.* ; 

public class Main { 
    public static void cout ( String str ) { 
        System.out.println ( str ) ; 
    } 
    
    public static void main ( String args [ ] ) { 
        Scanner cin = new Scanner ( System.in ) ; 
        
        // Reading the integer input n
        int n ; 
        n = cin.nextInt ( ) ; 
        cin.nextLine ( ) ; 
        
        // Reading the string input str
        String a = "" , b = "" , str ; 
        str = cin.nextLine ( ) ; 
        
        // Constructing the string a by taking the first n/2 characters of str
        for ( int i = 0 ; i < n / 2 ; i ++ ) { 
            a = a + str.charAt ( i ) ; 
        } 
        
        // Checking if str is equal to a + a and printing the result
        if ( str.equals ( a + a ) ) 
            cout ( "Yes" ) ; 
        else 
            cout ( "No" ) ; 
    } 
} ;

