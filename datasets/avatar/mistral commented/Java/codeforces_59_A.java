import java.util.Scanner ;  // Importing the Scanner class for reading input from the console

public class Main {
    public static void main ( String [ ] args ) {  // Main method, entry point of the program
        Scanner in = new Scanner ( System.in ) ;  // Creating a new Scanner object to read input from the console
        String word = in.next ( ) ;  // Reading the first word as input from the user

        int uppercase = 0 ;  // Initializing a counter for uppercase characters
        int lowercase = 0 ;  // Initializing a counter for lowercase characters

        for ( int i = 0 ; i < word.length ( ) ; i ++ ) {  // Iterating through each character in the word
            char ch = word.charAt ( i ) ;  // Assigning the character at the current index to a char variable

            if ( Character.isUpperCase ( ch ) ) {  // Checking if the character is uppercase
                uppercase ++ ;  // Incrementing the uppercase counter
            } else {
                lowercase ++ ;  // Incrementing the lowercase counter
            }
        }

        if ( uppercase > lowercase ) {  // Checking if there are more uppercase characters than lowercase characters
            System.out.println ( word.toUpperCase ( ) ) ;  // Printing the word in uppercase if condition is true
        } else if ( lowercase > uppercase ) {  // Checking if there are more lowercase characters than uppercase characters
            System.out.println ( word.toLowerCase ( ) ) ;  // Printing the word in lowercase if condition is true
        } else {  // If both uppercase and lowercase characters are equal
            System.out.println ( word.toLowerCase ( ) ) ;  // Printing the word in lowercase if both conditions are false
        }
    }
}
