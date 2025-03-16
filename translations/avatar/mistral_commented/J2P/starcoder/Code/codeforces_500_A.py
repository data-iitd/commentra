
import sys ; // Importing the utility module for input and output operations

def dfs ( currpos, arr, target ) : // Defining the recursive depth-first search function
    if ( currpos ==target ) : // Base case: if the current position is the target position, return true
        return True ;
    if ( currpos==len(arr)+1 ) : // Base case: if the current position is out of the array bounds, return false
        return False ;
    teleport = dfs ( currpos+arr[currpos-1], arr, target ) ; // Recursive call: try to teleport to the previous position
    if ( teleport ) : // If teleportation was successful, return true
        return True ;
    return False ; // If teleportation was not successful, return false

def main ( ) : // Defining the main function
    n = int ( sys.stdin.readline ( ) ) ; // Reading the number of positions in the array from the standard input
    goal = int ( sys.stdin.readline ( ) ) ; // Reading the target position from the standard input
    arr = [ ] ; // Creating an array to store the positions of the teleportals
    for i in range ( n-1 ) : // Reading the positions of the teleportals from the standard input and storing them in the array
        arr.append ( int ( sys.stdin.readline ( ) ) ) ;
    isFound = dfs ( 1, arr, goal ) ; // Calling the depth-first search function with the initial position and the target position
    if ( isFound ) : // If the target position was found, print "YES" to the standard output
        print ( "YES" ) ;
    else : // If the target position was not found, print "NO" to the standard output
        print ( "NO" ) ;

main ( ) ; // Calling the main function

