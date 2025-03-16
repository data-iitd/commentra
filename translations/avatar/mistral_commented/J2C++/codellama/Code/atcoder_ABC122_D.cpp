
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std ;

class Main {
  // Declaring class variables
  int N ;
  long MOD = 1000000007L ;
  string [ ] TOKENS = { "A" , "C" , "G" , "T" } ;
  map < string , long > [ ] memo ;

  // Constructor
  Main ( ) {
    cin >> N ;  // Reading the number of test cases

    this->memo = new map < string , long > [ N + 1 ] ;  // Initializing a 2D map to store the results of subproblems

    for ( int i = 0 ; i < this->memo.size ( ) ; ++ i ) {  // Initializing each sub-array with a new HashMap
      this->memo [ i ] = map < string , long > ( ) ;
    }
  }

  long calc ( ) {
    return dfs ( 0 , "TTT" ) ;  // Calling the recursive function to calculate the result
  }

  // Checking if the last 4 nucleotides form an invalid sequence
  bool isOK ( string last4 ) {
    if ( last4.find ( "AGC" ) != string::npos ) {  // If the sequence contains "AGC", it's invalid
      return false ;
    }

    for ( int i = 0 ; i < 3 ; ++ i ) {  // Checking all possible pairs of adjacent nucleotides
      char [ ] vals = last4.c_str ( ) ;
      vals [ i ] = last4.at ( i + 1 ) ;
      vals [ i + 1 ] = last4.at ( i ) ;
      string s = string ( vals ) ;  // Creating a new String from the pair

      if ( s.find ( "AGC" ) != string::npos ) {  // If the pair contains "AGC", it's invalid
        return false ;
      }
    }

    return true ;  // If no invalid sequence is found, the last 4 nucleotides are valid
  }

  long dfs ( int current , string last3 ) {
    if ( this->memo [ current ].find ( last3 ) != this->memo [ current ].end ( ) ) {  // If the result for the current sub-sequence and last 3 nucleotides is already calculated
      return ( long ) ( this->memo [ current ].find ( last3 )->second ) ;
    }

    if ( current == N ) {  // If we reach the end of the sequence, the result is 1
      return 1 ;
    }

    long result = 0 ;  // Initializing the result to 0

    for ( string c : TOKENS ) {  // Iterating through all possible next nucleotides
      if ( isOK ( last3 + c ) ) {  // If the next nucleotide and the current sequence form a valid sequence
        result = ( result + dfs ( current + 1 , last3.substr ( 1 , last3.length ( ) ) + c ) ) % MOD ;  // Recursively calculating the result for the next sub-sequence
      }
    }

    memo [ current ][ last3 ] = result ;  // Storing the result for the current sub-sequence and last 3 nucleotides
    return result ;  // Returning the result
  }

  public:
    static void main ( string [ ] args ) {
      Main ins = new Main ( ) ;  // Creating an instance of the Main class
      cout << ins.calc ( ) << endl ;  // Printing the result
    }
} ;

