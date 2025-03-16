
import java.io.* ; // Importing required classes for input and output
import java.util.* ; // Importing required classes for Scanner and HashMap

public class Main {

 // Main method is the entry point of the program
 public static void main ( String [ ] args ) {
 Scanner in = new Scanner ( System.in ) ; // Creating a Scanner object for reading input
 PrintWriter pw = new PrintWriter ( System.out ) ; // Creating a PrintWriter object for writing output
 int n = in.nextInt ( ) ; // Reading the number of elements in the array from the input
 int ara [ ] = new int [ n ] ; // Creating an integer array of size n
 Map < Integer , Integer > map = new HashMap < > ( ) ; // Creating an empty HashMap to store the frequency of each integer

 // Reading elements of the array and updating the frequency in the HashMap
 for ( int i = 0 ; i < n ; i ++ ) {
 int v = in.nextInt ( ) ; // Reading an integer from the input
 ara [ i ] = v ; // Storing the integer in the array
 if ( ! map.containsKey ( v ) ) { // Checking if the integer is already present in the HashMap
 map.put ( v , 1 ) ; // If not, add it with a frequency of 1
 } else {
 map.put ( v , map.get ( v ) + 1 ) ; // If yes, increment its frequency by 1
 }
 }

 // Finding the maximum frequency in the HashMap
 int max = 0 ;
 for ( Integer i : map.values ( ) ) {
 max = Math.max ( max , i ) ; // Updating max with the maximum frequency found so far
 }

 // Finding the element(s) with the maximum frequency
 Map < Integer , Integer > mm = new HashMap < > ( ) ; // Creating an empty HashMap to store the elements and their frequencies
 for ( int i = 0 ; i < n ; i ++ ) {
 if ( ! mm.containsKey ( ara [ i ] ) ) { // Checking if the current element is already present in the HashMap
 mm.put ( ara [ i ] , 1 ) ; // If not, add it with a frequency of 1
 if ( mm.get ( ara [ i ] ) == max ) { // Checking if the frequency of the current element is equal to the maximum frequency
 pw.println ( ara [ i ] ) ; // If yes, print it and break out of the loop
 break ;
 }
 } else {
 mm.put ( ara [ i ] , mm.get ( ara [ i ] ) + 1 ) ; // If the current element is already present, increment its frequency by 1
 if ( mm.get ( ara [ i ] ) == max ) { // Checking if the frequency of the current element is equal to the maximum frequency
 pw.println ( ara [ i ] ) ; // If yes, print it and break out of the loop
 break ;
 }
 }
 }

 pw.close ( ) ; // Closing the PrintWriter object
 }

 // A helper method for printing debugging information
 static void debug ( Object...obj ) { System.err.println ( Arrays.deepToString ( obj ) ) ; }
}