
import java.util.* ;  // Importing the utilities package for collections and input/output
import java.io.* ;

public class Main {
  // Declaring class variables
  int N ;
  long MOD = 1000000007L ;
  String [ ] TOKENS = { "A" , "C" , "G" , "T" } ;
  Map < String , Long > [ ] memo ;

  // Constructor
  Main ( ) {
    Scanner in = new Scanner ( System.in ) ;  // Creating a Scanner object to read input
    N = in.nextInt ( ) ;  // Reading the number of test cases
    in.close ( ) ;  // Closing the scanner after reading the input

    this.memo = new Map [ N + 1 ] ;  // Initializing a 2D map to store the results of subproblems

    for ( int i = 0 ; i < this.memo.length ; ++ i ) {  // Initializing each sub-array with a new HashMap
      this.memo [ i ] = new HashMap < String , Long > ( ) ;
    }
  }

  long calc ( ) {
    return dfs ( 0 , "TTT" ) ;  // Calling the recursive function to calculate the result
  }

  // Checking if the last 4 nucleotides form an invalid sequence
  boolean isOK ( String last4 ) {
    if ( last4.contains ( "AGC" ) ) {  // If the sequence contains "AGC", it's invalid
      return false ;
    }

    for ( int i = 0 ; i < 3 ; ++ i ) {  // Checking all possible pairs of adjacent nucleotides
      char [ ] vals = last4.toCharArray ( ) ;
      vals [ i ] = last4.charAt ( i + 1 ) ;
      vals [ i + 1 ] = last4.charAt ( i ) ;
      String s = new String ( vals ) ;  // Creating a new String from the pair

      if ( s.contains ( "AGC" ) ) {  // If the pair contains "AGC", it's invalid
        return false ;
      }
    }

    return true ;  // If no invalid sequence is found, the last 4 nucleotides are valid
  }

  long dfs ( int current , String last3 ) {
    if ( this.memo [ current ].containsKey ( last3 ) ) {  // If the result for the current sub-sequence and last 3 nucleotides is already calculated
      return ( Long ) ( this.memo [ current ].get ( last3 ) ) ;
    }

    if ( current == N ) {  // If we reach the end of the sequence, the result is 1
      return 1 ;
    }

    long result = 0 ;  // Initializing the result to 0

    for ( String c : TOKENS ) {  // Iterating through all possible next nucleotides
      if ( isOK ( last3 + c ) ) {  // If the next nucleotide and the current sequence form a valid sequence
        result = ( result + dfs ( current + 1 , last3.substring ( 1 , last3.length ( ) ) + c ) ) % MOD ;  // Recursively calculating the result for the next sub-sequence
      }
    }

    memo [ current ].put ( last3 , result ) ;  // Storing the result for the current sub-sequence and last 3 nucleotides
    return result ;  // Returning the result
  }

  public static void main ( String [ ] args ) {
    Main ins = new Main ( ) ;  // Creating an instance of the Main class
    System.out.println ( ins.calc ( ) ) ;  // Printing the result
  }
}

