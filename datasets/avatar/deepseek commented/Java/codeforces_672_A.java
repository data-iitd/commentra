
import java.util.Scanner ; 

public class Main { 
    // This method generates a string of numbers from 1 to 1000
    static char [ ] generateString ( ) { 
        StringBuilder sb = new StringBuilder ( ) ; 
        for ( int i = 1 ; i <= 1000 ; i ++ ) { 
            sb.append ( i ) ; 
        } 
        return sb.toString ( ).toCharArray ( ) ; 
    } 

    // The main method reads an integer n from the user, and prints the nth character of the generated string
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; 
        System.out.println ( generateString ( ) [ n - 1 ] ) ; 
    } 
}

