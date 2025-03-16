
import java.util.Scanner ; // Importing Scanner class for user input

public class Main {
    static Scanner scanner ; // Declaring and initializing scanner object

    public static void main ( String [ ] args ) {
        scanner = new Scanner ( System.in ) ; // Creating new scanner object for user input
        int N = gi () ; // Getting the value of N from user input

        long i = 357 ; // Initializing the variable i with a value of 357
        int c = 0 ; // Initializing the variable c with a value of 0

        while ( i <= N ) { // Starting a while loop that continues as long as i is less than or equal to N
            String s = String.valueOf ( i ) ; // Converting the integer value of i to a string

            if ( s.contains ( "3" ) && s.contains ( "5" ) && s.contains ( "7" ) ) { // Checking if the string contains the digits 3, 5, and 7
                c ++ ; // Incrementing the value of c by 1 if the condition is true
            }

            StringBuilder sb = new StringBuilder ( ) ; // Creating a new StringBuilder object
            boolean f = false ; // Initializing a boolean variable f with a value of false

            for ( int j = 0 ; j < s.length ( ) ; j ++ ) { // Starting a for loop that iterates through each character in the string s
                char a = s.charAt ( s.length ( ) - 1 - j ) ; // Getting the character at the current index in reverse order

                if ( f ) { // If the boolean variable f is true, meaning we have found the first occurrence of 3, 5, or 7
                    sb.append ( a ) ; // Appending the current character to the StringBuilder object
                } else { // If the boolean variable f is false, meaning we have not found the first occurrence of 3, 5, or 7 yet
                    if ( a == '3' ) { // Checking if the current character is a 3
                        sb.append ( '5' ) ; // If it is, append a 5 to the StringBuilder object and set f to true
                        f = true ;
                    } else if ( a == '5' ) { // Checking if the current character is a 5
                        sb.append ( '7' ) ; // If it is, append a 7 to the StringBuilder object and set f to true
                        f = true ;
                    } else { // If the current character is not a 3, 5, or 7, append a 3 to the StringBuilder object and set f to true
                        sb.append ( '3' ) ;
                        f = true ;
                    }
                }
            }

            if ( ! f ) sb.append ( 3 ) ; // If we have not found any 3, 5, or 7 in the string, append a 3 to the StringBuilder object

            StringBuffer sb2 = new StringBuffer ( sb ) ; // Creating a new StringBuffer object from the StringBuilder object
            i = Long.parseLong ( sb2.reverse ( ).toString ( ) ) ; // Converting the reversed string back to a long integer and assigning it to the variable i
        }

        System.out.println ( c ) ; // Printing the value of c to the console
    }

    public static String gs ( ) { // Method for reading a single string input from the user
        return scanner.next ( ) ;
    }

    public static int gi ( ) { // Method for reading a single integer input from the user
        return Integer.parseInt ( scanner.next ( ) ) ;
    }

    public static long gl ( ) { // Method for reading a single long integer input from the user
        return Long.parseLong ( scanner.next ( ) ) ;
    }

    public static double gd ( ) { // Method for reading a single double input from the user
        return Double.parseDouble ( scanner.next ( ) ) ;
    }
}