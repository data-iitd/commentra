import java.util.* ; // Importing the Java Util library for Scanner class

public class Main { // Defining the Main class
    public static void main ( String [ ] args ) throws Exception { // Defining the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the console
        String str = sc.next ( ) ; // Reading the first line of input as a String
        char [ ] c = str.toCharArray ( ) ; // Converting the String to a character array
        long k = sc.nextLong ( ) ; // Reading the second line of input as a long integer
        int n = str.length ( ) ; // Finding the length of the String

        for ( int i = 0 ; i < k ; i ++ ) { // Starting a for loop to iterate through the character array up to the given limit 'k'
            if ( c [ i ] == '1' ) { // Checking if the current character is '1'
                if ( i == k - 1 ) { // Checking if the current index is the last index of the array
                    System.out.println ( 1 ) ; // If yes, print '1' and exit the method
                    return ;
                }
            } else {
                System.out.println ( c [ i ] ) ; // If the current character is not '1', print it to the console
                return ; // Exit the method as soon as a non-'1' character is found
            }
        }
    }
}
