
#include <bits/stdc++.h>

using namespace std ;

// Initialize constants
const int BUFFER\_SIZE = 512000 ;

// Initialize scanner and print writer
static in in ;
static out out ;

// Main method
int main ( int argc, char\*\* argv ) {
init() ; // Initialize input and output streams
solve() ; // Solve the problem
closeIO() ; // Close input and output streams
}

// Initialize input and output streams
void init ( ) {
in.init( ) ; // Initialize input stream
}

// Close input and output streams
void closeIO ( ) {
in.close() ; // Close input stream
out.close() ; // Close output stream
}

// Solve the problem
void solve ( ) {
long position = in.nextLong() ; // Read the position from input
solveHelper( position ) ; // Solve the problem using helper method
}

// Helper method to solve the problem
void solveHelper ( long position ) {
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
long getValueAtIndex ( long index ) {
return 1 + ( ( index - 1 ) \* index / 2 ) ; // Calculate the value at the given index
}

// Inner class for input handling
class in {
public:
// Initialize input stream
void init ( ) {
reader = new BufferedReader( new InputStreamReader( stdin ), BUFFER\_SIZE ) ;
tokenizer = new StringTokenizer( "" ) ;
}

// Read a string token from input
string next ( ) throws IOException {
while (! tokenizer.hasMoreTokens( ) ) {
tokenizer = new StringTokenizer( reader.readLine( ) ) ;
}
return tokenizer.nextToken( ) ;
}

// Read an integer from input
int nextInt ( ) throws IOException {
return Integer.parseInt( next( ) ) ;
}

// Read a double from input
double nextDouble ( ) throws IOException {
return Double.parseDouble( next( ) ) ;
}

// Read a long from input
long nextLong ( ) throws IOException {
return Long.parseLong( next( ) ) ;
}

// Close input stream
void close ( ) throws IOException {
reader.close( ) ;
}

private:
BufferedReader reader ;
StringTokenizer tokenizer ;
} ;

// Inner class for output handling
class out {
public:
// Initialize output stream
void init ( ) {
writer = new PrintWriter( new BufferedOutputStream( stdout ), BUFFER\_SIZE ) ;
}

// Print a string to output
void print ( String data ) {
writer.print( data ) ;
}

// Print a character to output
void print ( char data ) {
writer.print( data ) ;
}

// Print an integer to output
void print ( int data ) {
writer.print( data ) ;
}

// Print a long to output
void print ( long data ) {
writer.print( data ) ;
}

// Print a double to output
void print ( double data ) {
writer.print( data ) ;
}

// Print a new line to output
void println ( ) {
writer.println( ) ;
}

// Print a string to output
void println ( String data ) {
writer.println( data ) ;
}

// Print a character to output
void println ( char data ) {
writer.println( data ) ;
}

// Print an integer to output
void println ( int data ) {
writer.println( data ) ;
}

// Print a long to output
void println ( long data ) {
writer.println( data ) ;
}

// Print a double to output
void println ( double data ) {
writer.println( data ) ;
}

// Close output stream
void close ( ) {
writer.close( ) ;
}

private:
PrintWriter writer ;
} ;

