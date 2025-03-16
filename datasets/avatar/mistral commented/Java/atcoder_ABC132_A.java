
import java.util.HashMap ; // Importing HashMap class for storing character and their frequency
import java.util.Map.Entry ; // Importing Entry class for iterating through HashMap
import java.util.Scanner ; // Importing Scanner class for taking input from user

public class Main {

    public static void main ( String [ ] args ) {
        Scanner in = new Scanner ( System.in ) ; // Creating a Scanner object for taking input from user

        String s = in.next ( ) ; // Reading a string input from user
        char [ ] targ = s.toCharArray ( ) ; // Converting the string input to character array

        HashMap < Character , Integer > map = new HashMap < > ( ) ; // Creating an empty HashMap to store character and their frequency

        for ( int i = 0 ; i < targ.length ; i ++ ) { // Iterating through each character in the character array
            char currentChar = targ [ i ] ; // Assigning the current character to a variable

            if ( ! map.containsKey ( currentChar ) ) { // Checking if the current character is already present in the HashMap
                map.put ( currentChar , 1 ) ; // If not present, adding the current character with frequency 1 to the HashMap
            } else {
                map.put ( currentChar , map.get ( currentChar ) + 1 ) ; // If present, incrementing the frequency of the current character in the HashMap
            }
        }

        boolean ok = true ; // Initializing a boolean variable to check if all characters have frequency 2 or not

        for ( Entry < Character , Integer > c : map.entrySet ( ) ) { // Iterating through each entry in the HashMap
            char key = c.getKey ( ) ; // Assigning the character to a variable
            int value = c.getValue ( ) ; // Assigning the frequency to a variable

            if ( value != 2 ) { // Checking if the frequency of the current character is not 2
                ok = false ; // Setting the boolean variable to false if any character has frequency other than 2
                break ; // Exiting the loop if any character has frequency other than 2
            }
        }

        if ( ok && map.size ( ) == 2 ) { // Checking if all characters have frequency 2 and the size of the HashMap is 2
            System.out.println ( "Yes" ) ; // Printing "Yes" if both conditions are true
        } else {
            System.out.println ( "No" ) ; // Printing "No" if any character has frequency other than 2 or the size of the HashMap is not 2
        }

        in.close ( ) ; // Closing the Scanner object
    }
}