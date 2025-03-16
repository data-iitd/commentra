
import java.io.* ;
import java.util.* ;

public class Main {

 // Initialize constants
 public static final int BUFFER\_SIZE = 512000 ;

 // Initialize scanner and print writer
 private static Scanner sc = new Scanner ( new BufferedReader ( new InputStreamReader ( System.in ) , BUFFER\_SIZE ) ) ;
 private static PrintWriter out = new PrintWriter ( new BufferedOutputStream ( System.out , BUFFER\_SIZE ) ) ;

 // Main method
 public static void main ( String\[\] args ) throws Exception {
 init() ; // Initialize input and output streams
 solve() ; // Solve the problem
 closeIO() ; // Close input and output streams
 }

 // Initialize input and output streams
 private static void init ( ) {
 in.init( System.in ) ; // Initialize input stream
 }

 // Close input and output streams
 private static void closeIO ( ) {
 in.close() ; // Close input stream
 out.close() ; // Close output stream
 }

 // Solve the problem
 public static void solve ( ) {
 long position = sc.nextLong() ; // Read the position from input
 solveHelper( position ) ; // Solve the problem using helper method
 }

 // Helper method to solve the problem
 private static void solveHelper ( long position ) {
 long nrstSeqStartIndx = 1 ; // Initialize index for the start of the next sequence

 // Binary search for the start index of the sequence containing the position
 while ( getValueAtIndex( nrstSeqStartIndx \* 2 ) < position ) {
 nrstSeqStartIndx \*= 2 ; // Multiply index by 2
 }

 // Linear search for the end index of the sequence containing the position
 while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ) {
 nrstSeqStartIndx++ ; // Increment index
 }

 // Print the answer
 long startIndex = getValueAtIndex( nrstSeqStartIndx ) ; // Get the start index of the sequence
 out.println( ( position - startIndex ) + 1 ) ; // Print the length of the sequence
 }

 // Get the value at a given index
 public static long getValueAtIndex ( long index ) {
 return 1 + ( ( index - 1 ) \* index / 2 ) ; // Calculate the value at the given index
 }

 // Inner class for input handling
 public static class in {
 static BufferedReader reader ;
 static StringTokenizer tokenizer ;

 // Initialize input stream
 static void init ( InputStream input ) {
 reader = new BufferedReader( new InputStreamReader( input ) , BUFFER\_SIZE ) ;
 tokenizer = new StringTokenizer( "" ) ;
 }

 // Read a string token from input
 static String next ( ) throws IOException {
 while ( ! tokenizer.hasMoreTokens( ) ) {
 tokenizer = new StringTokenizer( reader.readLine( ) ) ;
 }
 return tokenizer.nextToken( ) ;
 }

 // Read an integer from input
 static int nextInt ( ) throws IOException {
 return Integer.parseInt( next( ) ) ;
 }

 // Read a double from input
 static double nextDouble ( ) throws IOException {
 return Double.parseDouble( next( ) ) ;
 }

 // Read a long from input
 static long nextLong ( ) throws IOException {
 return Long.parseLong( next( ) ) ;
 }
 }
}

These comments should provide a good understanding of the code for someone who is not familiar with it.