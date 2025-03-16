
import sys

def main ( ):
  # Declaring class variables
  N = int ( sys.stdin.readline ( ) )
  MOD = 1000000007
  TOKENS = [ "A" , "C" , "G" , "T" ]
  memo = [ { } for i in range ( N + 1 ) ]

  # Constructor
  def calc ( ):
    return dfs ( 0 , "TTT" )

  # Checking if the last 4 nucleotides form an invalid sequence
  def isOK ( last4 ):
    if "AGC" in last4:
      return False

    for i in range ( 3 ):
      vals = list ( last4 )
      vals [ i ] = last4 [ i + 1 ]
      vals [ i + 1 ] = last4 [ i ]
      s = "".join ( vals )

      if "AGC" in s:
        return False

    return True

  # Recursive function to calculate the result
  def dfs ( current , last3 ):
    if last3 in memo [ current ]:
      return memo [ current ] [ last3 ]

    if current == N:
      return 1

    result = 0

    for c in TOKENS:
      if isOK ( last3 + c ):
        result = ( result + dfs ( current + 1 , last3 [ 1 : ] + c ) ) % MOD

    memo [ current ] [ last3 ] = result
    return result

  print ( calc ( ) )

if __name__ == "__main__":
  main ( )

