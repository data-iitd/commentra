
import sys

def dfs ( currpos , arr , target ):
    if currpos == target:
        return True
    if currpos == len(arr)+1:
        return False
    teleport = dfs ( currpos+arr[currpos-1] , arr , target )
    if teleport:
        return True
    return False

n = int ( sys.stdin.readline ( ) )
goal = int ( sys.stdin.readline ( ) )
arr = [ int ( sys.stdin.readline ( ) ) for i in range ( n-1 ) ]
isFound = dfs ( 1 , arr , goal )
if isFound:
    print ( "YES" )
else:
    print ( "NO" )

