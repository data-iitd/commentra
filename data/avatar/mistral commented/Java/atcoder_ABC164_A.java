import java.util.* ;  // Importing the Java utility package for Scanner class

public class Main {  // Main class definition
    public static void main ( String [ ] args ) throws Exception {  // Main method definition
        Scanner scan = new Scanner ( System.in ) ;  // Creating a new Scanner object to read input from the console
        ArrayList < String > scList = new ArrayList < > ( ) ;  // Creating an empty ArrayList to store the input lines

        // The following for loop reads input lines from the console and stores them in the ArrayList
        for ( int i = 0 ; i >= 0 ; i ++ ) {
            try {
                scList.add ( scan.nextLine ( ) ) ;  // Reading the next line from the console and adding it to the ArrayList
            } catch ( Exception e ) {
                break ;  // Exiting the loop if an exception occurs during input reading
            }
        }

        // The following line extracts the first line of the input (which contains the number of sheep and wolves)
        String [ ] numlist = scList.get ( 0 ).split ( " " ) ;

        // The following two lines parse the first two elements of the numlist array as integers representing the number of sheep and wolves
        int Sheep = Integer.parseInt ( numlist [ 0 ] ) ;
        int Wolve = Integer.parseInt ( numlist [ 1 ] ) ;

        // The following if statement checks if the number of wolves is greater than or equal to the number of sheep.
        // If so, it prints the message "unsafe" to the console. Otherwise, it prints the message "safe".
        if ( Wolve >= Sheep ) {
            System.out.println ( "unsafe" ) ;  // Printing the message "unsafe" to the console
        } else {
            System.out.println ( "safe" ) ;  // Printing the message "safe" to the console
        }
    }
}
