
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws Exception { 
        Scanner scan = new Scanner ( System.in ) ; // Initialize Scanner to read input
        ArrayList < String > scList = new ArrayList < > ( ) ; // Create an ArrayList to store input lines
        
        // Continuously read input lines from the user until an exception occurs
        for ( int i = 0 ; i >= 0 ; i ++ ) { 
            try { 
                scList.add ( scan.nextLine ( ) ) ; // Add the input line to the ArrayList
            } catch ( Exception e ) { 
                break ; // Exit the loop if an exception occurs
            } 
        } 
        
        // Get the first line of input and split it into an array of strings
        String [ ] numlist = scList.get ( 0 ).split ( " " ) ; 
        
        // Parse the first element to get the number of sheep
        int Sheep = Integer.parseInt ( numlist [ 0 ] ) ; 
        
        // Parse the second element to get the number of wolves
        int Wolve = Integer.parseInt ( numlist [ 1 ] ) ; 
        
        // Check if the number of wolves is greater than or equal to the number of sheep
        if ( Wolve >= Sheep ) { 
            System.out.println ( "unsafe" ) ; // Print "unsafe" if the condition is true
        } else { 
            System.out.println ( "safe" ) ; // Print "safe" otherwise
        } 
    } 
}

