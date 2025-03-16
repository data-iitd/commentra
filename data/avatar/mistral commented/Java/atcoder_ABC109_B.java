
import java.util.HashMap ;  // Importing HashMap and Scanner classes
import java.util.Scanner ;

public class Main {

    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;  // Creating a Scanner object to read input
        int N = sc.nextInt ( ) ;  // Reading the number of strings from the input

        HashMap < Integer , String > map = new HashMap < > ( ) ;  // Creating an empty HashMap to store strings

        for ( int i = 0 ; i < N ; i ++ ) {  // Loop to read strings from the input and store them in the HashMap
            map.put ( i , sc.next ( ) ) ;
        }

        boolean ans = true ;  // Initializing a boolean variable to store the result of the check
        HashMap < Integer , String > past = new HashMap < > ( ) ;  // Creating an empty HashMap to store the previous strings
        String next = "" ;  // Initializing a string variable to store the next character of the current string

        for ( int i = 0 ; i < N ; i ++ ) {  // Loop to check for the condition
            if ( past.containsValue ( map.get ( i ) ) ) {  // Checking if the current string is already in the HashMap
                ans = false ;
                break ;
            }
            past.put ( i , map.get ( i ) ) ;  // Storing the current string in the HashMap

            if ( i != 0 ) {  // Checking if it's not the first iteration of the loop
                if ( ! next.equals ( map.get ( i ).substring ( 0 , 1 ) ) ) {  // Checking if the current string starts with the same character as the previous string
                    ans = false ;
                    break ;
                }
            }
            next = map.get ( i ).substring ( map.get ( i ).length ( ) - 1 , map.get ( i ).length ( ) ) ;  // Storing the last character of the current string in the next variable
        }

        if ( ans ) {  // Printing "Yes" if the condition is satisfied
            System.out.println ( "Yes" ) ;
        } else {  // Printing "No" if the condition is not satisfied
            System.out.println ( "No" ) ;
        }
    }
}