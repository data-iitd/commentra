
import sys

def main ( ):
  n = int ( sys.stdin.readline ( ) )
  k = int ( sys.stdin.readline ( ) )
  bb = [ int ( sys.stdin.readline ( ) ) for i in range ( n ) ]
  aa = [ 0 for i in range ( n ) ]
  m = 0

  for a in range ( n - 1 , -1 , -1 ):
    j = 0
    while bb [ a ] > 0:
      if aa [ j ] >= a + k:
        bb [ a ] -= 1
      j += 1

    for j_ in range ( m , j - 1 , -1 ):
      aa [ j_ ] = aa [ j_ - 1 ]

    aa [ j ] = a

  for i in range ( n ):
    print ( aa [ i ] + 1 , end = " " )

  print ( )

if __name__ == "__main__":
  main ( )

