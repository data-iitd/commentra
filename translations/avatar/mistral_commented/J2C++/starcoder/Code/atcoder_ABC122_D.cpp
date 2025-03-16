
#include <bits/stdc++.h>
using namespace std;

class Main {
public:
  int N ;
  long long MOD = 1000000007 ;
  string TOKENS [ ] = { "A", "C", "G", "T" } ;
  map < string, long long > * memo ;

  Main ( ) {
    cin >> N ;
    this->memo = new map < string, long long > [ N + 1 ] ;

    for ( int i = 0 ; i < this->memo.length ; ++ i ) {
      this->memo [ i ] = map < string, long long > ( ) ;
    }
  }

  long long calc ( ) {
    return dfs ( 0, "TTT" ) ;
  }

  bool isOK ( string last4 ) {
    if ( last4.find ( "AGC" )!= string::npos ) {
      return false ;
    }

    for ( int i = 0 ; i < 3 ; ++ i ) {
      char [ ] vals = last4.c_str ( ) ;
      vals [ i ] = last4 [ i + 1 ] ;
      vals [ i + 1 ] = last4 [ i ] ;
      string s = string ( vals ) ;

      if ( s.find ( "AGC" )!= string::npos ) {
        return false ;
      }
    }

    return true ;
  }

  long long dfs ( int current, string last3 ) {
    if ( this->memo [ current ].find ( last3 )!= this->memo [ current ].end ( ) ) {
      return this->memo [ current ] [ last3 ] ;
    }

    if ( current == N ) {
      return 1 ;
    }

    long long result = 0 ;

    for ( string c : TOKENS ) {
      if ( isOK ( last3 + c ) ) {
        result = ( result + dfs ( current + 1, last3.substr ( 1, last3.length ( ) ) + c ) ) % MOD ;
      }
    }

    this->memo [ current ] [ last3 ] = result ;
    return result ;
  }
};

int main ( ) {
  Main ins = Main ( ) ;
  cout << ins.calc ( ) << endl ;
}

