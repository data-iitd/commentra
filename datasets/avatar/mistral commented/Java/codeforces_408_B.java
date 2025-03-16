
import java.io.* ;  // For handling input/output
import java.lang.* ; // Standard Java library
import java.util.* ; // Collection framework and other utilities

public class Main {

    public static void main ( String [ ] args ) {
        Scanner s = new Scanner ( System.in ) ; // Create a Scanner object to read input from the console

        String s1 = s.next ( ) ; // Read the first string from the input
        String s2 = s.next ( ) ; // Read the second string from the input

        if ( isValid ( s1 , s2 ) == false ) { // Check if the given strings are valid
            System.out.println ( - 1 ) ; // If not valid, print -1 and exit
        } else { // If the strings are valid, proceed with the computation
            HashMap < Character , Integer > m1 = new HashMap < > ( ) ; // Create a HashMap to store the frequency of characters in the first string
            HashMap < Character , Integer > m2 = new HashMap < > ( ) ; // Create a HashMap to store the frequency of characters in the second string

            for ( char c : s1.toCharArray ( ) ) { // Iterate through each character in the first string
                if ( m1.containsKey ( c ) ) { // If the character is already in the HashMap, increment its count
                    m1.put ( c , m1.get ( c ) + 1 ) ;
                } else { // If the character is not in the HashMap, add it with a count of 1
                    m1.put ( c , 1 ) ;
                }
            }

            for ( char c : s2.toCharArray ( ) ) { // Iterate through each character in the second string
                if ( m2.containsKey ( c ) ) { // If the character is already in the HashMap, increment its count
                    m2.put ( c , m2.get ( c ) + 1 ) ;
                } else { // If the character is not in the HashMap, add it with a count of 1
                    m2.put ( c , 1 ) ;
                }
            }

            int ans = 0 ; // Initialize the answer variable to 0
            HashSet < Character > hs = new HashSet < > ( ) ; // Create a HashSet to store unique characters in the second string

            for ( char c : s2.toCharArray ( ) ) { // Iterate through each character in the second string
                if ( ! hs.contains ( c ) ) { // If the character is not already in the HashSet, add it and compute the answer
                    hs.add ( c ) ;
                    int x1 = m1.get ( c ) ; // Get the count of the character in the first string
                    int x2 = m2.get ( c ) ; // Get the count of the character in the second string
                    x1 = Math.min ( x1 , x2 ) ; // Take the minimum count
                    ans += x1 ; // Add the minimum count to the answer
                }
            }

            System.out.println ( ans ) ; // Print the answer
        }
    }

    public static boolean isValid ( String s1 , String s2 ) { // Check if the given strings are valid
        int n1 = s1.length ( ) ; // Get the length of the first string
        int n2 = s2.length ( ) ; // Get the length of the second string

        HashMap < Character , Boolean > map = new HashMap < > ( ) ; // Create a HashMap to store the presence of characters in the first string

        for ( char c : s1.toCharArray ( ) ) { // Iterate through each character in the first string
            map.put ( c , true ) ; // Mark the character as present in the HashMap
        }

        for ( char c : s2.toCharArray ( ) ) { // Iterate through each character in the second string
            if ( ! map.containsKey ( c ) ) { // If the character is not present in the first string, return false
                return false ;
            }
        }

        return true ; // If all characters in the second string are present in the first string, return true
    }
}