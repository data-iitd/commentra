
import java.util.ArrayList ;  // Importing the ArrayList and Scanner classes
import java.util.Scanner ;

def main():
    sc = Scanner ( System.in ) ;  # Creating a new Scanner object named sc to read input from the standard input

    n = sc.nextInt ( ) ;                     # Reading the first integer n from the standard input
    m = sc.nextInt ( ) ;                     # Reading the second integer m from the standard input
    q = sc.nextInt ( ) ;                     # Reading the third integer q from the standard input

    a = [ ]                                 # Allocating memory for the array a of size q and initializing it to null
    b = [ ]                                 # Allocating memory for the array b of size q and initializing it to null
    c = [ ]                                 # Allocating memory for the array c of size q and initializing it to null
    d = [ ]                                 # Allocating memory for the array d of size q and initializing it to null

    for i in range ( q ):                  # A for loop that reads q integers from the standard input and stores them in arrays a, b, c, and d
        a.append ( sc.nextInt ( ) - 1 )     # Reading the integer a[i] from the standard input and storing it in the array a after subtracting 1 from it
        b.append ( sc.nextInt ( ) - 1 )     # Reading the integer b[i] from the standard input and storing it in the array b after subtracting 1 from it
        c.append ( sc.nextInt ( ) )         # Reading the integer c[i] from the standard input and storing it in the array c
        d.append ( sc.nextInt ( ) )         # Reading the integer d[i] from the standard input and storing it in the array d

    dfs ( [ ] )                            # Calling the recursive function dfs with an empty ArrayList as an argument

    print ( ans )                          # Printing the value of the long variable ans to the standard output

def dfs ( list ):                         # A recursive function named dfs that takes an ArrayList named list as an argument
    if ( len ( list ) == n ):              # A conditional statement that checks if the size of the ArrayList list is equal to the integer n
        score = 0                          # Declaring and initializing a long variable score to zero

        for i in range ( q ):              # A for loop that calculates the score based on the condition that (list.get(b[i]) - list.get(a[i]) == c[i])
            score += ( list [ b [ i ] ] - list [ a [ i ] ] == c [ i ] ) * d [ i ]

        global ans                          # Declaring the global variable ans
        ans = max ( ans, score )           # Updating the value of the long variable ans with the maximum value of ans and the score calculated in the for loop
        return                              # Returning from the function after updating the value of ans

    if ( len ( list )!= 0 ):              # A conditional statement that checks if the ArrayList list is not empty
        for num in range ( list [ - 1 ] + 1, m + 1 ): # A for loop that adds the integer num to the ArrayList list and recursively calls the function dfs
            list.append ( num )
            dfs ( list )
            list.remove ( - 1 )
    else:                                 # If the ArrayList list is empty
        for num in range ( 1, m + 1 ):     # A for loop that adds the integer num to the ArrayList list and recursively calls the function dfs
            list.append ( num )
            dfs ( list )
            list.remove ( - 1 )

if __name__ == '__main__':
    main ( )

