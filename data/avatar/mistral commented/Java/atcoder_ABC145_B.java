
import java.util.* ; // Importing the utility class Scanner from the Java standard library
import java.math.* ; // Importing the BigDecimal class from the Java standard library (not used in this code)

public class Main { // Defining a public class named Main

    public static void cout ( String str ) { // Defining a static method named cout that takes a String argument and prints it to the console
        System.out.println ( str ) ; // Printing the given String to the console
    } ;

    public static void main ( String args [ ] ) { // Defining the main method that is the entry point of the program
        Scanner cin = new Scanner ( System.in ) ; // Creating a new Scanner object named cin to read input from the console

        String a = "" , b = "" , str ; // Declaring three String variables: a, b, and str
        int n ; // Declaring an integer variable named n

        n = cin.nextInt ( ) ; // Reading an integer value from the console and assigning it to the variable n
        cin.nextLine ( ) ; // Consuming the newline character left after reading an integer value

        str = cin.nextLine ( ) ; // Reading a line of text from the console and assigning it to the variable str

        for ( int i = 0 ; i < n / 2 ; i ++ ) { // Starting a for loop that iterates n/2 times
            a = a + str.charAt ( i ) ; // Appending the character at the current index of str to the variable a
        }

        if ( str.equals ( a + a ) ) { // Starting an if statement to check if the given string is a palindrome
            cout ( "Yes" ) ; // Printing "Yes" to the console if the given string is a palindrome
        } else {
            cout ( "No" ) ; // Printing "No" to the console if the given string is not a palindrome
        }

        cin.close ( ) ; // Closing the Scanner object to release the system resources
    }
}