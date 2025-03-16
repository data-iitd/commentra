

import sys

class Main:
  # Declaring class variables
  N = 0
  MOD = 1000000007
  TOKENS = [ "A", "C", "G", "T" ]
  memo = [ { } for _ in range ( 100001 ) ]

  # Constructor
  def __init__ ( self ) :
    self.N = int ( input ( ) )

  def calc ( self ) :
    return self.dfs ( 0, "TTT" )

  # Checking if the last 4 nucleotides form an invalid sequence
  def isOK ( self, last4 ) :
    if ( "AGC" in last4 ) :
      return False

    for i in range ( 3 ) :
      vals = list ( last4 )
      vals [ i ], vals [ i + 1 ] = vals [ i + 1 ], vals [ i ]
      s = "".join ( vals )

      if ( "AGC" in s ) :
        return False

    return True

  def dfs ( self, current, last3 ) :
    if ( last3 in self.memo [ current ] ) :
      return self.memo [ current ] [ last3 ]

    if ( current == self.N ) :
      return 1

    result = 0

    for c in self.TOKENS :
      if ( self.isOK ( last3 + c ) ) :
        result = ( result + self.dfs ( current + 1, last3 [ 1 : ] + c ) ) % self.MOD

    self.memo [ current ] [ last3 ] = result
    return result

  def main ( self ) :
    ins = Main ( )
    print ( ins.calc ( ) )

if __name__ == "__main__" :
  ins = Main ( )
  ins.main ( )

